/*****************************************************
 * copyright (C) 2007 by Rob Merrell
 * rob@migrob.com
 *
 * ***************************************************/

#include "ruby.h"
#include "rinotify.h"

#include <sys/inotify.h>
#include <unistd.h>

// extension entry point
void Init_rinotify() {
	rb_cRInotify = rb_define_class("RInotify", rb_cObject);	
	
	// initialize all of the events
	rinotify_declare_events(rb_cRInotify);		

	// RInotify.new
	rb_define_alloc_func(rb_cRInotify, rb_rinotify_new);

	// RInotify.close
	rb_define_method(rb_cRInotify, "close", rb_rinotify_close, 0);

	// RInotify.add_watch
	rb_define_method(rb_cRInotify, "add_watch", rb_rinotify_add_watch, 2);

	// RInotify.rm_watch
	rb_define_method(rb_cRInotify, "rm_watch", rb_rinotify_rm_watch, 1);
}


static VALUE rb_rinotify_new(VALUE klass) {
	// initialize inotify
	int *inotify = NULL;
	inotify = malloc(sizeof(int));
	*inotify = inotify_init();

	if (*inotify < 0)
		rb_sys_fail("inotify_init");	

	// make sure free is called because we malloc'd above
	// TODO instead of sending to free create a function to close inotfy
	// if it is still open, so we can prevent memory leaks
	return Data_Wrap_Struct(klass, NULL, free, inotify);
}


static VALUE rb_rinotify_close(VALUE self) {
	int *inotify = NULL, close_return;
	Data_Get_Struct(self, int, inotify);

	// close and clean up inotify
	close_return = close(*inotify);
	if (close_return)
		rb_sys_fail("close");	

	return Qnil;
}


static VALUE rb_rinotify_add_watch(VALUE self, VALUE filename, VALUE event_masks) {
	int *inotify = NULL, watch_desc;
	Data_Get_Struct(self, int, inotify);

	// TODO: does inotify make sure the file exists?
	// add the watch
	watch_desc = inotify_add_watch(*inotify, RSTRING(filename)->ptr, NUM2INT(event_masks));	
	if (watch_desc < 0)
		rb_sys_fail("add_watch");
	
	return INT2NUM(watch_desc);
}


static VALUE rb_rinotify_rm_watch(VALUE self, VALUE watch_desc) {
	int *inotify = NULL, rm_return;
	Data_Get_Struct(self, int, inotify);

	// remove the watch
	rm_return = inotify_rm_watch(*inotify, NUM2INT(watch_desc));
	if (rm_return < 0)
		rb_sys_fail("rm_watch");

	return INT2NUM(rm_return);
}


static void rinotify_declare_events(VALUE klass) {
	// watch events
	rb_const_set(klass, rb_intern("IN_ACCESS"), INT2NUM(IN_ACCESS));
	rb_const_set(klass, rb_intern("IN_MODIFY"), INT2NUM(IN_MODIFY));
	rb_const_set(klass, rb_intern("IN_ATTRIB"), INT2NUM(IN_ATTRIB));
	rb_const_set(klass, rb_intern("IN_CLOSE_WRITE"), INT2NUM(IN_CLOSE_WRITE));
	rb_const_set(klass, rb_intern("IN_CLOSE_NOWRITE"), INT2NUM(IN_CLOSE_NOWRITE));
	rb_const_set(klass, rb_intern("IN_OPEN"), INT2NUM(IN_OPEN));
	rb_const_set(klass, rb_intern("IN_MOVED_FROM"), INT2NUM(IN_MOVED_FROM));
	rb_const_set(klass, rb_intern("IN_MOVED_TO"), INT2NUM(IN_MOVED_TO));
	rb_const_set(klass, rb_intern("IN_CREATE"), INT2NUM(IN_CREATE));
	rb_const_set(klass, rb_intern("IN_DELETE"), INT2NUM(IN_DELETE));
	rb_const_set(klass, rb_intern("IN_DELETE_SELF"), INT2NUM(IN_DELETE_SELF));

	// sent by any watch
	rb_const_set(klass, rb_intern("IN_UNMOUNT"), INT2NUM(IN_UNMOUNT));
	rb_const_set(klass, rb_intern("IN_Q_OVERFLOW"), INT2NUM(IN_Q_OVERFLOW));
	rb_const_set(klass, rb_intern("IN_IGNORED"), INT2NUM(IN_IGNORED));

	// helper events
	rb_const_set(klass, rb_intern("IN_CLOSE"), INT2NUM(IN_CLOSE));
	rb_const_set(klass, rb_intern("IN_MOVE"), INT2NUM(IN_MOVE));

	// special flags
	rb_const_set(klass, rb_intern("IN_ISDIR"), INT2NUM(IN_ISDIR));
	rb_const_set(klass, rb_intern("IN_ONESHOT"), INT2NUM(IN_ONESHOT));	

	// TODO IN_ALL_EVENTS
}

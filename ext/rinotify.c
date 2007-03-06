#include "ruby.h"
#include "rinotify.h"

#include <sys/inotify.h>
#include <unistd.h>

// extension entry point
void Init_rinotify() {
	rb_cRInotify = rb_define_class("RInotify", rb_cObject);	

	// "new" method
	rb_define_alloc_func (rb_cRInotify, rinotify_new);
}


static VALUE rinotify_new(VALUE klass) {
	// initialize inotify
	int *inotify = NULL;
	*inotify = inotify_init();

	if (*inotify < 0)
		rb_sys_fail("inotify_init");	

	// initialize all of the bit masks
	rinotify_declare_events(klass);		

	return Data_Wrap_Struct(klass, NULL, rinotify_free, inotify);
}


static void rinotify_free(VALUE self) {
	int *inotify = NULL, close_return;
	Data_Get_Struct(self, int, inotify);

	close_return = close(*inotify);
	if (close_return)
		rb_sys_fail("close");	
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
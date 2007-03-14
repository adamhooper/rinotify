#include "ruby.h"
#include "rubyio.h"
#include "rinotify_event.h"

#include <sys/inotify.h>

// class entry point
void Init_rinotify_event() {
	rb_cRInotifyEvent = rb_define_class("RInotifyEvent", rb_cObject);

	// RInotifyEvent.name
	rb_define_method(rb_cRInotifyEvent, "name", rb_rinotify_event_name, 0);
}


static VALUE rb_rinotify_event_new(struct inotify_event *event) {
	return Data_Wrap_Struct(rb_cRInotifyEvent, NULL, free, event);	
}


static VALUE rb_rinotify_event_name(VALUE self) {
	struct inotify_event *event;	
	Data_Get_Struct(self, struct intotify_event, event);

	return RSTRING(event->name)->ptr;
}



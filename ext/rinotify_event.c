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


VALUE rb_rinotify_event_new(struct inotify_event *event) {
	VALUE rinotify_event;

	rinotify_event = Data_Wrap_Struct(rb_cRInotifyEvent, NULL, free, event);
	rb_obj_call_init(rinotify_event, 0, NULL);

	return rinotify_event;
}


VALUE rb_rinotify_event_name(VALUE self) {
	struct inotify_event *event;	
	Data_Get_Struct(self, struct inotify_event, event);

	return INT2NUM(5);
}



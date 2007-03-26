#include "ruby.h"
#include "rinotify_event.h"

#include <sys/inotify.h>

VALUE rb_rinotify_event_new(struct inotify_event *event) {
	VALUE rinotify_event;

	rinotify_event = Data_Wrap_Struct(rb_cRInotifyEvent, NULL, free, event);
	rb_obj_call_init(rinotify_event, 0, NULL);

	return rinotify_event;
}


VALUE rb_rinotify_event_name(VALUE self) {
	VALUE name;
	struct inotify_event *event;	
	Data_Get_Struct(self, struct inotify_event, event);

	// if watching for events in a directory inotify will tell us the name
	if (event->len) {
		name = rb_str_new2(event->name);	
	} else {
	// if watching a single file we need to retrieve it from the initial watch
		name = rb_str_new2("no name yet");
	}

	return name;
}



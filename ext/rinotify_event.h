/*****************************************************
 * copyright (C) 2007 by Rob Merrell
 * rob@migrob.com
 *
 * ***************************************************/

#ifndef RINOTIFY_EVENT_H
#define RINOTIFY_EVENT_H

#include "ruby.h"
#include <sys/inotify.h>

// RInotifyEvent class
VALUE rb_cRInotifyEvent;

/* Ruby Prototypes */

/*
 *
 * call-seq:
 * 		RInotifyEvent.new => RInotifyEvent
 *
 * 	Returns a new RInotifyEvent object.  This method should only be called by RInotify.read_each_event
 *
 */
VALUE rb_rinotify_event_new(struct inotify_event*);


/*
 *
 * call-seq:
 * 		RInotifyEvent.name => event->name
 *
 * Returns the name of the event.
 *
 */
VALUE rb_rinotify_event_name(VALUE);


/*
 *
 * call-seq:
 * 		RInotifyEvent.watch_descriptor => event->wd
 *
 * Returns the watch descriptor that the event belongs to.
 *
 */
VALUE rb_rinotify_event_watch_descriptor(VALUE);


/*
 *
 * call-seq:
 * 		RInotifyEvent.check_mask => boolean
 *
 * Returns true or false if the current event contains the mask(s)
 *
 */
VALUE rb_rinotify_event_check_mask(VALUE, VALUE);

#endif

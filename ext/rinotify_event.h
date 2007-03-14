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
static VALUE rb_cRInotifyEvent;

/* Ruby Prototypes */

/*
 *
 * call-seq:
 * 		RInotifyEvent.new => RInotifyEvent
 *
 * 	Returns a new RInotifyEvent object.  This method should only be called by RInotify.read_each_event
 *
 */
static VALUE rb_rinotify_event_new(struct inotify_event*);


/*
 *
 * call-seq:
 * 		RInotifyEvent.name => event->name
 *
 * Returns the name of the event.
 *
 */
static VALUE rb_rinotify_event_name(VALUE);


#endif
/*****************************************************
 * copyright (C) 2007 by Rob Merrell
 * rob@migrob.com
 *
 * ***************************************************/

#ifndef RINOTIFY_H
#define RINOTIFY_H

#include "ruby.h"

// RInotify class
static VALUE rb_cRInotify;

/* Non Ruby-implimented Prototypes */

// declare the inotify events as constants
static void rinotify_declare_events(VALUE);



/* Ruby Prototypes */

/*
 *
 * call-seq:
 *		RInotify.new => RInotify
 *
 *	Returns a new RInotify object.
 *
 */
static VALUE rb_rinotify_new(VALUE);


/*
 *
 * call-seq:
 *		RInotify.close => nil
 *
 *	Cleans up and closes inotify.
 *
 */
static VALUE rb_rinotify_close(VALUE);


/*
 * call-seq:
 *		RInotify.add_watch(filename, event masks) => watch descriptor
 *
 */
static VALUE rb_rinotify_add_watch(VALUE, VALUE, VALUE);


/*
 * call-seq:
 *		RInotify.rm_watch(watch descriptor) => closed descriptor
 *
 */
static VALUE rb_rinotify_rm_watch(VALUE, VALUE);


/*
 * call-seq:
 * 		RInotify.wait_for_events(seconds to time out) => true or false 
 *
 * Waits for events to be received from inotify.
 * Returns true when there are events waiting in the queue
 * and false if not.
 *
 */
static VALUE rb_rinotify_wait_for_events(VALUE, VALUE);


/*
 * call-seq:
 *		RInotify.read_each_event => ... 
 *
 */
static VALUE rb_rinotify_read_each_event(VALUE);

#endif

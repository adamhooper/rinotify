/*****************************************************
 * copyright (C) 2007 by Rob Merrell
 * rob@migrob.com
 *
 * ***************************************************/

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
 *		RInotify.rm_watch(watch descriptor) => nil
 *
 */
static VALUE rb_rinotify_rm_watch(VALUE, VALUE);

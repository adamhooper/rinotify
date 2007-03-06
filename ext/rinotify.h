#include "ruby.h"

// RInotify class
static VALUE rb_cRInotify;

/* Non Ruby-implimented Prototypes */

// free up the object for Ruby's GC
static void rinotify_free(VALUE);

// declare the inotify events
static void rinotify_declare_events(VALUE);



/* Ruby Prototypes */

/*
 *
 * call-seq:
 *		RInotify.new => RInotify
 *
 *	Returns a new RInotify object.
 */
static VALUE rinotify_new(VALUE);

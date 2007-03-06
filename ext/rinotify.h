#include "ruby.h"

// RInotify class
static VALUE rb_cRInotify;

/* Non Ruby-implimented Prototypes */

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


/*
 *
 * call-seq:
 *		RInotify.close => nil
 *
 *	Cleans up and closes inotify.
 */
static VALUE rinotify_close(VALUE);

#######################################################
# copyright (C) 2007 by Rob Merrell
# rob@migrob.com
#
#
# This example shows the very basics of how to use RInotify with regular files.
# It is recomended that this example be used for to see the uses of different methods
# as you wait_for_events really does wait for events until one is received or it 
# times out.  Long story short, use threads, as is shown in another example.
# 
#######################################################

require 'rinotify'

# make sure we have a file name
if !ARGV[0]
	raise("Please pass in a file name")
end

# make sure that it is indeed a file
if !File.file?(ARGV[0])
	raise("Nice try, but no cigar.  I can't read this, because it isn't a regular file.")
end

# create the object and add a watch on the file
rinotify = RInotify.new
rinotify.add_watch(ARGV[0], RInotify::MODIFY | RInotify::DELETE_SELF)


# wait for events
has_events = false

# timeout after five seconds
has_events = rinotify.wait_for_events(5)	
if has_events

	# iterate through events
	rinotify.each_event {|revent|
		
		# check if the event we received was MODIFY or DELETE_SELF
		if revent.check_mask(RInotify::MODIFY)
			puts "file was modified"
		elsif revent.check_mask(RInotify::DELETE_SELF)
			puts "file was deleted"
		end
	}

else
	# no events were received in the number of seconds specified in wait_for_events above
	puts "Timed out"
end

# close and clean up
rinotify.close


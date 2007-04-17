#######################################################
# copyright (C) 2007 by Rob Merrell
# rob@migrob.com
#
#
# This example shows how to use RInotify using threads.  And should
# look very similar to watch_file.rb
# 
#######################################################

# require the file and rubygems if necessary
begin
	require 'rinotify'
rescue LoadError
	require 'rubygems'
	require 'rinotify'
end

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

# catch ctrl-c and clean up the RInotify object
trap("INT") do
	rinotify.close
	exit
end

# sit and watch the file.  Time out after 5 seconds.
event_thread = Thread.new do
	while (1)
		has_events = rinotify.wait_for_events(2)	
		if has_events
		
			# iterate through events
			rinotify.each_event {|revent|
				
				# check if the event we received was MODIFY or DELETE_SELF
				if revent.check_mask(RInotify::MODIFY)
					print "file was modified\n"
				elsif revent.check_mask(RInotify::DELETE_SELF)
					print "file was deleted\n"
				end
			}
		
		else
			# no events were received in the number of seconds specified in wait_for_events above
			print "Timed out\n"
		end
	end
end

event_thread.join

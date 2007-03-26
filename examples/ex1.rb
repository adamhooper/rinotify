require "rinotify"

rino = RInotify.new
t = rino.add_watch("/home/rob/tmp/test", RInotify::MODIFY)
puts rino.watch_descriptors

while(1)
	has_events = rino.wait_for_events(5)
	if has_events
		puts "has events"
		rino.read_each_event {|revent|
			wd = revent.watch_descriptor
			puts wd
		}

		has_events = false
	else
		puts "timed out"	
	end
end


rino.close

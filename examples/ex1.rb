require "rinotify"

rino = RInotify.new
t = rino.add_watch("/home/rob/tmp", RInotify::MODIFY | RInotify::DELETE | RInotify::CREATE)
puts rino.watch_descriptors

while(1)
	has_events = rino.wait_for_events(5)
	if has_events
		puts "event queue size: " + rino.event_queue_size.to_s

		rino.read_each_event {|revent|
			if revent.check_mask(RInotify::MODIFY)
				puts "modified"
			elsif revent.check_mask(RInotify::DELETE)
				puts "deleted"
			elsif revent.check_mask(RInotify::CREATE)
				puts "created"
			end

			if revent.check_mask(RInotify::ISDIR)
				puts "is a dir"
			end
		}

		has_events = false
	else
		puts "timed out"	
	end
end


rino.close

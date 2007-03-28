require "rinotify"

rino = RInotify.new
t = rino.add_watch("/home/rob/tmp", RInotify::MODIFY | RInotify::DELETE | RInotify::CREATE)
puts rino.watch_descriptors

while(1)
	has_events = rino.wait_for_events(5)
	if has_events
		puts "has events"
		rino.read_each_event {|revent|
			if revent.check_mask(RInotify::MODIFY)
				puts "modified"
			elsif revent.check_mask(RInotify::DELETE)
				puts "deleted"
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

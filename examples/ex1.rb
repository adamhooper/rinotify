require "rinotify"

rino = RInotify.new
rino.add_watch("/home/rob/tmp", RInotify::CREATE)

while(1)
	has_events = rino.wait_for_events(5)
	if has_events
		puts "has events"
		rino.read_each_event {|revent|
			puts "event_name: " + revent.name
		}

		has_events = false
	else
		puts "timed out"	
	end
end


rino.close

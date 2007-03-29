require 'test/unit'
require '../rinotify'

class TestCase_File < Test::Unit::TestCase
	def setup
		@inotify = RInotify.new

		# clear the testfile
		File.truncate("./testfile", 0)
	end

	def teardown
		@inotify.close
	end

	def test_watch_single_event
		watch_desc = @inotify.add_watch("./testfile", RInotify::OPEN)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end

	def test_watch_multi_event
		watch_desc = @inotify.add_watch("./testfile", RInotify::OPEN | RInotify::MODIFY | RInotify::ACCESS)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end

	def test_read_events
		watch_desc = @inotify.add_watch("./testfile", RInotify::MODIFY)

		# modify the file
		filehandle = File.new("./testfile", "w")
		filehandle.write("Hello World!!!")
		filehandle.close

		# wait for events
		has_events = @inotify.wait_for_events(5)
		if has_events
			@inotify.each_event {|event|
				event_check = event.check_mask(RInotify::MODIFY)
				assert(event_check)
			}
		else
			flunk
		end
	end
end

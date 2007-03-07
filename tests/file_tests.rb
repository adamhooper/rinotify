require 'test/unit'
require '../rinotify'

class TestCase_File < Test::Unit::TestCase
	def setup
		@inotify = RInotify.new
	end

	def teardown
		@inotify.close
	end

	def test_watch_single_event
		watch_desc = @inotify.add_watch("./testfile", RInotify::IN_OPEN)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end

	def test_watch_multi_event
		watch_desc = @inotify.add_watch("./testfile", RInotify::IN_OPEN | RInotify::IN_MODIFY | RInotify::IN_ACCESS)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end
end

require 'test/unit'
begin
	require 'rinotify'
rescue LoadError
	require 'rubygems'
	require 'rinotify'
end

class TestCase_Directory < Test::Unit::TestCase
	def setup
		@inotify = RInotify.new
	end

	def teardown
		@inotify.close
	end

	def test_watch_single_event
		watch_desc = @inotify.add_watch("./testdir", RInotify::OPEN)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end

	def test_watch_multi_event
		watch_desc = @inotify.add_watch("./testdir", RInotify::OPEN | RInotify::MODIFY | RInotify::ACCESS)
		@inotify.rm_watch(watch_desc)

		assert(watch_desc > 0)
	end
end

require 'test/unit'
begin
	require 'rinotify'
rescue LoadError
	require 'rubygems'
	require 'rinotify'
end

class TestCase_Obj < Test::Unit::TestCase
	def setup
		@inotify = RInotify.new
	end

	def teardown
		@inotify.close
	end

	def test_is_correct_instance
		assert_instance_of(RInotify, @inotify)	
	end
end

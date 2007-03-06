require '../rinotify'

inotify = RInotify.new
wd = inotify.add_watch("./init.rb", RInotify::IN_OPEN)
puts "\n" + wd.to_s + "\n"
inotify.rm_watch(wd)
inotify.close

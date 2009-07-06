begin
  require 'jeweler'
  Jeweler::Tasks.new do |gemspec|
    gemspec.name = "rinotify"
    gemspec.summary = "A Ruby wrapper for Linux's inotify"
    gemspec.email = "josh@technicalpickles.com"
    gemspec.homepage = "http://rinotify.migrob.com"
    gemspec.authors = ["Rob Merrell"]
    gemspec.email = "rob@migrob.com"
    gemspec.files = Dir.glob("{ext, examples, tests}/**/*")
    gemspec.require_path = "."
    gemspec.has_rdoc = false
    gemspec.extensions = ["extconf.rb"]
  end
rescue LoadError
  puts "Jeweler not available. Install it with: sudo gem install technicalpickles-jeweler -s http://gems.github.com"
end

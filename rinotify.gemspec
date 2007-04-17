require 'rubygems'
spec = Gem::Specification.new do |s|
	s.name = "RInotify"
	s.version = "0.9"
	s.author = "Rob Merrell"
	s.email = "rob@migrob.com"
	s.homepage = "http://rinotify.migrob.com"
	s.platform = Gem::Platform::LINUX_586
	s.summary = "A Ruby wrapper for Linux's inotify"

	candidates = Dir.glob("{ext, examples, tests}/**/*")
	s.files	= candidates.delete_if do |item|
				item.include?(".svn")
			  end

	s.require_path = "."
	s.has_rdoc = false
	s.autorequire = "RInotify"
	s.extensions = ["extconf.rb"]
end

if $0 == __FILE__
	Gem::manage_gems
	Gem::Builder.new(spec).build
end

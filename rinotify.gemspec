# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{rinotify}
  s.version = "0.9.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Rob Merrell"]
  s.date = %q{2009-07-06}
  s.email = %q{rob@migrob.com}
  s.extensions = ["extconf.rb"]
  s.extra_rdoc_files = [
    "README.rdoc"
  ]
  s.files = [
    "ext/rinotify.c",
     "ext/rinotify.h",
     "ext/rinotify_event.c",
     "ext/rinotify_event.h"
  ]
  s.homepage = %q{http://rinotify.migrob.com}
  s.rdoc_options = ["--charset=UTF-8"]
  s.require_paths = ["."]
  s.rubygems_version = %q{1.3.1}
  s.summary = %q{A Ruby wrapper for Linux's inotify}
  s.test_files = [
    "examples/watch_file.rb",
     "examples/watch_file_threaded.rb"
  ]

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 2

    if Gem::Version.new(Gem::RubyGemsVersion) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end


#!/usr/bin/env ruby
require 'mkmf'
old_dir = Dir.pwd
Dir.chdir(File.join File.dirname(__FILE__), 'libbsc')
system "make libbsc.a"
Dir.chdir old_dir
create_makefile("bsc") {
    |conf|
    conf[-1].gsub! /^(ldflags.+)/, "\\1 -L#{File.join '.', File.dirname(__FILE__), 'libbsc'}"
    conf[-1].gsub! /^(CFLAGS.+)/, "\\1 -lbsc"
    conf
}
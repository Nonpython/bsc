#!/usr/bin/env ruby
require 'mkmf'
create_makefile("bsc") {
    |conf|
    conf[-1].gsub! /^(CFLAGS.+)/, "\\1 -I#{File.join '.', File.dirname(__FILE__), 'libbsc'}"
    conf
}

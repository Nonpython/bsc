#include <ruby/ruby.h>
#include "libbsc/libbsc.h"
#include "libbsc/filters.h"

VALUE Bsc = Qnil;

void Init_bsc();
VALUE ruby_ruby_bsc_compress(VALUE self, VALUE args);
VALUE ruby_ruby_bsc_decompress(VALUE self, VALUE input);

void Init_bsc() {
    Bsc = rb_define_class("Bsc", rb_cObject);
    rb_define_method(Bsc, "compress", ruby_bsc_compress, -2); // -2 is the Magic Number™ for arguments as an array.
    rb_define_method(Bsc, "decompress", ruby_bsc_decompress, 1);
    
    if (bsc_init(LIBBSC_FEATURE_MULTITHREADING || LIBBSC_FEATURE_LARGEPAGES || LIBBSC_FEATURE_FASTMODE) != LIBBSC_NO_ERROR) {
        rb_raise(rb_cSystemCallError);
    }
}

VALUE ruby_bsc_compress(VALUE self, VALUE args) {
    int len = RARRAY_LEN(args);
    VALUE *args_ptr = RARRAY_PTR(args);
    char* input;
    int lzpHashSize = LIBBSC_DEFAULT_LZPHASHSIZE;
    
    for(int i = 0; i < args_len; i++) {
        
    }
    /*
    recordSize = bsc_detect_recordsize(buffer, dataSize, LIBBSC_FEATURE_FASTMODE);
	if (result != LIBBSC_NO_ERROR) {
	    {
		switch (result) {
		case LIBBSC_NOT_ENOUGH_MEMORY:
		    rb_raise(rb_cOutOfMemoryError);
		    break;
		default:
		    rb_raise(rb_SystemCallError);
		}
	    }
    }
    if (recordSize > 1) {
        int result = bsc_reorder_forward(buffer, dataSize, recordSize, LIBBSC_FEATURE_MULTITHREADING);
    	if (result != LIBBSC_NO_ERROR) {
    	    {
    		switch (result) {
    		case LIBBSC_NOT_ENOUGH_MEMORY:
    		    rb_raise(rb_cOutOfMemoryError);
    		    break;
    		default:
    		    rb_raise(rb_SystemCallError);
    		}
    	    }
        }
    }
    */
    
}
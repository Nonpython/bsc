#include <ruby/ruby.h>
#include "libbsc/libbsc.h"
#include "libbsc/filters.h"
#include <string.h>

VALUE Bsc = Qnil;

void Init_bsc();
VALUE ruby_bsc_compress(VALUE self, VALUE args);
VALUE ruby_bsc_decompress(VALUE self, VALUE input);

void Init_bsc() {
    Bsc = rb_define_class("Bsc", rb_cObject);
    rb_define_method(Bsc, "compress", ruby_bsc_compress, 1); // -2 is the Magic Number™ for arguments as an array.
    rb_define_method(Bsc, "decompress", ruby_bsc_decompress, 1);
    int init_return_val = bsc_init(LIBBSC_FEATURE_MULTITHREADING);
    if (init_return_val != LIBBSC_NO_ERROR) {
		rb_raise(rb_eSystemCallError, "libbsc internal error");
    }
}
VALUE ruby_bsc_compress(VALUE self, VALUE rb_input) {
    char *input = StringValue(rb_input);
    unsigned char *output = (unsigned char *)bsc_malloc(25 + LIBBSC_HEADER_SIZE);
    int n = strlen(input);
    bsc_compress(input, output, n, 0, 0, LIBBSC_BLOCKSORTER_BWT, LIBBSC_FEATURE_FASTMODE || LIBBSC_FEATURE_FASTMODE);
    VALUE retval = rb_str_new2(output);
    free(output);
    return retval;
}
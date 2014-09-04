#include <stdio.h>
#include <stdbool.h>

// Using this to get the same symbol names across OS X and Linux.
#define JEMALLOC_NO_DEMANGLE 1
#include <jemalloc/jemalloc.h>

/* Try to set the number of arenas via the `je_malloc_conf` symbol,
   and print out the count to verify.

   This works as expected on Linux (x86-64), but on OS X I end up with
   two instances of the je_malloc_conf symbol - one in the app and one
   in libjemalloc.2.dylib and malloc_conf_init() picks up the (NULL)
   one from libjemalloc.
*/

const char* je_malloc_conf = "narenas:1";

int main(void) {
    /* Check how many areans we have */
    unsigned narenas;
    size_t len = sizeof(narenas);

    if (je_mallctl("arenas.narenas", &narenas, &len, NULL, 0) != 0) {
        fprintf(stderr, "Failed to get narenas");
        return 1;
    }

    if (narenas != 1) {
        fprintf(stderr, "Incorrect number of arenas: %d != 1\n", narenas);
        return 2;
    }
    return 0;
}

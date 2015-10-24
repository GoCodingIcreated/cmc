#include <stdio.h>
#include <string.h>

enum 
{
    NO_SUBSTR = -1
};

int
mysubstr(const char *sample, const char *text)
{
    const char *text_pointer, *sample_pointer;
    int counter = 0;
    int is_substr = 1;
    int is_found_before_star = 1;
    if (!(*text || *sample)) {
        return 0;
    }
    if (*sample == '*' && !*(sample + 1)) {
        return 0;
    }
    while (*text) {
        sample_pointer = sample;
        text_pointer = text;
        is_substr = 1;
        while (*sample_pointer && *text_pointer && *sample_pointer != '*') {
            if (*sample_pointer == *text_pointer) {
                sample_pointer++;
                text_pointer++;
            } else {
                is_substr = 0;
                break;
            }
        }
        if (!*sample_pointer && is_substr) {
            return counter;
        }
        is_found_before_star = 0;
        if (*sample_pointer == '*' && is_substr) {
            is_found_before_star = 1;
            sample_pointer++;
            sample = sample_pointer;
            break;
        }
        counter++;
        text++;
    }
    if (!is_found_before_star) {
        return NO_SUBSTR;
    }
    while (*text) {
        sample_pointer = sample;
        text_pointer = text;
        is_substr = 1;
        while (*sample_pointer && *text_pointer && *sample_pointer == *text_pointer) {
            sample_pointer++;
            text_pointer++;
        }
        if (!*sample_pointer) {
            return counter;
        }
        text++;
    }
    return NO_SUBSTR;
}

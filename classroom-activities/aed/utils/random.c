#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

int generate_random_int(int lim) {
    return rand() % lim;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct RandomOperations RandomOperations;
typedef struct RandomGenerator RandomGenerator;
void destroy(RandomGenerator *rr);
int next(RandomGenerator *rr);

enum
{
    
    MULTIPLEX = 1103515245ll,
    INCREMENT = 12345,
    MOD = 1 << 31
};

struct RandomGenerator
{
    int start_value;
    int last_value;
    long long multiplex;
    long long increment;
    long long mod;
    RandomOperations *ops;
};

struct RandomOperations
{
    void (*destroy)(RandomGenerator *rr);
    int (*next)(RandomGenerator *rr);
};

static RandomOperations rops = {destroy, next};

RandomGenerator* random_create(int seed)
{
    RandomGenerator *rr = calloc(1, sizeof(*rr));
    rr->start_value = rr->last_value = seed;
    rr->multiplex = MULTIPLEX;
    rr->increment = INCREMENT;
    rr->mod = MOD;
    rr->ops = &rops;

    return rr;
}

int next(RandomGenerator *rr)
{
    return rr->last_value = (rr->multiplex * rr->last_value
                            + rr->increment) % rr->mod;
}

void destroy(RandomGenerator *rr)
{
    free(rr);
}


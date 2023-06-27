/*
 * Airplanes Stack (apstack)
 *
 * Implemented using Simple Dynamic Stack (sds)
 *
 * Basic operations for stack: push, pop, isEmpty, isFull, peek (without removing)
 *
 * */

typedef struct Airplane_v2 {
    char name[255];
    char company[255];

    int id;
    int maxPassengers;
} Airplane_v2;

typedef struct AirplanesStackElement {
    Airplane_v2 node;
    struct AirplanesStackElement *next;
} AirplanesStackElement;

typedef struct AirplanesStack {
    AirplanesStackElement *top;
} AirplanesStack;

AirplanesStack * apstack_create_stack();
Airplane_v2 * apstack_create_airplane(int value, char *name);

void apstack_push_airplane(AirplanesStack *src, Airplane_v2 newNode);
Airplane_v2 apstack_pop_airplane(AirplanesStack *src);
Airplane_v2 apstack_pop_airplane_at(AirplanesStack *src, int removeAt);
Airplane_v2 apstack_peek_airplane(AirplanesStack *src);

int apstack_is_empty(AirplanesStack *src);

void apstack_print_stack(AirplanesStack *src);
void apstack_print_airplane(Airplane_v2 node);
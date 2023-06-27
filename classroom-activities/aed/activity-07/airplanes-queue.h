/*
 * Airplanes Queue (apqueue)
 *
 * Implemented using Simple (Dynamic) Queue (sq)
 *
 * Basic operations for queue: create, enqueue, dequeue, isEmpty, isFull, size
 *
 * */

typedef struct Airplane {
    char name[255];
    char company[255];

    int id;
    int maxPassengers;
} Airplane;

typedef struct AirplanesQueueElement {
    Airplane airplane;
    struct AirplanesQueueElement *next;
} AirplanesQueueElement;

typedef struct SimpleQueue {
    AirplanesQueueElement *front;
    AirplanesQueueElement *back;
    int len;
} AirplanesQueue;

AirplanesQueue * apqueue_create_queue();
Airplane * apqueue_create_airplane(int id, char *name);

int apqueue_is_empty(AirplanesQueue *src);
int apqueue_get_len(AirplanesQueue *src);

void apqueue_enqueue_airplane(AirplanesQueue *src, Airplane newAirplane);
Airplane * apqueue_dequeue_airplane(AirplanesQueue *src);

void apqueue_print_queue(AirplanesQueue *src);
void apqueue_print_airplane(Airplane *src, char *title);
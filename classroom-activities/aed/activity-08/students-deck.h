/*
 * Students StudentsDeck (ststdeck)
 *
 * Implemented using Doubled Loop Linked List (dobll) + Simple Queue (sq)
 *
 * Basic operations for queue: create, enqueue, dequeue, isEmpty, isFull, size
 *
 * */

typedef struct StudentsDeckNode {
    int id;
    int pos;
    char name[255];
} StudentsDeckNode;

typedef struct StudentsDeckElement {
    StudentsDeckNode node;
    struct StudentsDeckElement *next;
    struct StudentsDeckElement *previous;
} StudentsDeckElement;

typedef struct StudentsDeck {
    StudentsDeckElement *head;
    int len;
} StudentsDeck;

StudentsDeck * stdeck_create_queue();
StudentsDeckNode * stdeck_create_node(int id, int pos, char *name);

int stdeck_is_empty(StudentsDeck *src);

void stdeck_enqueue_node_at_start(StudentsDeck *src, StudentsDeckNode newNode);
void stdeck_enqueue_node_at_end(StudentsDeck *src, StudentsDeckNode newNode);
StudentsDeckNode * stdeck_dequeue_node(StudentsDeck *src);

StudentsDeckNode * stdeck_dequeue_node_at_start(StudentsDeck *src);
StudentsDeckNode * stdeck_dequeue_node_at_end(StudentsDeck *src);

void stdeck_print_queue(StudentsDeck *src);
void stdeck_print_as_stack(StudentsDeck *src);
void stdeck_print_node(StudentsDeckNode src, char *title);
void stdeck_print_element(StudentsDeckElement *src, char *title);
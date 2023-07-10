#include <stdio.h>
#include <stdlib.h>

#include "../utils/show.h"
#include "students-deck.h"

void init_main_() {
    init_show();
}

void students_deck() {
    show_header("Example - Students (Deck)", BLUE);

    StudentsDeck *deck = stdeck_create_queue();

    StudentsDeckNode *a = stdeck_create_node(1, 1, "Gabriel");

    stdeck_enqueue_node_at_end(deck, *a);
}

int main() {
    init_main_();
    students_deck();
    return 0;
}
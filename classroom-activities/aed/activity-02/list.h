typedef struct List {
    int maxLength;
    int length;
    int *values;
} List;

/* operations */
List * create_list(int length);
void free_list(List *list);
void insert(List *list, int value);
void insert_ord(List *list, int value);
void fill_list(List *list);
void fill_list_ord(List *list);

/* special */
void sort_list(List *list);

/* prints */
void print_list_iterative(List *list);
void print_list_recursive(List *list, int index);

/* searching */
int sequential_search_list(List *list, int target);
int sequential_search_list_ord(List *list, int target);
int binary_search_list_iterative(List *list, int target);
int binary_search_list_recursive(List *list, int target, int low, int high);

/* getters */
int get_lower_list_iterative(List *list);
int get_lower_list_recursive(List *list, int lower, int index);
int get_greater_list_iterative(List *list);
int get_greater_list_recursive(List *list, int greater, int index);

int get_sum_list_iterative(List *list);
int get_sum_list_recursive(List *list, int sum, int index);
long long int get_prod_list_iterative(List *list);
long long int get_prod_list_recursive(List *list, long long int prod, int index);

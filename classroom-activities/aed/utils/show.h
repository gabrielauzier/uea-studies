#define FR_NORMAL  "\x1B[0m"
#define FR_RED  "\x1B[31m"
#define FR_GREEN  "\x1B[32m"
#define FR_YELLOW  "\x1B[33m"
#define FR_BLUE  "\x1B[34m"
#define FR_MAGENTA  "\x1B[35m"
#define FR_CYAN  "\x1B[36m"
#define FR_WHITE  "\x1B[37m"

#define end() (printf("\n\n"))
#define println(s) (printf("%s\n", s))

typedef enum { NORMAL, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE } TEXT_COLORS;

void init_show();
void title(char *string);
void subtitle(char *string);
void warn(char *string);
void attr_str(char *key, char *value);
void attr_int(char *key, int value);
void attr_dob(char *key, double value);

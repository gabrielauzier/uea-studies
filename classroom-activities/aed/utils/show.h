#define FR_NORMAL  "\x1B[0m"
#define FR_BLACK  "\x1B[30m"
#define FR_RED  "\x1B[31m"
#define FR_GREEN  "\x1B[32m"
#define FR_YELLOW  "\x1B[33m"
#define FR_BLUE  "\x1B[34m"
#define FR_MAGENTA  "\x1B[35m"
#define FR_CYAN  "\x1B[36m"
#define FR_WHITE  "\x1B[37m"

#define BG_NORMAL  "\x1B[40m"
#define BG_RED  "\x1B[41m"
#define BG_GREEN  "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE  "\x1B[44m"
#define BG_MAGENTA  "\x1B[45m"
#define BG_CYAN  "\x1B[46m"
#define BG_WHITE  "\x1B[47m"

#define endline() (printf("\n"))
#define println(s) (printf("%s\n", s))

typedef enum { NORMAL, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, BLACK } PROMPT_COLORS;

void init_show();
void show_text(char *string, PROMPT_COLORS color);
void show_text_ln(char *string, PROMPT_COLORS color);
void show_header(char *string, PROMPT_COLORS color);
void show_highlight(char *string, PROMPT_COLORS bgColor, PROMPT_COLORS textColor);
void show_highlight_ln(char *string, PROMPT_COLORS bgColor, PROMPT_COLORS textColor);
void show_separator(int n, PROMPT_COLORS color);
void show_start(PROMPT_COLORS bgColor, PROMPT_COLORS textColor);
void show_close();

void show_title(char *string);
void show_subtitle(char *string);
void show_warning(char *string);
void show_attr_str(char *key, char *value);
void show_attr_int(char *key, int value);
void show_attr_dob(char *key, double value);

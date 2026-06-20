
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int size;
} List;

void list_init(List *l);
void list_push_front(List *l, int value);
void list_push_back(List *l, int value);
void list_print(const List *l);
void list_free(List *l);
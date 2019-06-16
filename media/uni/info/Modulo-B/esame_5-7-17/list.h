typedef struct 
{
    int x;
    int y;
}coordinate;
typedef struct list_element
{
    coordinate a;
    struct list_element *next;
}item;
typedef item  *list;
list insord( int x, int y, list root);
void showlist(list l);
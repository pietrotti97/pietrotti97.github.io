typedef struct
{
    char product[50];
    int kcal;
}alimento;
typedef struct elemento
{
    alimento A;
    struct elemento *next;
}item;
typedef item *list;
list insord ( alimento a, list l);
void showlist(list l);

typedef struct 
{
    char name[50];
    int scatole;
}prodotti;
typedef struct element
{
    prodotti P;
    struct element *left, *right;
}nodo;
typedef nodo *tree; 
tree insord(prodotti PRO, tree T);
void inorder (tree t);
tree adds_an_el(prodotti PRO, tree t);
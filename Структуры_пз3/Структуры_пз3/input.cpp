FILE* myfile;
struct tree
{
    char data;
    int i;
    tree* left, * right;

};

void input(tree** Poly, FILE* myfile, int* i)
{
    char c, c2, op;
    if (fscanf(myfile, "%c", &c) != EOF)
        switch (c) {
        case '(':
        {
            *i = *i + 1;
            tree* br = new tree;
            br->left = NULL;
            br->right = NULL;
            br->i = *i;
            (*Poly)->left = br;
            input(&((*Poly)->left), myfile, i);
            fscanf(myfile, "%c", &op);
            (*Poly)->data = op;

            br = new tree;
            br->left = NULL;
            br->right = NULL;
            br->i = *i;
            (*Poly)->right = br;
            input(&((*Poly)->right), myfile, i);
        }
        break;
        case ')':
            *i = *i - 1;
            break;
        default:
        {
            tree* br = new tree;
            br->left = NULL;
            br->right = NULL;
            br->i = *i;
            (*Poly) = br;
            (*Poly)->data = c;
            break;
        }
        }
};
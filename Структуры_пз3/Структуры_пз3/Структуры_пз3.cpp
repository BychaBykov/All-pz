#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DeckLib.cpp"

FILE* myfile;

int DFSKLPK(tree* tree) {
    queue_2 e;
    queue_2* element = &e;
    queue_1 q;
    queue_1* Q = &q;
    int ans;
    int f = 0;
    int a[2], b[2];
    while (tree != NULL) {
        if ((tree->data == '+' || tree->data == '*' || tree->data == '-') && (f == 0)) {
            push(Q, tree, 1);
            push(Q, tree->right, 0);
            tree = tree->left;
        }
        else if ((tree->data == '+' || tree->data == '*' || tree->data == '-') && (f == 1)) {
            popM(element, a);
            popM(element, b);
            switch (tree->data) {
            case '+': 
                a[0] = a[0] + b[0];
                break;
            case '*':
                a[0] = a[0] * b[0];
                break;
            case '-':
                a[0] = a[0] - b[0];
                break;
            }
            pushP(element, a[0], tree->i);
            if (pop(Q, &tree, &f));
            else tree = NULL;
        }
        else {
            pushP(element, (int)(tree->data - '0'), tree->i);
            if (pop(Q, &tree, &f));
            else tree = NULL;
        }
    }
    popM(element, a);
    ans = a[0];
    return(ans);
}

void input(tree** Poly, FILE* myfile, int* i)
{
    char c, op;
    if (fscanf(myfile, "%c", &c) != EOF)
        switch (c) {
        case '(':
        {   
            (*Poly)->i = *i;
            *i = *i + 1;
            tree* br = new tree;
            br->left = NULL;
            br->right = NULL;
            br->i = *i;
            (*Poly)->left = br;
            input(&((*Poly)->left), myfile, i);
            fscanf(myfile, "%c", &op);
            while (op == ')') {
                fscanf(myfile, "%c", &op);
                *i = *i - 1;
            }
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
            (*Poly)->data = c;
            break;
        }
        }
};

void inOrderTravers(tree* root, FILE* myfile) {
    if (root) {
        inOrderTravers(root->left, myfile);
        fprintf(myfile, "%c", root->data, myfile);
        inOrderTravers(root->right, myfile);
    }
};

void vyvod(tree*Poly) {
    myfile = fopen("output.txt", "w");
    inOrderTravers(Poly, myfile);
    fprintf(myfile, "\n%i", DFSKLPK(Poly));
}

int main()
{
    int b;
    myfile = fopen("input.txt", "r");
    if (myfile == NULL)
        b = 0;
    else {
        tree* Poly = new tree;
        Poly->left = NULL;
        Poly->right = NULL;
        char c;
        int i = 0;
        input(&Poly, myfile, &i);
        vyvod(Poly);
    }
    return 0;
}

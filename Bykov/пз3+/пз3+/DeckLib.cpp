#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>

int const N = 20;

struct tree {
	int data;
	int height;
	tree* left;
	tree* right;
};

int height(tree* t) {
	if (t == NULL)
		return 0;
	else
		return t->height;
}

int bfactor(tree* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(tree* t) {
	int hl = height(t->left);
	int hr = height(t->right);
	t->height = MAX(hl,hr) + 1;
}

tree* LeftSmall(tree* t) {
	tree* p = t->right;
	t->right = p->left;
	p->left = t;
	fixheight(t);
	fixheight(p);
	return p;
}

tree* RightSmall(tree* t) {
	tree* q = t->left;
	t->left = q->right;
	q->right = t;
	fixheight(t);
	fixheight(q);
	return q;
}

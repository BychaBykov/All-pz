#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DeckLib.cpp"

FILE* myfile;

void input(tree** t, int a) {
	if (a!=0)
		if ((*t) == NULL) {
			(*t) = new tree;
			(*t)->left = NULL;
			(*t)->right = NULL;
			(*t)->height = 0;
			(*t)->data = a;
		}
		else {
			if (a > (*t)->data) {
				input(&((*t)->right), a);
			}
			else {
				input(&((*t)->left), a);
			}
		}
}
 
tree* balance(tree* t) {
	fixheight(t);
	if (bfactor(t) == 2)
	{
		if (bfactor(t->right) < 0)
			t->right = RightSmall(t->right);
		return LeftSmall(t);
	}
	else if (bfactor(t) == -2) //можно ли else if???
	{
		if (bfactor(t->left) > 0)
			t->left = LeftSmall(t->left);
		return RightSmall(t);
	}
	return t;
}

void dfs(tree** t) {
	if ((*t) != NULL) {
		dfs(&((*t)->left));
		dfs(&((*t)->right));
		*t = balance(*t);
	}
}

void AVL(tree** t) {
	myfile = fopen("input.txt", "r");
	int a;
	fscanf(myfile, "%i ", &a);
	while (a != 0) {
		input(t, a);
		fscanf(myfile, "%i ", &a);
	}
	
	dfs(t);

}

int main()
{	
	tree* t = NULL;
	AVL(&t);
}
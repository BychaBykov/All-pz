#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

FILE* myfile;
struct tree 
{ 
   char data;
   int i;
   tree*left, *right; 

};

void input(tree** Poly, FILE* myfile, int *i)
{
   char c,c2, op; 
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
         input(&((*Poly)->left), myfile, i); //посылаем за левым операндом 
         fscanf(myfile, "%c", &op);//считываем операцию
         (*Poly)->data = op;

         br = new tree;
         br->left = NULL;
         br->right = NULL;
         br->i = *i;
         (*Poly)->right = br;
         input(&((*Poly)->right), myfile, i); //посылаем за правым операндом
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


int main()
{
   myfile = fopen("input.txt", "r");
   tree* Poly = new tree;
   tree* cur = Poly;
   char c;
   int i = 0;
   fscanf(myfile, "%c", &c);
   if (c != '(')// проверка на то что вводится 1 число без скобок
   {
      Poly->data = c;
   } // конец проверки 
   else
   {
      fclose(myfile);
      myfile = fopen("input.txt", "r");
      input(&Poly, myfile, &i);
   } //конец ввода 


}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int N = 19;
FILE* myfile;

struct elem {
	char name[256];
	char type[15];
	int mem;
	int k;
	char type_k[15];
	int num = -1;
};

struct types {
	char D[7];
	int size;
};

void input(elem* t){
	myfile = fopen("table.txt", "r");
	for (int i = 0; i < N; i++) {
		fscanf(myfile, "%s %s %i %i %s", t[i].name, t[i].type, &t[i].mem, &t[i].k, t[i].type_k);
	}
}

int main()
{
	elem t[N];
	input(t);

}
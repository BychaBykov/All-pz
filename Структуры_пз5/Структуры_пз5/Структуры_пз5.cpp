#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int N = 19;
FILE* myfile;

int look = 0;
int cmp = 0;
int beg = 0;

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

int h(char* a) {
	int len = strlen(a);
	int ans = 0;
	for (int i = 0; i < len; i++)
		ans += int(a[i]);
	return (ans % N);
}

void vyvod(elem* t) {
	int i = 0;
	myfile = fopen("output.txt", "a");
	while (i < N) {
		if (strcmp(t[i].name, ""))
			fprintf(myfile, "%i %s %s %i %i %s %i\n", i, t[i].name, t[i].type, t[i].mem, t[i].k, t[i].type_k, t[i].num);
		i++;
	}

	fprintf(myfile, "%i %i %i\n\n", look, cmp, beg);
}

void add(elem* t, char* a) {
	int k = h(a);
	int counter = 0;
	sscanf(a, "%[^[{; ]", a);
	while (strcmp(t[k%N].name, a) && counter!= N) {
		k +=1;
		counter += 1;
	}
	if (!strcmp(t[k % N].name, a)) {
		t[k%N].num += 1;
	}
}

void input(elem* t){
	myfile = fopen("table.txt", "r");
	int i = 0;
	while (fscanf(myfile, "%i ", &i) != EOF) {
		fscanf(myfile, "%s %s %i %i %s", t[i].name, t[i].type, &t[i].mem, &t[i].k,t[i].type_k);
		if (strcmp(t[i].name, "")) t[i].num = 0;
	}
	myfile = fopen("code.txt", "r");
	char a[25];
	char prev[25];
	while (fscanf_s(myfile, "%s ", a,sizeof(a)) != EOF) {
		if (!strcmp(a, "=")) {
			add(t, prev);
			while (fscanf_s(myfile, " %[^[; ] ", a, sizeof(a)) != 0) {
				if (strcmp(a, "+")) add(t, a);
			}
		}
		else if (!strcmp(a, "if(")) {
			while (fscanf_s(myfile, " %[^[) ]", a, sizeof(a)) != 0) {
				add(t, a);
			}
		}
		strcpy_s(prev, a);
	}
	vyvod(t);
}

void piv(elem* t, int L, int R, int* ri, int* rj)
{
	elem c = t[(L+R)/2];
	int i = L;
	int j = R;
	look += 1;
	while (i <= j)
	{
		while (t[i].num > c.num) {
			i++;
			cmp += 1;
		}
		while (t[j].num < c.num) {
			j--;
			cmp += 1;
		}
		if (i <= j)
		{
			elem x = t[i];
			t[i] = t[j];
			t[j] = x;
			i++;
			j--;
			beg += 3;
		}
	}
	*ri = i;
	*rj = j;
}

void Quicksort(elem* t, int L, int R)
{
	int i;
	int j;
	if (R - L > 0)
	{
		piv(t, L, R, &i, &j);
		if (L < j) Quicksort(t, L, j);
		if (i < R) Quicksort(t, i, R);
	}
}



int main()
{
	elem t[N];
	for (int i = 0; i < N; i++) {
		strcpy_s(t[i].name, "");
	}
	input(t);
    Quicksort(t, 0, N - 1);
	vyvod(t);
}

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
	int num;
};

struct table {
	elem t[N];
	int n;
};

struct types {
	char D[7];
	int size;
};

int find(table* t, char* a) {
	int k = 0;
	int counter = 0;
	while (strcmp((t->t)[k].name, a) != 0 && counter != N) {
		k += 1;
		counter += 1;
	}
	if (!strcmp((t->t)[k].name, a))
		return k;
	else
		return -1;
}

void input(table* t) {
	fopen_s(&myfile,"input.txt", "r");
	char* str;
	char name[256];
	char type[7];
	int mem;
	int k;
	int key = 0;
	char type_k[7];
	char a[250];
	int flag;
	char b[2];
	types data[4];
	strcpy_s(data[0].D, "int");
	data[0].size = sizeof(int);
	strcpy_s(data[1].D, "float");
	data[1].size = sizeof(float);
	strcpy_s(data[2].D, "double");
	data[2].size = sizeof(double);
	strcpy_s(data[3].D, "bool");
	data[3].size = sizeof(bool);
	fscanf_s(myfile, "%s", a, sizeof(a));
	while (strcmp(a, "{"))
		fscanf_s(myfile, "%s", a, sizeof(a));
	while (fscanf_s(myfile, " %[^[; ] ", a,sizeof(a)) != EOF && key != -1) {
		flag = 0;
		for (int i = 0; i < 4; i++) {
			if (!strcmp(a, data[i].D)) {
				flag = 1;
				strcpy_s(type, a);
				fscanf_s(myfile, " %[^[;] ", a, sizeof(a));
				if (key < N) {
					strcpy_s(name, a);
					(t->t)[key].mem = data[i].size;
					(t->t)[key].num = 0;
					strcpy_s((t->t)[key].name, name);
					strcpy_s((t->t)[key].type, type);
					if (fgetc(myfile) == '[') {
						fscanf_s(myfile, "%d", &k);
						(t->t)[key].k = k;
						strcpy_s((t->t)[key].type, "array");
						strcpy_s((t->t)[key].type_k, type);
					}
					key += 1;
				}
			}
		}
		if (flag == 0) {
			do {
				if (strcmp(a, "=") && strcmp(a, "+")) {
					k = find(t, a);
					if (k != -1) {
						(t->t)[k].num += 1;
					}
				}
			} while (fscanf_s(myfile, " %[^[; ] ", a, sizeof(a)) != 0);
			fgetc(myfile);
		}
		
	}
};

int main()
{
	table t;
	t.n = 0;
	for (int i = 0; i < N; i++) {
		strcpy_s(t.t[i].name, "");
		t.t[i].k = 0;
		strcpy_s(t.t[i].type_k, "");

	}
	input(&t);

}
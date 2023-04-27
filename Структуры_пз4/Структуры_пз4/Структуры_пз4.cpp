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
};

struct types {
	char D[7];
	int size;
};

int find(int k, elem* t) {
	int counter = 0;
	while (strcmp(t[k % N].name, "")) {
		k += 1;
		counter += 1;
		if (counter == N) {
			return -1;
		}
	}
	return k;
}

int h(char* str) {
	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len; i++)
		ans += int(str[0]);
	return (ans%N);
}

void vyvod(elem* t) {
	myfile = fopen("output.txt","w");
	for (int i = 0; i < N; i++) {
		if (strcmp(t[i].name, "")) {
			fprintf(myfile, "%s %s %i %i %s\n", t[i].name, t[i].type, t[i].mem, t[i].k, t[i].type_k);
		}
	}
}

void input(elem* t) {
	myfile = fopen("input.txt","r");
	char* str;
	char name[256];
	char type[7];
	int mem;
	int k;
	int key = 0;
	char type_k[7];
	char a[250];
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
	while (fscanf(myfile, "%s", a) != EOF && key != -1) {
		for (int i = 0; i < 4; i++) {
			if (!strcmp(a, data[i].D)) {
				key = h(name);
				key = find(key, t);
				if (key != -1) {
					strcpy_s(type, a);
					fscanf_s(myfile, " %[^[;]", a, sizeof(a));
					strcpy_s(name, a);
					t[key].mem = data[i].size;
					strcpy_s(t[key].name, name);
					strcpy_s(t[key].type, type);
					if (fgetc(myfile) == '[') {
						fscanf_s(myfile, "%d", &k);
						t[key].k = k;
						strcpy_s(t[key].type, "array");
						strcpy_s(t[key].type_k, type);
					}
				}
			}
		}
	}
};

int main()
{
	elem t[N];
	for (int i = 0; i < N; i++) {
		strcpy_s(t[i].name,"");
		t[i].k = 0;
		strcpy_s(t[i].type_k,"");
	}
	input(t);
	vyvod(t);
}
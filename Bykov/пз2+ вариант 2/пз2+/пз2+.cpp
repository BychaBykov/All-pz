#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeckLib.cpp"


FILE* file;

void vyvod(queue_2* C) {
	file = fopen("output.txt", "w");
	showQ(C, file);
}

void program(FILE* ifile,queue_2* C) {
	int i = 0;
	char a;
	while (fscanf(ifile, "%c", &a) != EOF) {
		if (a == ')')
			i = i - 1;
		else if (a == '(')
			i = i + 1;
		else if (a == '-' || a == '+' || a == '*')
			pushM(C, i, a);
		else
			pushP(C, i, a);
	}
}

int main() {
	file = fopen("input.txt","r");
	if (file == NULL) {
		file = fopen("output.txt", "w");
	}
	else {
		queue_2 c;
		queue_2* C = &c;
		program(file,C);
		vyvod(C);
	}
	return 0;
}
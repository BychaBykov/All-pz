#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeckLib.cpp"


FILE* ifile;
FILE* ofile;

void program(FILE* ifile) {
	int i = 0;
	char a;
	char sym[2];
	queue_2 c;
	queue_2* C = &c;
	ofile = fopen("output.txt", "w");
	while (fscanf(ifile, "%c", &a) != EOF) {
		if (a == '-' || a == '+' || a == '*')
			pushP(C, i, a);
		else if (a == ')') {
			popM(C, sym);
			fprintf(ofile, "%c", sym[1]);
			i = i - 1;
		}
		else if (a == '(')
			i = i + 1;
		else
			fprintf(ofile, "%c", a);
	}
}


int main() {
	ifile = fopen("input.txt","r");
	if (ifile == NULL) {
		ofile = fopen("output.txt", "w");
	}
	else {
		program(ifile);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeckLib.cpp"


FILE* file;
FILE* out;

void vyvod(queue_1* B) {
	file = fopen("output.txt", "w");
	showQ(B,file);
}

void program(FILE* file, queue_1* B) {
	int i = 0;
	char a;
	char sym[2];
	queue_2 c;
	queue_2* C = &c;
	while (fscanf(file, "%c", &a) != EOF) {
		if (a == '-' || a == '+' || a == '*')
			pushP(C, i, a);
		else if (a == ')') {
			if (popM(C, sym) != 0){
				pushM(B, sym[1]);
				i = i - 1;
			}
		}
		else if (a == '(')
			i = i + 1;
		else
			pushM(B, a);
	}
}


int main() {
	file = fopen("input1.txt","r");
	if (file == NULL) {
		file = fopen("output.txt", "w");
	}
	else {
		queue_1 b;
		queue_1* B = &b;
		program(file, B);
		vyvod(B);
	}
	return 0;
}
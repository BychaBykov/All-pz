#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeckLib.cpp"


FILE* myfile;

void program(queue_1** A, queue_2** B, queue_2** C, char a, int *j) {
	if (a == '(') {
		j++;
		push(*A, *j);
	}
	else if (a == ')') {
		int k;
		pop(*A, &k);
		j++;
		pushP(*B, k, *j);
		pushM(*C, k, *j);
	}
}

void vyvod(queue_2* B, queue_2* C) {
	myfile = fopen("output.txt", "w");
	int a = 0;
	while (a <= B->end) {
		fprintf_s(myfile, "(%i %i) ", B->data[a][0], B->data[a][1]);
		a++;
	}
	a = 0;
	while (a <= C->end) {
		fprintf_s(myfile, "(%i %i) ", C->data[a][0], C->data[a][1]);
		a++;
	}
}

int main() {
	myfile = fopen("input.txt", "r");
	if (myfile == NULL){
		myfile = fopen("output.txt", "w");
		fprintf_s(myfile, " ");
	}
	else {
		queue_1* A = new queue_1;
		queue_2* B = new queue_2;
		queue_2* C = new queue_2;
		char sym;
		int j = 0;
		while (fscanf(myfile, "%c", &sym) != EOF) {
			program(&A, &B, &C,sym,&j);
		}
	}
	int afafa = 0;
	return 0;
}


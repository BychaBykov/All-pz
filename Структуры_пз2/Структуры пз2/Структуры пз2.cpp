#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeckLib.cpp"


FILE* myfile;
FILE* file;

void program(queue_1** A, queue_2** B, queue_2** C, char a, int *j) {
	if (a == '(') {
		*j = *j + 1;
		push(*A, *j);
	}
	else if (a == ')') {
		int k;
		pop(*A, &k);
		*j = *j + 1;
		pushP(*B, k, *j);
		pushM(*C, k, *j);
	}
}

void vyvod(queue_2* B, queue_2* C,FILE* myfile) {
	int a = 0;
	while (a <= B->end) {
		fprintf_s(myfile, "%i %i ", B->data[a][0], B->data[a][1]);
		a++;
	}
	fprintf_s(myfile,"\n");
	a = 0;
	while (a <= C->end) {
		fprintf_s(myfile, "%i %i ", C->data[a][0], C->data[a][1]);
		a++;
	}
}

int main() {
	myfile = fopen("input4.txt", "r");
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
		file = fopen("output.txt", "w");
		while (fscanf(myfile, "%c", &sym) != EOF) {
			program(&A, &B, &C,sym,&j);
			
			showQ(A,file);
			/*showQMP(B,file);
			showQMM(C,file);*/
		}
		fprintf_s(myfile, "\n");
		vyvod(B, C,file);
	}
	return 0;
}


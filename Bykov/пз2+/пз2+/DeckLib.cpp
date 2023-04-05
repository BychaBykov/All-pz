#include <stdio.h>

int const N = 20;

struct queue_1 {
	int beg = 0;
	int end = -1;
	int data[N];
};

struct queue_2 {
	int beg = 0;
	int end = -1;
	int data[N][2];
};

int push(queue_1* q, int a) {
	if (((q->end + 1) % N == q->beg) && (q->end != -1))
		return 0;
	int i = (q->end + 1) % N;
	while ((i != q->beg) && (q->data[(i - 1) % N] < a)) {
		q->data[i] = q->data[(i - 1) % N];
		i = (i - 1) % N;
	}
	q->data[i] = a;
	q->end = (q->end + 1) % N;
	return 1;
}

int pushM(queue_2* q, int k, int j) {
	if (((q->end + 1) % N == q->beg) && (q->end != -1))
		return 0;
	if (q->end == -1) {
		q->end++;
		q->data[q->end][0] = k;
		q->data[q->end][1] = j;
		return 1;
	}
	int i = (q->end + 1) % N;
	while ((i != q->beg) && (q->data[(i - 1) % N][1] > j)) {
		q->data[i][0] = q->data[(i - 1) % N][0];
		q->data[i][1] = q->data[(i - 1) % N][1];
		i = (i - 1) % N;
	}
	q->data[i][0] = k;
	q->data[i][1] = j;
	q->end = (q->end + 1) % N;
	return 1;
}

int pushP(queue_2* q, int k, int j) {
	if (((q->end + 1) % N == q->beg) && (q->end != -1))
		return 0;
	if (q->end == -1) {
		q->end++;
		q->data[q->end][0] = k;
		q->data[q->end][1] = j;
		return 1;
	}
	int i = (q->end + 1) % N;
	while ((i != q->beg) && (q->data[(i - 1) % N][0] < k)) {
		q->data[i][0] = q->data[(i - 1) % N][0];
		q->data[i][1] = q->data[(i - 1) % N][1];
		i = (i - 1) % N;
	}
	q->data[i][0] = k;
	q->data[i][1] = j;
	q->end = (q->end + 1) % N;
	return 1;
}

int pop(queue_1 *q, int* a)
{
	if (q->end == -1)
		return 0;
	*a = q->data[q->beg];
	q->data[q->beg] = -1;
	if (q->beg == q->end) {
		q->beg = 0;
		q->end = -1;
		return 1;
	}
	else
		q->beg = (q->beg + 1) % N;
	return 1;
}

int popM(queue_2* q, char* a) {
	if (q->end == -1)
		return 0;
	a[0] = q->data[q->beg][0];
	a[1] = q->data[q->beg][1];
	if (q->beg == q->end) {
		q->beg = 0;
		q->end = -1;
		return 1;
	}
	else
		q->beg = (q->beg + 1) % N;
	
	return 1;
}

void showQ(queue_1* q, FILE* myfile) { 
	if (q->end != -1) {
		queue_1 CRINGE;
		queue_1* COPY = &CRINGE;
		int a;
		while ((q->beg) != ((q->end)+1)%N) {
			pop(q, &a);
			fprintf_s(myfile, "%i ", a);
			push(COPY, a);
		}
		while ((COPY->beg) != ((COPY->end)+1)%N) {
			pop(COPY, &a);
			push(q, a);
		}
		fprintf_s(myfile, "\n");
	}
}

#include <stdio.h>


struct queue_1 {
	int beg = 0;
	int end = -1;
	int data[20];
};

struct queue_2 {
	int beg = 0;
	int end = -1;
	int data[20][2];
};

int push(queue_1* q, int a) {
	if (((q->end + 1) % 20 == q->beg) && (q->end != -1))
		return 0;
	int i = (q->end + 1) % 20;
	while ((i != q->beg) && (q->data[(i - 1) % 20] < a)) {
		q->data[i] = q->data[(i - 1) % 20];
		i = (i - 1) % 20;
	}
	q->data[i] = a;
	q->end = (q->end + 1) % 20;
	return 1;
}

int pushM(queue_2* q, int k, int j) {
	if (((q->end + 1) % 20 == q->beg) && (q->end != -1))
		return 0;
	if (q->end == -1) {
		q->end++;
		q->data[q->end][0] = k;
		q->data[q->end][1] = j;
		return 1;
	}
	int i = (q->end + 1) % 20;
	while ((i != q->beg) && (q->data[(i - 1) % 20][1] > j)) {
		q->data[i][0] = q->data[(i - 1) % 20][0];
		q->data[i][1] = q->data[(i - 1) % 20][1];
		i = (i - 1) % 20;
	}
	q->data[i][0] = k;
	q->data[i][1] = j;
	q->end = (q->end + 1) % 20;
	return 1;
}

int pushP(queue_2* q, int k, int j) {
	if (((q->end + 1) % 20 == q->beg) && (q->end != -1))
		return 0;
	if (q->end == -1) {
		q->end++;
		q->data[q->end][0] = k;
		q->data[q->end][1] = j;
		return 1;
	}
	int i = (q->end + 1) % 20;
	while ((i != q->beg) && (q->data[(i - 1) % 20][0] > k)) {
		q->data[i][0] = q->data[(i - 1) % 20][0];
		q->data[i][1] = q->data[(i - 1) % 20][1];
		i = (i - 1) % 20;
	}
	q->data[i][0] = k;
	q->data[i][1] = j;
	q->end = (q->end + 1) % 20;
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
		q->beg = (q->beg + 1) % 20;
	return 1;
}

int popM(queue_2* q, int* a) {
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
		q->beg = (q->beg + 1) % 20;
	
	return 1;
}

void showQ(queue_1* q, FILE* myfile) { 
	if (q->end != -1) {
		queue_1 CRINGE;
		queue_1* COPY = &CRINGE;

		int a;
		while ((q->beg) != ((q->end)+1)%20) {
			pop(q, &a);
			fprintf_s(myfile, "%i ", a);
			push(COPY, a);
		}
		while ((COPY->beg) != ((COPY->end)+1)%20) {
			pop(COPY, &a);
			push(q, a);
		}
		fprintf_s(myfile, "\n");
	}
}
//void showQMP(queue_2* q, FILE* myfile) {
//	int a[2];
//	queue_2 COPY;
//	if (q->end != -1) {
//		while ((q->beg) != ((q->end) + 1) % 20) {
//			popM(q, a);
//			fprintf_s(myfile, "%i %i ", a[0],a[1]);
//			pushP(&COPY, a[0], a[1]);
//		}
//		while ((COPY->beg) != ((COPY->end) + 1) % 20) {
//			popM(&COPY, a);
//			pushP(q, a[0],a[1]);
//		}
//		fprintf_s(myfile, "\n");
//	}
//}

//void showQMM(queue_2* q, FILE* myfile) {
//	int a[2];
//	queue_2* COPY;
//	if (q->end != -1) {
//		while ((q->beg) != ((q->end) + 1) % 20) {
//			popM(q, a);
//			fprintf_s(myfile, "%i %i ", a[0], a[1]);
//			pushM(COPY, a[0], a[1]);
//		}
//		while ((COPY->beg) != ((COPY->end) + 1) % 20) {
//			popM(COPY, a);
//			pushM(q, a[0], a[1]);
//		}
//		fprintf_s(myfile, "\n");
//	}
//}

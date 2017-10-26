#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DQNode {
	element data;
	struct DQNode *llink;
	struct DQNode *rlink;
}DQNode;

typedef struct {
	DQNode *front, *rear;
}DQueType;

void init(DQueType *d) {
	d->front = NULL;
	d->rear = NULL;
}
int is_empty(DQueType *d) {
	if (d->front == NULL&&d->rear==NULL)
		return 1;
	else
		return 0;
}
void insert_front(DQueType *d, element data) {
	DQNode *tmp = (DQNode*)malloc(sizeof(DQNode));
	tmp->data = data;
	tmp->llink = NULL;
	tmp->rlink = NULL;

	if (is_empty(d)) {
		d->front = tmp;
		d->rear = tmp;
	}
	else {		
		d->front->llink = tmp;
		tmp->rlink = d->front;
		d->front = tmp;
	}
}
void insert_back(DQueType *d, element data) {
	DQNode *tmp = (DQNode*)malloc(sizeof(DQNode));
	tmp->data = data;
	tmp->llink = NULL;
	tmp->rlink = NULL;

	if (is_empty(d)) {
		d->front = tmp;
		d->rear = tmp;
	}
	else {		
		d->rear->rlink = tmp;
		tmp->llink = d->rear;
		d->rear = tmp;
	}
}
element delete_front(DQueType *d) {
	if (is_empty(d)) {
		fprintf(stderr, "deque is empty.\n");
		exit(1);
	}
	else {
		if (d->front ->rlink==NULL)
			d->rear = NULL;

		element ret=d->front->data;
		d->front = d->front->rlink;
		if (d->front->llink != NULL) {
			free(d->front->llink);
			d->front->llink = NULL;
		}
		return ret;
	}
}
element delete_back(DQueType *d) {
	if (is_empty(d)) {
		fprintf(stderr, "deque is empty.\n");
		exit(1);
	}
	else {
		if (d->rear->llink==NULL)
			d->front = NULL;

		element ret = d->rear->data;
		d->rear = d->rear->llink;
		if (d->rear->rlink != NULL) {
			free(d->rear->rlink);
			d->rear->rlink = NULL;
		}
		return ret;
	}
}
void printDQ(DQueType *DQ) {
	DQNode *tmp = DQ->front;
	int cnt = 0;
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->rlink;
		cnt++;
	}
	printf("\n");
	printf("size : %d\n", cnt);
}
int main() {
	DQueType d;
	init(&d);

	insert_front(&d, 1);
	insert_front(&d, 2);
	insert_back(&d, 3);

	
	printf("%d\n", delete_front(&d));
	
	printf("%d\n", delete_back(&d));
	
	printf("%d\n", delete_front(&d)); // It's that fucking line.
}

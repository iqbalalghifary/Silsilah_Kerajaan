#ifndef queue_H
#define queue_H
#include"linked.h"

typedef address Queue;

void CreateEmpty(Queue *Q);

boolean IsEmpty(Queue Q);

void Enqueue(Queue *Q,infotype2 X);

void Dequeue(Queue *Q,infotype2 *X);

int SearchList(Queue Q,infotype2 x);

#endif

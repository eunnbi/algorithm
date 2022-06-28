# Queue

> FIFO (First In First Out)

<br/>

## Array-based Implementation of Queue

```cpp
// Circular Queue

#define QUEUE_SIZE 100


typedef struct _Queue{
    int front;
    int rear;
    int queue[QUEUE_SIZE];
} Queue;

int nextPosIdx(int pos){
    if (pos == QUEUE_SIZE - 1){
        return 0;
    }
    else {
        return (pos + 1);
    }
}

void initQueue(Queue* pq){
    pq->front = 0;
    pq->rear = 0;
}

int IsEmpty(Queue* pq){
    return pq->front == pq->rear;
}

void enqueue(Queue* pq, int data){
    if (pq->front == nextPosIdx(pq->rear)) exit(-1);
    pq->queue[pq->rear] = data;
    pq->rear = nextPosIdx(pq->rear);
}

int dequeue(Queue* pq){
    int rdata;
    if (IsEmpty(pq)) exit(-1);
    rdata = pq->queue[pq->front];
    pq->front = nextPosIdx(pq->front);
    return rdata;
}

int peek(Queue* pq){
    if (IsEmpty(pq)) exit(-1);
    return pq->queue[pq->front];
}
```

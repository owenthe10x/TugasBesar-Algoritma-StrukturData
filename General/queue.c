/* File: queue.c */

#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* *** Prototype *** */
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return (IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q);
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else if (IDX_HEAD(q) <= IDX_TAIL(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    } else {
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    if (!isFull(*q)) {
        if (isEmpty(*q)) {
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        }
        TAIL(*q) = val;
    } else {
        printf("Queue penuh. Enqueue gagal.\n");
    }
}

void dequeue(Queue *q, ElType *val) {
    if (!isEmpty(*q)) {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        } else {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    } else {
        printf("Queue kosong. Dequeue gagal.\n");
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;
    }

    printf("[");
    int i = IDX_HEAD(q);
    do {
        printf("%d", q.buffer[i]);
        if (i != IDX_TAIL(q)) {
            printf(",");
        }
        i = (i + 1) % CAPACITY;
    } while (i != (IDX_TAIL(q) + 1) % CAPACITY);
    printf("]\n");
}
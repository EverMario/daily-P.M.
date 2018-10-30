#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declares a large array on the stack
void allocateOnStack() {
    char space[1024];
}

// declares a same large array from the heap
void allocateOnHeap() {
    void *space = malloc(1024);
    free(space);
}

// calls each of the funtions 1m times and outputs the time required by each
int main() {
    int counter = 1000000;
    clock_t timeBegin;
    clock_t timeEnd;
    timeBegin = clock();
    for (int i = 0; i < counter; i++) {
        allocateOnStack();
    }
    timeEnd = clock();
    printf("[%d times] Allocate 1 KiB on stack: %lu tick\n", counter, timeEnd - timeBegin);
    timeBegin = clock();
    for (int i = 0; i < counter; i++) {
        allocateOnHeap();
    }
    timeEnd = clock();
    printf("[%d times] Allocate 1 KiB on heap: %lu tick\n", counter, timeEnd - timeBegin);
    return 0;
}

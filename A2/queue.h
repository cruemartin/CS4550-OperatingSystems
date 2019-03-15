
struct queue{

    int front;
    int end;
    int size;
    unsigned maxSize;
    int *array;

}typedef queue;

queue creatQueue(queue * q, unsigned maxSize);


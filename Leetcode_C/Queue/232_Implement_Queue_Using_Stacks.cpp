/*
Imaging two bucket 'one' on the left and 'two' on the right. 
Push 'X' in to bucket one - 'one'.
Before pushing 'X2' to 'one', take 'X' from 'one' to bucket two - 'two'.
Then push 'X2' into 'one'. Get 'X' from 'two' to 'one'.
Every time you want to push a number into 'one',
you have to move all the number in 'one' to 'two' one by one.
After pushing the the number to 'one', get all the number back from 'two'.
Thus we can promise the number on the top of 'one' is the one should be pop or peek.
*/
typedef struct {
    // I love it just define one struct for two bucket. You can define two if you like.
    int dataone[1000]; // bucket one
    int topone;

    int datatwo[1000]; // bucket two
    int toptwo;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->topone = -1; // Start from -1 is easy for me. 
    queue->toptwo = -1; // You can start from 0 if you like.
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    while (obj->topone != -1) obj->datatwo[++obj->toptwo] = obj->dataone[obj->topone--]; // from 'one' to 'two'
    obj->dataone[++obj->topone] = x; // push 'x' into 'one'
    while (obj->toptwo != -1) obj->dataone[++obj->topone] = obj->datatwo[obj->toptwo--]; // from 'two' back to 'one'
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    return obj->dataone[obj->topone--]; // return the top one of 'one'
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->dataone[obj->topone]; // return but not minus minus
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->topin == -1 &&  obj->toptwo == -1; // when top is -1 means not number 
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
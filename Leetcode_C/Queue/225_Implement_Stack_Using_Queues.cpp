// Just use an array to simulate a stack.
// Imaging a bucket as a stack. You can only push or remove from the top.

typedef struct {
    int data[1000]; // The size is enough for this leetcode.
    int top; // Get the top of the stack
} MyStack;

/** Initialize your data structure here. */
// If top start from -1, we add up the 'top' then put x in or out of the bucket.
// But if top start from 0, we put x in or out of the bucket then add up the top.
// Both ways are ok. Choose what you like.
MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack)); 
    stack->top = -1;
    return stack;
}

/** Push element x onto stack. */
// Push x onto the bucket then add up to.
void myStackPush(MyStack* obj, int x) {
    obj->data[++obj->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
// 
int myStackPop(MyStack* obj) {
    return obj->data[obj->top--];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
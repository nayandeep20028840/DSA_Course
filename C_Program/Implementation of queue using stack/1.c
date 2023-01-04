/*
 * C Program to Implement Queues using Stacks
 */
#include <stdio.h>
#include <stdlib.h>
 
int stack1[100] , stack2[100];
int top1 = -1 , top2 = -1;
int count = 0;
 
/*Function to create a queue*/
void create(){
    top1 = top2 = -1;
}
 
/*Function to push the element on to the stack*/
void push1(int data){
    stack1[++top1] = data;
}
 
/*Function to pop the element from the stack*/
int pop1(){
    return(stack1[top1--]);
}
 
/*Function to push an element on to the stack2*/
void push2(int data){
    stack2[++top2] = data;
}
 
/*Function to pop an element from th stack2*/
 
int pop2(){
    return(stack2[top2--]);
}
 
/*Function to add an element into the queue using stack*/
void enqueue(){
    int data, i;
    printf("Enter data into queue");
    scanf("%d " , &data);
    push1(data);
    count++;
}
 
/*Function to delete an element from the queue using stack*/
 
void dequeue(){
    int i;
    for (i = 0 ; i <= count ; i++){
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0 ; i <= count ; i++){
        push1(pop2());
    }
}
 
/*Function to display the elements in the stack*/
 
void display(){
    int i;
    for (i = 0;i <= top1;i++){
        printf(" %d ", stack1[i]);
    }
}

int main(){
    int ch;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    create();
    while (1){
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}
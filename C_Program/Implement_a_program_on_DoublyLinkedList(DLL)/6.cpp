#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int id;
    char name[10];
    char branch[5];
    char phone_no[15];
    struct node *next;
    struct node *prev;
};
struct node *newnode , *head , *temp = 0 , *tail ;

struct node *getnode(){
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    if (x == NULL){
        printf("Memory Insufficient ");
        exit(0);
    }
    x -> next = 0 ;
    x -> prev = 0 ;
    return x;
}
void List(){
    int i = 2;
    while (i > 0){
        newnode = getnode();
        printf("Enter id of the student : ");
        scanf("%d", &newnode->id);
        printf("Enter name of the student : ");
        scanf("%s", &newnode->name);
        printf("Enter branch of the student : ");
        scanf("%s", &newnode->branch);
        printf("Enter phone no of the student : ");
        scanf("%s", &newnode->phone_no);
        if (head == NULL){
            head = temp = tail = newnode;
        }else{
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode ;
            tail = newnode ;
        }
        i = i - 1;
    }
}
void display_content(){
    temp = head;
    int count = 0;
    while(temp != 0){
        cout<<temp->id<<" "<<temp->name << " " << temp->branch << " " << temp->phone_no << endl;
        temp = temp -> next;
        count++;
    }
    printf("Total number of nodes present in the linked list are : %d\n ", count);
}
void insertion_at_front_end(){
    newnode = getnode();
    printf("Enter id of the student : ");
    scanf("%d", &newnode->id);
    printf("Enter name of the student : ");
    scanf("%s", &newnode->name);
    printf("Enter branch of the student : ");
    scanf("%s", &newnode->branch);
    printf("Enter phone no of the student : ");
    scanf("%s", &newnode->phone_no);
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    printf("Data entered successfully at front end.\n");
}

void insertion_at_rear_end(){
    newnode = getnode();
    printf("Enter id of the student : ");
    scanf("%d", &newnode->id);
    printf("Enter name of the student : ");
    scanf("%s", &newnode->name);
    printf("Enter branch of the student : ");
    scanf("%s", &newnode->branch);
    printf("Enter phone no of the student : ");
    scanf("%s", &newnode->phone_no);
    temp = tail ;
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = 0;
    printf("Data inserted successfully at the rear end.\n");
}

void insertAtPos(){
    int i;
    printf("Enter the position : ");
    scanf("%d", &i);
    if (i == 1){
        insertion_at_front_end();
    }else{
        newnode = getnode();
        printf("Enter id of the student : ");
        scanf("%d", &newnode->id);
        printf("Enter name of the student : ");
        scanf("%s", &newnode->name);
        printf("Enter branch of the student : ");
        scanf("%s", &newnode->branch);
        printf("Enter phone no of the student : ");
        scanf("%s", &newnode->phone_no);
        temp = head;
        while (i - 2 > 0){
            temp = temp->next;
            i--;
        }
        newnode -> prev = temp;
        newnode -> next = temp -> next;
        temp -> next = newnode;
        newnode->next->prev = newnode;
    }
}

void deletion_at_front_end(){
    if (head == 0){
        printf("Linked List is empty.");
    }
    temp = head;
    head = temp -> next;
    head -> prev = 0;
    free(temp);
}

void deletion_at_rear_end(){
    struct node *curr;
    curr = temp;
    temp = temp -> prev;
    temp -> next = 0;
    free(curr);
}
int main(){
    List();
    insertion_at_front_end();
    // deleteEnd();
    // insertAtPos();
    display_content();
}

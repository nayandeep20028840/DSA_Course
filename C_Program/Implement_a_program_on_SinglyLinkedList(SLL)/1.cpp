/*
Experiment:3	Design, Develop and Implement a menu driven Program for the following operations on Singly Linked List (SLL) with Header node of Student data with the fields:
Roo No, Name, Branch, Semester, Phone No.	30	19/09
	1.	Create SLL of N students data by using front insertion 
2.	Display the content of SSL and count the number of nodes
3.	Perform Insertion and Deletion at Rear End of SLL
4.	Perform Insertion and Deletion at Front End of SLL
5.	Demonstrate how this SLL can be used as Double Ended Queue
6.	Exit		
*/

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int id;
    char name[100];
    char branch[5];
    char phone_no[15];

    struct node *next;
};
struct node *newnode, *head, *temp = 0;

struct node *getnode()
{
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Memory Insufficient ");
        exit(0);
    }
    else
        x -> next = 0;
        return x;
}

void List()
{

    int i = 2;

    while (i > 0)
    {
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
            head = newnode;
            temp = newnode;
        }else{
            temp -> next = newnode;
            temp = newnode;
        }

        i = i - 1;
    }
}

void display()
{
    // temp->next = 0;
    temp = head;
    int count=0;

    while (temp != 0)
    {

        cout << temp->id << " " << temp->name << " " << temp->branch << " " << temp->phone_no << endl;
        temp = temp->next;
        count++;

    }
    printf("Total number of nodes present in the linked list are : %d\n ",count);

}
void insertfront()
{
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
    head = newnode;
    
}

void insertrear(){
    
    temp = head;
    while(temp -> next != 0){
        temp = temp -> next;
    }
    newnode = getnode();
    printf("Enter id of the student : ");
    scanf("%d", &newnode -> id);

    printf("Enter name of the student : ");
    scanf("%s", &newnode -> name);

    printf("Enter branch of the student : ");
    scanf("%s", &newnode -> branch);

    printf("Enter phone no of the student : ");
    scanf("%s", &newnode -> phone_no);

    newnode -> next = 0;
    temp -> next = newnode;
}

void deleteBegin(){
    temp = head;
    head = temp -> next;
    free(temp);
}

void deleteEnd(){

    temp = head;
    struct node *curr;
    while(temp -> next != 0){
        curr = temp;
        temp = temp -> next;
    }
    curr -> next = 0;
    free(temp);
}
int main()
{
    List();
    // display();
    insertfront();
    deleteEnd();
    display();
    // deleteBegin();
    // display();

}
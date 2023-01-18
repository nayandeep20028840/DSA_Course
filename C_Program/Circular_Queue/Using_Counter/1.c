#include<stdio.h>
#include<string.h>

int s[5];
int counter = 0;

void display(){
    if(counter == 0){
        printf("Nothing is there to print : ");
    }else{
        printf("The Context of the stack is : ");
        for(int i = 0 ; i < counter ; ++i){
            scanf("%d" , s[i]);
        }
    }
}

void push(int item , int top){
    if(counter == 5){
        printf("The Stack is Full");
    }else{
        top++;
        s[top] = item;
        counter++;
    }
}

int pop(int delete , int top){
    if(counter == 0){
        printf("The Stack is Empty");
    }else{
        delete = s[top];
        top--;
        counter--;
        return delete;
    }
}

int main(){
    int top = -1;
    int ch;
    int delete = 0;
    int flag = 1;
    while(flag){
        printf("Enter a choice : 
                                1. push 
                                2. Display
                                3. pop 
                                4. Exit \n") ;
        scanf("%d" , ch);
        switch(ch){
            case 1:
                printf("Enter a Element to be inserted");
                int item;
                scanf("%d" , item);
                push(item , top);
                break;
            case 2:
                display();
            case 3:
                if(delete == 0 && top == -1){
                    printf("Umderflow");
                }else{
                    delete = pop(delete , top);
                    printf("The deleted element is : %d" , delete);
                }
                break;
            case 4:
                flag = 0;
                break;
        }
    }
}

#include<stdio.h>
#include<string.h>
struct node{
    int c,x,y,z;
    struct node* link;
};
typedef struct node* NODE;

NODE getnode(int c, int x, int y, int z){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == 0){
        printf("Out of Memorty \n");
        return temp;
    }
    temp->c = c;
    temp->x = x;
    temp->y = y;
    temp->z = z;
    temp->link = 0;
    return temp;
}
void insert_at_rear(int c, int x, int y, int z, NODE header){
    NODE temp = getnode(c,x,y,z);
    NODE cur = header->link;
    if(cur == 0){
        header->link = temp;
    }else{
        while(cur->link != 0){
            cur = cur->link;
        }
        cur->link = temp;
    }
}
int evaluate(int x, int y, int z, NODE header){
    NODE cur = header->link;
    int res = 0;
    while(cur != 0){
        res += (cur->c) * (pow(cur->x,x)) * (pow(cur->y,y)) * (pow(cur->z,z));
        cur = cur->link;
    }
    return res;
}
void print(NODE header){
    NODE cur = header->link;
    if(cur == 0){
        printf("\n");
    }else{
        while(cur->link != 0){
            printf("%d->",cur->c); 
            printf("x^ %d->",cur->x);
            printf("y^ %d->",cur->y);
            printf("z^ %d->",cur->z);
            print(" + ");
            cur = cur->link;
        }
        printf("%d->",cur->c); 
        printf("x^ %d->",cur->x);
        printf("y^ %d->",cur->y);
        printf("z^ %d->",cur->z);
        printf("\n");
    }
}
int main()
{
    int c,x,y,z;
    NODE header = getnode(c,x,y,z);
    int choice;
    while(1){
        printf("Enter your choice : \n");
        printf("1 - To enter the Polynomial \n");
        printf("2 - Evaluate the Expression \n");
        printf("3 - Print the Expression \n");
        printf("4 - Exit\n");
        scanf("%d",choice);
        switch(choice){
            case(1):   
                    while(1){
                        printf("Enter c,x,y,z for term : ");
                        scanf("%d%d%d%d",&c,&x,&y,&z);
                        if(!c && !x && !y && !z){
                            break;
                        }else{
                            insert_at_rear(c,x,y,z,header);
                        }
                    }
                    break;
            case(2):   
                    printf("Enter the values of x,y,z : ");
                    scanf(x);
                    scanf(y);
                    scanf(z);
                    printf("The result of the Expression is ",evaluate(x,y,z,header),"\n");
                    break;
            case(3):   
                    printf("The expression is as follows : \n");
                    print(header);
                    break;
            case(4):   
                    return 0;
        }
    }
}
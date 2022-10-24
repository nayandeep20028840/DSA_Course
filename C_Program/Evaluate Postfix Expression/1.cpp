#include<stdio.h>
#include<string.h>

int SP(char symbol){
    switch(symbol){
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '$': return 5;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int value02(int a , char symbol , int b){
    switch(symbol){
        case '+': return (a + b);
        case '-': return (a - b);
        case '*': return (a * b);
        case '/': return (a / b);
        case '^': return (a ^ b);
        default: return 7;
    }
}

int inftopos(char inf[] , int res , int array[]){
    char s[20];
    int top , i , j;
    char symbol;
    top = -1;
    j = 0;
    for(int i = 0; i < strlen(inf); ++i){
        symbol = inf[i];
        if(SP(symbol) == 8){
            s[++top] = symbol;
        }else{
            char op2 = s[top--];
            char op1 = s[top--];
            char op = symbol;
            // printf("%c %c %c %d %d " , op2 , op1 , op , array[int(op2) - 65] , array[int(op1) - 65]);
            res = value02(array[int(op1) - 65] , op , array[int(op2) - 65]);
            array[int(op1) - 65] = res;
            // printf("%d %c '\n" , res , char(int(op1) - 65 + 65));
            s[++top] = char(int(op1));
        }
    }
    printf("The value is....... ");
    printf("%d" , res);
}

int main(){
    char inf[20];
    int res;
    scanf("%s" , inf);
    int count = 0;
    for(int i = 0; i < strlen(inf); ++i){
        if(SP(inf[i]) == 8){
            count++;
        }
    }
    // printf("%d\n" , count);
    int array[count];
    for(int i = 0; i < count; ++i){
        scanf("%d" , &array[i]);
    }
    inftopos(inf , res , array);
    // printf("The value is....... ");
    // printf("%d" , res);
}

// give Input as ABC*+ and then give the values of operands(A , B)
// Output should be an integer
// written and directed by Nayan Deep ;
// It might be wrong ....

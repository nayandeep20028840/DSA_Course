//code for to convert an expression infex to postfix 

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

int IP(char symbol){
    switch(symbol){
        case '+': return 1;
        case '-': return 1;
        case '*': return 3;
        case '/': return 3;
        case '$': return 6;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

int inftopos(char inf[] , char pos[]){
    char s[30];
    int top , i , j;
    char symbol;
    top = -1;
    s[top] = '#';
    j = 0;
    for(i = 0; i < strlen(inf); ++i){
        symbol = inf[i];
        while(SP(s[top]) > IP(symbol)){
            pos[j++] = s[top--];
        }
        if(SP(s[top]) != IP(symbol)){
            s[++top] = symbol;
        }else{
            top--;
        }
    }
    while(s[top] != '#'){
        pos[i++] = s[top++];
    }
    pos[j] = '\0';
}

int main(){
    char inf[30];
    char pos[30];
    scanf("%s" , inf);
    inftopos(inf , pos);
    printf("The pos....... ");
    printf("%s" , pos);
}




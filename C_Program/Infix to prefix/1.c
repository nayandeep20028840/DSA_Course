// code for to convert an expression infex to prefix

#include<stdio.h>
#include<ctype.h>
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
        case '(': return 100;
        case ')': return 0;
        default: return 7;
    }
}

int inftopre(char inf[] , char pos[]){
    char s[30];
    int top , i , j;
    char symbol;
    top = -1;
    s[top] = '#';
    j = 0;
    for(int i = 0; i < strlen(inf); ++i){
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
    int size = strlen(inf);
    int j = size, i=0;
    char temp[size];
    temp[j--]='\0';
    while(inf[i]!='\0'){
        temp[j] = inf[i];
        j--;
        i++;
    }
    strcpy(inf,temp);
    i = 0;
    while(inf[i]!='\0'){
        if(inf[i]=='('){
            inf[i]=')';
        }
        else if(inf[i]==')'){
            inf[i]='(';
        }
        i++;
    }
    inftopre(inf , pos);
    size = strlen(pos);
    j = size, i=0;
    char temp2[size];
    temp[j--]='\0';
    while(pos[i]!='\0'){
        temp2[j] = pos[i];
        j--;
        i++;
    }
    strcpy(pos,temp2);
    printf("The pos....... ");
    printf("%s" , pos);
}

example (A + B * C) to (+A *BC)




#include<stdio.h>
#include<string.h>

int main(){
    char str[100],stack[100];
    int i , top=-1;
    
    printf("enter your string: ");
    fgets(str,sizeof(str),stdin);
    
    for(i=0;str[i]!='\0' && str[i]!='\n';i++){
        if(str[i]=='*'){
            if(top == -1){
                printf("empty stack!!");
            }else{
                top--;
            }
        }
        else{
            top++;
            stack[top]=str[i];
        }
    }
    stack[top +1]='\0';
    printf("modified string = %s",stack);
    return 0;
}

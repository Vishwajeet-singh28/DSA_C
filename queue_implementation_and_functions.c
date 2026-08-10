#include<stdio.h>

#define SIZE 10
int queue[SIZE];
int F=-1;
int R=-1;

void enqeue(int value){
    if(R==SIZE-1){
        printf("queue is full\n");
        return;
    }
    R++;
    queue[R]=value;
    printf("%d inserted \n",value);
}

void deque(){
    if(F==-1&&R==-1){
        printf("queue is empty\n");
        return ;
    }
    printf("%d deleted \n",queue[F]);
    F++;
    if(F>R){
        F==-1;
        R==-1;
    }
}

void peek(){
    if(F==-1&&R==-1){
        printf("queue is empty\n");
        return ;
    }
    printf("%d front elment is: ",queue[F]);
}

void display(){
    if(F==-1&&R==-1){
        printf("queue is empty\n");
        return ;
    }
    printf("queue:\n ");
    for(int i=F;i<=R;i++){
        printf("%d ",queue[i]);
    }
}

int main(){
    int choice,value;
    while(1){
        printf("----queue-----\n");
        printf("1.enqeue\n");
        printf("2.deque\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        
        printf("enter choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("enter value: ");
            scanf("%d",&value);
            enqeue(value);
            break;
            
            case 2:
            deque();
            break;
            
            case 3:
            peek();
            break;
            
            case 4:
            display();
            break;
            
            case 5:
            return 0;
            
            default:
            printf("enter valid choice");
            
        }
    }
    return 0;
}

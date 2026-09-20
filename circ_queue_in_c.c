#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front =-1;
int rear = -1;

void enqueue(int v){
    if((rear+1)%MAX==front){
        printf("queue is full \n");
        return;
    }
    
    printf("enter value: ");
    scanf("%d",&v);
    
    if(front == -1){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    queue[rear]=v;
}

void dequeue(){
    if(front == -1){
        printf("queue is empty:\n ");
        return ;
    }
    
    printf("deleted element is :%d ",queue[front]);
    
    if(front==rear){
        front = -1;
        rear = -1;
    }
    else{
        front=(front+1)%MAX;
    }
}


void peek(){
    if(front == -1){
        printf("empty queue\n");
        return ;
    }
    
    printf("peek element of the queue is: %d",queue[front]);
}

void display(){
    
    if(front== -1){
        printf("empty queue\n");
        return ;
    }
    
    printf("queue\n");
    
    int i=front;
    
    while(1){
        printf("%d",queue[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int choice,v;
    
    while(1){
        printf("-----MENU------\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek()\n");
        printf("4.display\n");
        printf("5.exit\n");
        
        printf("enter choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                enqueue(v);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                peek();
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("exit");
                return 0;
            
            default:
                printf("enter valid case\n");
        }
    
    }
}

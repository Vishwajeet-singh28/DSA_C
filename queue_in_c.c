#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int v){
    if(rear == MAX - 1){
        printf("qeue is full\n");
        return;
    }
    
    printf("enter value: ");
    scanf("%d",&v);
    
    if(front == -1){
        front = 0;
    }
    
    rear ++;
    queue[rear]=v;
    printf("element inserted\n");
}

void dequeue(){
    
    if(front == -1){
        printf("queue is empty");
        return ;
    }
    
    printf("deleted element is: ",queue[front]);
    front ++;
    
    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void peek(){
    if(front == -1){
        printf("queue is empty\n");
        return ;
    }
    
    printf("peek of yhe queue is : %d",queue[front]);
}


void display(){
    if(front == -1){
        printf("queue is empty nothing to display\n");
        return ;
    }
    
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
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
            
            default:
                printf("enter valid case\n");
        }
    
    }
}

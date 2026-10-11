#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(){
    struct node *head=NULL,*temp,*newnode;
    int n,i;
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        
        printf("enter node: %d ",i+1);
        scanf("%d",&newnode->data);
        
        newnode->next=NULL;
        
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node *head){
    struct node *temp;
    
    temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

struct node *prime(struct node *head){
    struct node *temp;
    int i;
    temp=head;
    while(temp!=NULL){
        if(temp->data > 1){
            for(i=2;i<temp->data;i++){
                if(temp->data % i ==0){
                    break;
                }
            }
            if(i==temp->data){
                printf("%d",temp->data);
            }
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    
    struct node *temp,*head,*current,*duplicate;
    printf("creating linked list\n");
    head=create();
    
    printf("\ndisplaying created linked list\n");
    display(head);
    
    printf("list: ");
    prime(head);
    
    return 0; 
}

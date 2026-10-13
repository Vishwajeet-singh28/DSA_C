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

void cycledetection(struct node *head){
    struct node *team=head,*slow=head,*fast=head;
    
    while(fast!= NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow == fast){
            printf("cycle found");
            return;
        }
    }
    printf("cycle not found");
}

void makecycle(struct node *head){
    struct node *temp;
    temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=head->next;
}


int main(){
    struct node *head,*slow,*fast,*temp;
    
    printf("creating linked list\n");
    head=create();
    
    printf("\ndisplaying created linked list\n");
    display(head);
    
    makecycle(head);
    
    printf("\ndetecting cycle:\n");
    cycledetection(head);
    
    return 0;
}

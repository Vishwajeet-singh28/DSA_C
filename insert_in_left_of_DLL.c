#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create(){
    struct node *head=NULL,*temp,*newnode;
    int n , i;
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter node %d: ",i+1);
        scanf("%d",&newnode->data);
        
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("empty list");
        return;
    }
    while(temp!=NULL ){
        printf("%d -><- ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct node *insertleft(struct node *head){
    struct node *temp=head;
    struct node *newnode;
    
    int val;
    printf("enter value that you want to insert: ");
    scanf("%d",&val);
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;

   
        newnode->next=head;
        newnode->prev=NULL;

    return newnode;;
}

int main(){
    struct node *head=NULL,*temp,*newnode;
    printf("creating list: \n");
    head=create();
    
    printf("displaying linked list: \n");
    display(head);
    
    printf("insert left\n");
    head=insertleft(head);
    display(head);
    
    return 0;
}

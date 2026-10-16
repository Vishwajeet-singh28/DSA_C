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

void displayleft(struct node *head){
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

void displayright(struct node *head){
    struct node *temp=head;
    
    if(head==NULL){
        printf("emoty list");
        return ;
    }
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    while(temp != NULL){
        printf("%d -><-",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}

int main(){
    struct node *head=NULL;
    printf("creating linked list:\n ");
    head=create();
    
    printf("display  left to right linked list: \n");
    displayleft(head);
    
    printf("display  right to left  linked list: \n");
    displayright(head);

    return 0;
}

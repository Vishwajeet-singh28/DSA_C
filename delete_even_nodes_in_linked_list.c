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
        printf("enter node %d: ",i+1);
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
    struct node *temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
*/
/*struct node *evendelete(struct node *head){
    struct node *temp=head->next;
    struct node *prev=head;
    while(temp !=NULL){
        prev->next=temp->next;
        free(temp);
        temp=prev->next->next;
        prev=prev->next;
    }
    return head;
}
*/
/*
struct node *evendelete(struct node *head){
    
    struct node *prev=head;
    struct node *temp=head->next;
    while(temp !=NULL){
        prev->next=temp->next;
        prev=temp->next;
        free(temp);
        temp=prev->next;
    }
    return head;
}

int main(){
    struct node *head,*temp,*newnode,*current,*c;
    printf("creating linked list:\n ");
    head=create();
    
    printf("display linked list: \n");
    display(head);
    
    printf("newlinked list: \n");
    head=evendelete(head);
    
    display(head);
    
    return 0;
}

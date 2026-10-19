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


struct node *delete(struct node *head){
    struct node *temp=head,*del;
    
    while(temp != NULL){
        if((temp->data % 2)==0){
            del=temp;
            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            
            temp=temp->next;
            free(del);
            
        }else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    struct node *head=NULL,*temp,*newnode;
    printf("creating list: \n");
    head=create();
    
    printf("displaying linked list: \n");
    display(head);
    
    printf(" list: \n");
    head=delete(head);
    display(head);
    
    return 0;
    
}

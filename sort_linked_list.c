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

struct node *sort(struct node *head){
    struct node *temp=head,*current;
    
    while(temp !=NULL){
        current=temp;
        int c;
        while(current->next!=NULL){
            if(temp->data < current->next->data){
                c=current->next->data;
                current->next->data=temp->data;
                temp->data=c;
            }
            current=current->next;
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
    
    printf("list:\n ");
    head=sort(head);
    
    printf("sorted list:\n");
    display(head);
    
    return 0; 
    
}

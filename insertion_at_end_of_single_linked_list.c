#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node* head=NULL,*temp,*newnode;
    int n,i,value;
    
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        
        printf("enter data %d: ",i+1);
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
    
    printf("linked list before insertion: \n");
    
    temp = head;
    
    while(temp !=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    
    printf("\nenter value you want to insert: ");
    scanf("%d",&value);
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=value;
    newnode->next=NULL;
    
    temp=head;
    
    while(temp->next != NULL){
        temp=temp->next;
    }
    
    temp->next=newnode;
    
    printf("linked list after insertion: \n");
    
    temp = head;
    
    while(temp !=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return 0;   
}

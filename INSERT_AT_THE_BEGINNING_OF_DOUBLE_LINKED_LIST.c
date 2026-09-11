#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    struct node *prev;
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
        
        printf("enter data %d: ",i+1);
        scanf("%d",&newnode->data);
        
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(head==NULL){
           head=newnode;
           temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    
    return head;
}

void display(struct node *head){
    struct node *temp;
    
    temp=head;
    
    printf("DLL: \n");
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void insertinbeginning(struct node *head){
    struct node *temp,*newnode;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("enter data: ");
    scanf("%d",&newnode->data);
    
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
    temp=head;
    
    printf("DLL after insertion is:\n ");
    
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main(){
    struct node *head=NULL,*temp,*newnode;
    int choice;
    
    while(1){
        printf("------MENU------\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.insert in begining\n");
        printf("4.exit\n");
        
        printf("enter your choice: \n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            head=create();
            break;
            
            case 2:
            display(head);
            break;
            
            case 3:
            insertinbeginning(head);
            break;
            
            case 4:
            printf("\nexit\n");
            return 0;
            
            default:
            printf("\nenter valid choice\n");
            
        }
    }
}

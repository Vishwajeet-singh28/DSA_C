#include<stdio.h>
#include<stdlib.h>

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
    
    printf("DLL before insertion: \n");
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void insertaftervalue(struct node *head){
    struct node *temp,*newnode;
    int value,i,node;
    
    printf("enter value that you want to insert: ");
    scanf("%d",&value);
    
    
    printf("enter node after which you want to insert: ");
    scanf("%d",&node);
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    temp=head;
    
    
    while(temp != NULL && temp->data != node){
        temp=temp->next;
    }
    
    if(temp == NULL){
    printf("Node not found");
    free(newnode);
    return;
    }
    
    newnode->next=temp->next;
    newnode->prev=temp;
    
    if(temp->next != NULL){
        temp->next->prev=newnode;
    }
    
    temp->next=newnode;
    
    temp=head;
    
    printf("DLL after insertion: \n");
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void insertbeforevalue(struct node *head){
    struct node *temp,*newnode;
    int i,value,node;
    
    printf("enter value that you want to insert: ");
    scanf("%d",&value);
    
    printf("enter node before which you want to insert: ");
    scanf("%d",&node);
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    temp=head;
    
    while(temp != NULL && temp->data != node){
        temp=temp->next;
    }
    
    if(temp==NULL){
        printf("node not found");
        free(newnode);
        return ;
    }
    
    if(temp->prev==NULL){
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
    }
    
    newnode->prev=temp->prev;
    newnode->next=temp;
    temp->prev->next=newnode;
    temp->prev=newnode;
    
    temp=head;
    
    printf("DLL after insertion: \n");
    
    while(temp != NULL){
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
        printf("3.insert after value\n");
        printf("4.insert before value\n");
        printf("5.exit\n");
        
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
            insertaftervalue(head);
            break;
            
            case 4:
            insertbeforevalue(head);
            break;
            
            case 5:
            printf("\nexit\n");
            return 0;
            
            default:
            printf("\nenter valid choice\n");
            
        }
    }
}

#include<stdio.h>
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
        newnode=(struct node*)malloc(sizeof(struct node) );
        
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
    return head;
}

void display(struct node *head){
    struct node *temp;
    
    if(head==NULL){
        printf("\nlinked list is empty\n");
        return;
    }
    
    temp=head;
    
    printf("\nLINKED LIST: \n");
    
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
}

struct node *reverse(struct node *head){
    
    struct node *prev=NULL;
    struct node *current=head;
    struct node *nextnode;
    
    while(current != NULL){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    
    head=prev;
    return head;
}

int main(){
    
    struct node *head=NULL;
    int choice;
    
    while(1){
        
        printf("\n LINKED LIST MEANU-----\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.reverse\n");
        printf("4.exit\n");
        
        printf("enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            
            case 1:
                head=create();
                break;
                
            case 2:
                display(head);
                break;
                
            case 3:
                head=reverse(head);
                printf("\nlinked list after reversal: \n")
                break;
                
            case 4:
                printf("exit");
                return 0;
                
            default:
                printf("enter valid choice please");
        }
    }
}

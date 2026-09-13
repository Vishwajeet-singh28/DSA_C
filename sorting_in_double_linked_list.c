#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(){
    struct node *head=NULL,*temp,*newnode;
    int i,n;
    
    printf("enter no. of nodes you want to enter: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        
        newnode=(struct node *)malloc(sizeof(struct node));
        
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

void sort(struct node *head){
    struct node *temp,*second;
    int c;

    temp=head;
    while(temp != NULL){
        second=temp->next;
        
        while(second != NULL){
            if(temp->data > second->data ){
                c=temp->data;
                temp->data=second->data;
                second->data=c;
            }
            second=second->next;
        }
        temp=temp->next;
    }
    
    temp=head;
    printf("DLL: \n");
    
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
        printf("3.DLL after sorting\n");
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
            sort(head);
            break;
            
            case 4:
            printf("\nexit\n");
            return 0;
            
            default:
            printf("\nenter valid choice\n");
            
        }
    }
}


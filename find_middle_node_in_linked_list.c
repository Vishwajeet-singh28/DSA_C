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
    return head;
}

void display(struct node *head){
    
    struct node *temp;
    
    if(head==NULL){
        printf("\nlinked list is empty\n");
        return ;
    }
    
    temp=head;
    
    printf("LINKED LIST: \n");
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return;
}

void middle(struct node *head){
    
    struct node *temp;
    int count=0,i;
    
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    
    temp=head;
    for(i=0;i<count/2;i++){
        temp=temp->next;
    }
    
    printf("%d is the middle node",temp->data);
}

void findmiddle(struct node *head){
    
    struct node *temp;
    struct node *slow=head;
    struct node *fast=head;
    
    temp=head;
    
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast = fast->next->next;
    }
    
    printf("middle = %d",slow->data);
}

int main(){
    struct node *head=NULL;
    
    int choice;
    
    while(1){
    
        printf("-----MENU------\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.findmiddle first method:\n");
        printf("4.find middle 2nd method:\n");
        printf("5.exit\n");
        
        printf("enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                
            head=create();
            break;
            
            case 2:
            
            display(head);
            break;
            
            case 3:
            
            middle(head);
            break;
            
            case 4:
            findmiddle(head);
            break;
            
            case 5:
            
            printf("\nexit\n");
            return 0;
            
            default:
            
            printf("\nenter valid choice\n");
        }
    }
}

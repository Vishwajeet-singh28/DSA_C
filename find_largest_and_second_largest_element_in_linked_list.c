#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

void largest(struct node *head){
    struct node *temp;
    int largest;
    
    if(head==NULL){
        printf("empty linked list");
        return ;
    }
    
    temp=head;
    largest = head->data;
    
    while(temp != NULL){
        if(temp->data > largest){
            largest = temp-> data;
        }
        
        temp=temp->next;
    }
    printf("largest element is: %d ",largest );
}


void secondlargest(struct node *head){
    struct node *temp;
    int largest,second;
    
    if(head==NULL || head->next == NULL){
        printf("\nnot enough elements\n");
        return ;
    }
    
    temp=head;
    
    largest=head->data;
    second=INT_MIN;
    
    while(temp!=NULL){
        if(temp->data>largest){
            
            second=largest;
            largest=temp->data;
            
        }
        else if(temp->data>second && temp->data != largest){
            
            second = temp ->data;
        }
        
        temp=temp->next;
    }
    printf("second largest element is: %d",second);
    
}

int main(){
    struct node *head=NULL;
    
    int choice;
    
    while(1){
    
        printf("-----MENU------\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.secondlargest\n");
        printf("4.largest\n");
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
            
            secondlargest(head);
            break;
            
            case 4:
            largest(head);
            break;
            
            case 5:
            
            printf("\nexit\n");
            return 0;
            
            default:
            
            printf("\nenter valid choice\n");
        }
    }
    return 0;
}

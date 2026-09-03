#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int main(){
    struct node *head=NULL,*temp,*newnode;
    int n , i , value , pos;
    
    printf("enter no. of enter: ");
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
        
        printf("enter value you want to enter: ");
        scanf("%d",&value);
        
        printf("enter position at which you want to enter: ");
        scanf("%d",&pos);
        
        newnode=(struct node*)malloc(sizeof(struct node));
        
        newnode->data=value;
        newnode->next=NULL;
        
        if(pos==1){
            newnode->next=head;
            head=newnode;
        }
        else{
            temp=head;
            
            for(i=1;i<pos-1;i++){
                temp=temp->next;
            }
            
            newnode->next=temp->next;
            temp->next=newnode;
        }
    
    printf("LINKED LIST: \n");
    
    temp=head;
    
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return 0;
}

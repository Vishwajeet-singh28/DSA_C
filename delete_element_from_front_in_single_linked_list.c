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
    
    printf("deleting from linked list: \n");
    
    if(head==NULL){
        printf("linked list is empty");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
    
    printf("LINKED LIST AFTER DELETION: \n");
    
    temp=head;
    
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return 0;
}

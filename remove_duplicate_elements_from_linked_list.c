#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int main(){
    struct node *head=NULL,*temp,*newnode, *pre;
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
    
    temp=head->next;
    pre=head;
    while(temp!=NULL){
        if(pre->data==temp->data){
            pre->next=temp->next;
            temp->next=NULL;
            free(temp);
            temp=pre->next;
        }
        else{
            pre=temp;
            temp=temp->next;
        }
    }
    
    printf("LINKED LIST AFTER DELETION OF DUPLICATE ELEMENTS: \n");
    
    temp=head;
    
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return 0;
}

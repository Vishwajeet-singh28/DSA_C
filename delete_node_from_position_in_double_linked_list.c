#include<stdio.h>
#include<stdlib.h>

void delete(struct node *head){
    struct node *temp;
    int pos,i;
    
    printf("enter position: ");
    scanf("%d",&pos);
    
    if(pos==1){
        temp=head;
        head=head->next;
        
        if(head != NULL){
            head->prev=NULL;
        }
        
        free(temp);
        return ;
    }
    
    temp=head;
    
    for(i=1;i<pos;i++){
        temp=temp->next;
    }
    
    if(temp == NULL){
        printf("invalid position");
        return ;
    }
    
    temp->prev->next=temp->next;
    
    if(temp->next != NULL){
        
        temp->next->prev=temp->prev;
        
    }
    
    temp->prev=NULL;
    temp->next=NULL;
    
    free(temp);
    
}

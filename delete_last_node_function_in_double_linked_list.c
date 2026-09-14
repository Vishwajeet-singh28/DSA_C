#include<stdio.h>
#include<stdlib.h>

void deletelast(struct node *head){
    struct node *temp;
    
    if(head==NULL){
        printf("DLL is empty");
        return;
    }
        temp=head;
       
        while(temp->next!= NULL){
            temp=temp->next;
        }
        
        if(temp->prev==NULL){
            free(temp);
            return;
        }
        
        temp->prev->next=NULL;
        temp->prev=NULL;
        free(temp);
        
        temp=head;
        
        printf("DLL after deletion: \n");
        
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
}

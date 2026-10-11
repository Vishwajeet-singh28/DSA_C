#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node *delete(struct node *head){
    struct node *temp=head,*del;
    int val,count=0,i;
    
    printf("enter value that you want to delete: ");
    scanf("%d",&val);
    
    while(temp != NULL){
        count ++;
        temp=temp->next;
    }
    
    temp=head;
    for(i=1;i<=count-val-1;i++){
        temp=temp->next;
    }
    
    del=temp->next;
    temp->next=del->next;
    del->next->prev=del->prev;
    free(del);
    
    return head;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void split(struct node *head){
    struct node *temp=head;
    struct node *slow=head;
    struct node *fast=head,*head2;

    if(head==NULL || head->next == NULL){
        printf("can't split");
        return ;
    }
    
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast = fast -> next->next;
    }
    
    head2=slow->next;
    slow->next=NULL;
    
    printf("first node: \n");
    display(head);
    
    printf("second node: \n");
    display(head2);
}

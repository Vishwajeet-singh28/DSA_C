#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node *sort(struct node *head){
    struct node *temp=head,*current;
    int c;
    
    while(temp!= NULL){
        current=temp;
        while(current->next!=NULL){
            if(temp->data > current->next->data){
                c=current->next->data;
                current->next->data=temp->data;
                temp->data=c;
            }
            current=current->next;
        }
        temp=temp->next;
    }
    return head;
}

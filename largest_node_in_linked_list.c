#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void largestnode(struct node *head){
    struct node *temp=head;
    int largest=head->data;
    while(temp != NULL){
        if(temp->data > largest){
            largest=temp->data;
        }
        temp=temp->next;
    }
    printf("largest: %d",largest);
}
*/

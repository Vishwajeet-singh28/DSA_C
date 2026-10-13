#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(){
    struct node *head=NULL,*temp,*newnode;
    int n , i;
    
     printf("Enter no. of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter node %d: ", i + 1);
        scanf("%d", &newnode->data);
        
        newnode->next=NULL;
        
        if (head == NULL) {
            head = newnode;
            temp = newnode;
            newnode->next = head;
        }else {
            newnode->next = head;
            temp->next = newnode;
            temp = newnode;
        }
        
    }
    return head;
}

void display(struct node *head){
    struct node *temp;
    temp=head;
    do{
        printf("%d",temp->data);
        temp=temp->next;
    }while(temp!=NULL)
}


void display(struct node *head){
    struct node *temp=head;
    
    if(head==NULL){
        return;
    }
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    while (temp!=head);
    
    printf("back to the head");
    
}


struct node *merge(struct node *head1,struct node *head2 ){
    struct node *temp1=head1,*temp2=head2,*head3=NULL,*temp,*newnode;
    
    

    while(temp1->next!=head1){
        temp1=temp1->next;
    }
    
    while(temp2->next != head2){
        temp2=temp2->next;
    }
    
    temp1->next=head2;
    temp2->next=head1;
    
    return head1;
}

int main(){
    struct node *head,*temp,*newnode,*head1,*head2,*temp1,*temp2;
    printf("creating list 1:\n ");
    head1=create();
    
    printf("creating list 2:\n ");
    head2=create();
    
    printf("displaying list 1: \n");
    display(head1);
    
    printf("displaying list 2:\n");
    display(head2);
    
    
    printf("merged list: ");
    head=merge(head1,head2);
    
    display(head);
    
    return 0;
}

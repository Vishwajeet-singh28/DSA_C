#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *create(){
    struct node *head=NULL,*temp,*newnode;
    int n,i;
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enetr node %d: ",i+1);
        scanf("%d",&newnode->data);
        
        newnode->next=NULL;
        
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node *head){
    struct node *temp=head;
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

struct node *merge(struct node *head1,struct node *head2){
    struct node *temp1=head1,*temp,*newnode;
    struct node *temp2=head2;
    struct node *head3=NULL;
    
    while(temp1 != NULL && temp2 != NULL){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(temp1->data < temp2->data){
            newnode->data=temp1->data;
            temp1=temp1->next;
        }
        else if(temp2->data < temp1->data){
            newnode->data=temp2->data;
            temp2=temp2->next;
        }
        else{
            newnode->data=temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        newnode->next=NULL;
        
        if(head3==NULL){
            head3=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
        
        while(temp1!=NULL){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=temp1->data;
            newnode->next=NULL;
            
            if(head3==NULL){
                head3=newnode;
                temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            temp1=temp1->next;
        }
        
         while(temp2!=NULL){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=temp2->data;
            newnode->next=NULL;
            
            if(head3==NULL){
                head3=newnode;
                temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            temp2=temp2->next;
    }
    return head3;
}

int main(){
    
    struct node *head1,*head2,*head3;
    printf("first list: \n ");
    head1=create();
    
    printf("second list: \n");
    head2=create();
    
    printf("displaying frist list: \n ");
    display(head1);
    
    printf("displaying second list: \n ");
    display(head2);
    
    head3=merge(head1,head2);
    
    printf("Merged sorted list: ");
    display(head3);

    return 0;
}

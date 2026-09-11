#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(){
    struct node *head=NULL,*temp,*nenwode;
    int n,i;
    
    printf("enter no. of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        
        printf("enter data: %d",i+1);
        scanf("%d",&newnode->data);
        
        newnode->next=NULL:
        newnode->prev=NULL;
        
        if(head==NULL){
           head=newnode;
           temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    
    return head;
}

void display(struct node *head){
    struct node *temp;
    
    temp=head;
    
    printf("DLL: \n")
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void count(struct node *head){
    struct node *temp;
    int c=0;
    
    temp=head;
    
    while(temp != NULL){
        c++;
        temp=temp->next;
    }
    printf("no. of nodes= %d",c);
}

void countevenandodd(struct node *head){
    struct node *temp;
    int ec=0,oc=0;
    
    temp=head;
    
    while(temp != NULL){
        if(temp->data % 2 == 0){
            ec++;
        }
        else{
            oc++;
        }
        temp=temp->next;
    }
    printf("even and odd counts are: %d , %d ",ec,oc);
}

void largest(struct node *head){
    struct node *temp;
    
    int largest;
    
    largest=head->data;
    
    temp=head;
    while(temp != NULL){
        if(temp->data > largest){
            largest=temp->data;
        }
        temp=temp->next;
    }
    
    printf("largest element in node is : %d",largest);
}

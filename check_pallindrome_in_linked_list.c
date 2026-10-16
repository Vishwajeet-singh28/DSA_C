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
        printf("enter node %d: ",i+1);
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
    return head;
}

void pallindrome(struct node *head){
    struct node *temp=head ;
    int arr[100],i=0,j;
    
    while(temp != NULL){
        arr[i]=temp->data;
        i++;
        temp=temp->next;
    }
    
    for(j=0;j<i/2;j++){
        if(arr[j]!=arr[i-j-1]){
            printf("not pallindrome");
            return;
        }
    }
    printf("pallindrome");
}
void display(struct node *head){
    struct node *temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head=NULL;
    printf("creating linked list:\n ");
    head=create();
    
    printf("display linked list: \n");
    display(head);
    
    printf("ll is pallindrome = ");
    pallindrome(head);
    
    return 0;
}

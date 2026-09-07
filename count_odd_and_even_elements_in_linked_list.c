#include<stdio.h>
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
        
        printf("enter data %d: ",i+1);
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

void display(struct node *head){
    
    struct node *temp;
    
    if(head==NULL){
        printf("\nlinked list is empty\n");
        return ;
    }
    
    temp=head;
    
    printf("LINKED LIST: \n");
    
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
    printf("NULL");
    return;
}

void counting(struct node *head){
    
    struct node *temp;
    int ec=0,oc=0,i;
    
    temp=head;
    while(temp != NULL){
        if(temp->data%2==0){
            ec++;
        }
        else{
            oc++;
        }
        temp=temp->next;
    }
    
    printf("\neven count %d= ",ec);
    printf("\nodd count %d= ",oc);
}

int main(){
    struct node *head=NULL;
    
    int choice;
    
    while(1){
    
        printf("-----MENU------\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.counting\n");
        printf("4.exit\n");
        
        printf("enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                
            head=create();
            break;
            
            case 2:
            
            display(head);
            break;
            
            case 3:
            
            counting(head);
            break;
            
            case 4:
            
            printf("\nexit\n");
            return 0;
            
            default:
            
            printf("\nenter valid choice\n");
        }
    }
}

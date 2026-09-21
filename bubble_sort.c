#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[100],n,i,j,temp;
    
    printf("enter no. of elements: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("before sorting:\n ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
    printf("\nafter sorting : \n");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}

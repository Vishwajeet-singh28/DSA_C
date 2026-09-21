#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[100],n,i,j,temp,min;
    
    printf("enter no. of elements: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("before sorting: \n ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    
    printf("after sorting: \n ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}

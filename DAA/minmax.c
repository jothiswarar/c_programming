#include <stdio.h>
void maxmin(int *a,int i,int j,int *max,int *min){
    if(i==j){
        *max=a[i];
        *min=a[j];
    }
    else if(i==j-1){
        if(a[i]>a[j]){
            *max=a[i];
            *min=a[j];
        }
        else{
            *max=a[j];
            *min=a[i];
        }
    }
    else{
        int max1,max2,min1,min2;
        int mid=(i+j)/2;
        maxmin(a,i,mid,&max1,&min1);
        maxmin(a,mid+1,j,&max2,&min2);
        *max=(max2>max1) ? max2 : max1;
        *min=(min2<min1)?min2:min1;

    }
}
void main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    int max,min;
    maxmin(a,0,n-1,&max,&min);
    printf("MAX:%d\nMIN:%d",max,min);
}

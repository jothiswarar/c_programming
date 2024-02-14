#include <stdio.h>
int partition(int *a,int p,int n){
    int i=p,j=n;
    do{
        do{
            i=i+1;
            if(i==n){
                break;
            }
        }while(a[i]<=a[p]);
        do{
            j--;
            if(j==p){
                break;
            }
        }while(a[j]>=a[p]);
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }while(i<j);
    if(i>=j){
        int temp=a[p];
            a[p]=a[j];
            a[j]=temp;
    }
    return j;
}
void quicksort(int *a,int l,int h){
    if(l>=h){
        return ;
    }
    int p=partition(a,l,h+1);
    quicksort(a,l,p-1);
    quicksort(a,p+1,h);
}
int main(){
    int a[]={5,1,3,6,2,9,10,11,0,3};
    quicksort(a,0,9);
    for(int i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
}

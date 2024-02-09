#include <stdio.h>
#include <stdlib.h>
void merge(int *m,int i,int mid,int j){

    int *a=malloc(sizeof(int)*(mid-i+1));
    int *b=malloc(sizeof(int)*(j-mid));
    int k,l;
    for(k=0;k<(mid-i+1);k++){
        a[k]=m[i+k];
    }
    for(l=0;l<(j-mid);l++){
        b[l]=m[mid+1+l];
    }
    int n=i;
    int len1=k,len2=l;
    k=0;l=0;
    while(k<len1 && l<len2){
        if(a[k]<b[l]){
            m[n++]=a[k++];
        }
        else{
            m[n++]=b[l++];
        }
    }
    if(k==len1){
        for(l;l<len2;l++){
            m[n++]=b[l++];
        }
    }
    else{
        for(k;k<len1;k++){
            m[n++]=a[k++];
        }
    }
    //return m;
}
//int a[100];
void mergesort(int i,int j,int *a){
    if(i<j){
        int mid=(i+j)/2;
        mergesort(i,mid,a);
        mergesort(mid+1,j,a);
        merge(a,i,mid,j);
    }
}
void main(){
    int a[]={3,2,7,1,9,4};
    mergesort(0,5,a);
    for(int i=0;i<6;i++){
        printf("%d\t",a[i]);
    }
}
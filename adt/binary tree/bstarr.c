#include <stdio.h>
#include <stdlib.h>
int t[50]={'\0'};
#define n 50
void insert(int a,int i){
    if(i>=n){
        printf("Out of Bound\n");
        return;
    }
    if(t[i]=='\0'){
        t[i]=a;
        return;
    }
    else if(t[i]>a){
        insert(a,2*i +1);

    }
    else if(t[i]<a){
        insert(a,2*i+2);
    }
    else{
        printf("Duplicate\n ");
    }
}
void inorder(int i){
    if(i<n&&t[i]!='\0'){
        inorder(2*i+1);
        printf("%d\t",t[i]);
        inorder(2*i+2);
    }
}
int check(int i){
    return (i<n)&&(t[i]!='\0');
}
int min(int i){
    while(check(2*i+1)){
        i=2*i+1;
    }
    return i;
}
void delete(int a,int i){
    if(i>=n||t[i]=='\0'){
        return;
    }
    if(t[i]>a){
        delete(a,2*i+1);
    }
    else if(t[i]<a){
        delete(a,2*i+2);
    }else{
        int l=2*i+1;
        int r=l+1;
        if(check(l)&&check(r)){
            int temp=min(r);
            t[i]=t[temp];
            delete(t[temp],r);
        }
        else if(check(l)){
            t[i]=t[l];
            delete(t[l],l);
        }
        else if(check(r)){
            t[i]=t[r];
            delete(t[r],l);
        }
        else{
            t[i]='\0';
        }
    }
}
void main(){
    int a[]={10,4,6,7,11,3,2,8,9,27,36,1,5,13};
    int l=sizeof(a)/sizeof(int);
    for(int i=0;i<l;i++){
        insert(a[i],0);
    }
    inorder(0);
    printf("\n");
    delete(27,0);
    inorder(0);
}
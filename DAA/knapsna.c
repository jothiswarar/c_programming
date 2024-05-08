#include <stdio.h>
int max(int i,int j){
    if(i>j){
        return i;
    }
    return j;
}
int knapsnack(int w,int a[],int b[],int n){
    int k[n+1][w+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            if(i==0||j==0){
                k[i][j]=0;
            }
            else if(b[i-1] <= j){
                k[i][j]=max(a[i-1]+k[i-1][j-b[i-1]],k[i-1][j]);
            }
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }
    return k[n][w];
}

void main(){
    int b[]={3,4,6,5};
    int a[]={2,3,1,4};
    int w=7;
    int n=4;
    printf("the profit is %d",knapsnack(w,a,b,n));
}

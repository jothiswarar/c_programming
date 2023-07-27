#include <stdio.h>
#include<stdlib.h>
int *cofactor(int n,int *a,int *i){
   
   
    *i=0;
    for(int j=1;j<=n;j++){
        if((n%j)==0){
            a[*i]=j;
            *i+=1;
        }
    }
 int *b=(int*)realloc(a,(*i)*sizeof(int));
 a=b;
    
    
    

}
int main(){
     int n;
    printf("Enter a positive integer:");
    scanf("%d",&n);
    int *a;int b=0;
    cofactor(n,a,&b);
    

    for(int i=0;i<b;i++){
        printf("%d\n",a[i]);
    }
    free(a);
}
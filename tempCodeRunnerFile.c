#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main(){
    char a[100];
    gets(a);
    int j=0;
    int *b =malloc(100*sizeof(int));
    for(int i=0;a[i]!='\0';i++){
        if(isnum(a[i])){
            b[j]=atoi(a[i]);
            j++;
        }
    }
    a=realloc(b,j);
    for(int i=0;i<j;i++){
        printf("%d\t",a[i]);
    }

}
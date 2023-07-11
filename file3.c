#include <stdio.h>
int main(){
    FILE *p,*a,*b;
    a=fopen("hi.txt","r");
    b=fopen("hi2.txt","r");
    p=fopen("write.txt","w");
    char c;
    while(!feof(a)){
        c=fgetc(a);
        fputc(c,p);
    }
     while(!feof(b)){
        c=fgetc(b);
        fputc(c,p);
    }
    fclose(p);
    fclose(a);
    fclose(b);
}
#include <stdio.h>
int main()
{
    FILE *p;
    p=fopen("hi.txt","r");
    fseek(p,0,SEEK_END);
    printf("File Size:%d Bytes",ftell(p));
}
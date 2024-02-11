#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long int arr[10000];
int n;
void readf(FILE *a){
    unsigned long int buff;int i=0;
    //arr=malloc(10000*sizeof(long int));
    while(!feof(a))//a!=EOF
    {
        fscanf(a,"%ld",&buff);
        arr[i++]=buff;
    }
    n=i;
}
void bubble(){
    int swap;
    for(int i=0;i<n;i++){
        swap=0;
        for(int j=0;j<n-i-1;j++ ){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swap=1;
            }
        }
        if(!swap){
            return;
        }
        
    }
}
int checksorted(FILE *a){
    int t=0;
    unsigned long buff,prev=0;
    fseek(a,0,SEEK_SET);
    while(!feof(a)){
        fscanf(a,"%ld",&buff);
        if(buff <prev){
            return 0;
        }
        prev=buff;
    }
    return 1;
}
int main()
{
    clock_t b;
    b=clock();
    FILE *a=fopen("input.txt","r");
    readf(a);
    clock_t t;
    t=clock();
    bubble();
    t=clock()-t;
    printf("TIME TAKEN IS %f",(((double)t)/CLOCKS_PER_SEC));
    fclose(a);
    a=fopen("out.txt","w+");
    for(int i=0;i<n;i++){
        fprintf(a,"%ld\n",arr[i]);
    }
    if(checksorted((a))){
        printf("\nout.txt is sorted");
    }
    else{
        printf("not sorted");
    }
    fclose(a);

}

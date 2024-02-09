#include <stdio.h>
#include <time.h>
//#include "merge.c"
unsigned long int arr[10000];
int n;
void readf(FILE *a){
    unsigned long int buff;int i=0;
    while(!feof(a))//a!=EOF
    {
        fscanf(a,"%ld",&buff);
        arr[i++]=buff;
    }
    n=i;
}
void bubble(){
    int swapped;
    for(int i=0;i<n;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++ ){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                if(!swapped){
                    swapped=1;
                }
            }
        }
        if(!swapped){
            break;
        }
    }
}
int main()
{
    clock_t b;
    b=clock();
    FILE *a=fopen("sorted.txt","r");
    readf(a);
    clock_t t;
    t=clock();
    //mergesort(0,10000,arr);
    bubble();
    t=clock()-t;
    printf("TIME TAKEN IS %f",(((double)t)/CLOCKS_PER_SEC));
    fclose(a);
    a=fopen("out.txt","w");
    for(int i=0;i<n;i++){
        fprintf(a,"%ld\n",arr[i]);
    }
    fclose(a);

}

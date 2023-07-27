#include <stdio.h>
#include <ctype.h>
int main(){
    
    int n;
    scanf("%d",&n);
    float avg[2][5]={0.0};
    int mark[n][5];
   
    for(int i=0;i<n;i++){
        printf("Enter the marks of %d Student:",i+1);
        for(int j=0;j<5;j++){
            scanf("%d",(*(mark+i)+j));
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            avg[0][i]+=mark[j][i];
        }
        avg[0][i]/=n;
        for(int j=0;j<n;j++){
            
            if(mark[j][i]>(avg[0][i])){
                avg[1][i]++;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("\naverage:%.2f\nNo. od avg count:%d\n",avg[0][i],(int)avg[1][i]);
        
    }
    return 0;
}
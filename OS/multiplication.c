#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define N 1000
int main(){
    pid_t pid=fork();
    int n=1;
    if(pid<-1){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        while(n<N){
            printf("Michael's Turn");
            srand(time(NULL));
            int i= rand()%8 +2;
            n*=i;
            printf("Michael Multiplied:%d * %d = %d",(n/i),i,n);
            if(n>=N){
                printf("Michael Wins the game");
                break;
            }
            sleep(2);
            
        }

    }
    else{
        while(n<N){
            printf("Jhon's Turn");
            srand(time(NULL));
            int i= rand()%8 +2;
            n*=i;
            printf("Jhon Multiplied:%d * %d = %d",(n/i),i,n);
            if(n>=N){
                printf("Jhon Wins the game");
                break;
            }
            sleep(2);
            
        }

    }

}
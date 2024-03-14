#include <stdio.h>
#include <limits.h>
#define n 9
const int max=INT_MAX;
int i;
int graph[9][9] = { { 0, 4, 0, 0, 2, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==0){
                graph[i][j]=max;
            }
        }
    }
}
void intilizepath(int *path,int *b,int a){
    int i=0;
    for(i=0;i<n;i++){
        if(i!=a){
            path[i]=max;
        }
        else{
            path[i]=0;
        }
        b[i]=0;
    }
}
int isallvisited(int *visited){
    int b=1;
    for(i=0;i<n;i++){
        if(!visited[i]){
            b=0;
            break;
        }
    }
    return b;
}

void mindistance(int *a,int *b,int *l){
    int d=max;
    for(i=0;i<n;i++){
        if(d>a[i]&&!b[i]){
            d=a[i];
            *l=i;
        }
    }

}
void findshortest(int *path,int a){
    int visited[n];
    intilizepath(path,visited,a);

    int j,l;
    for(j=0;j<n-1;j++){
        mindistance(path,visited,&l);
        visited[l]=1;
        for(i=0;i<n;i++){
            if(!visited[i]&&graph[l][i]!=max){
                int j=path[l]+graph[l][i];
                if(j<path[i]){
                    path[i]=j;
                }
            }
        }
    }
}
int main(){
    int path[n];
    int s=0;
    init();
    findshortest(path,s);
    for(i=0;i<n;i++){
        printf("%d:%d=%d\n",s,i,path[i]);
    }
}


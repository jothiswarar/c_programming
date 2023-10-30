#include <stdio.h>
#include <stdlib.h>
void heapify(int *a, int i, int n)
{

    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (i >= n)
    {
        return;
    }
    int large = i;
    if (l < n && a[large] < a[l])
    {
        large = l;
    }
    if (r < n && a[large] < a[r])
    {
        large = r;
    }
    if (large != i)
    {
        int b = a[i];
        a[i] = a[large];
        a[large] = b;
        heapify(a, large, n);
    }
}
void main(int argc,char** argv)
{
    int *a=malloc(sizeof(int)*(argc-1));

    for(int i=1;i<argc;i++){
        a[i-1]=atoi(argv[i]);
    }
    int n= argc-1;
   
    for (int i = (n/2)-1; i >=0; i--)
    {
        heapify(a, i, n);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int b = a[0];
        a[0] = a[i];
        a[i] = b;
        heapify(a, 0, i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
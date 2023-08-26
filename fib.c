#include <stdio.h>
#include <stdlib.h>
void fib(int *a, int n)
{
    for (int i = 2; i < n; i++)
    {
        *(a + i) = *(a + i - 1) + *(a + i - 2);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    a[0] = 0;
    if (n > 1)
    {
        a[1] = 1;
        fib(a, n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",*(a+i));
    }
}
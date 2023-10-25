#include "stack.c"
#include <string.h>
#include <ctype.h>
int main( char **args, int argv)
{

    char c[250];
    printf("Enter the postfix notation:");
    gets(c);
    int i = 1;
    while (i < argv)
    {
        char *a= args[i];
        i++;
        if (isdigit(a[0]))
        {

            int b = atoi(a);
            push(b);
        }
        else
        {
            char d = a[0];
            switch (d)
            {
            case '+':
            {
                int b = pop() + pop();
                push(b);
                break;
            }
            case '-':
            {
                int a = pop();
                int d = pop();
                int b = d - a;
                push(b);
                break;
            }
            case '*':
            {
                int b = pop() * pop();
                push(b);
                break;
            }
            case '/':
            {
                int a = pop();
                int d = pop();
                int b = d / a;
                push(b);
                break;
            }
            }
        }
    }
    printf("ANS:%d", pop());
    return 0;
}
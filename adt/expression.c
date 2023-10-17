#include "stack.c"
#include <string.h>
#include <ctype.h>
int main()
{

    do
    {
        char c[20];
        printf("Enter the postfix notation(enter _ to answer):");
        scanf("%s", c);
        if (isdigit(c[0]))
        {

            int b = atoi(c);
            push(b);
        }
        else
        {
            char d = c[0];
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
            default:
            {
                printf("ANS:%d", pop());
                return 0;
            }
            }
        }

    } while (1);
}
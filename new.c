#include "menu.c"
#include "insert.c"
#include "delete.c"
int main()
{
    int c;
   
    input(&c);
    int i;
    switch (c)
    {
    case 1:
    {

        printf("Enter the Element:");
        scanf("%d", &i);
        insertbegin(i);
        break;
    }
    case 2:
    {
        printf("Enter the Element:");
        scanf("%d", &i);
        insertatend(i);
        break;
    }
    case 3:
    {
        printf("Enter the Element:");
        scanf("%d", &i);
        int a;
        printf("Enter the Position:");
        scanf("%d", &a);
        insert(i, a);
        break;
    }
    case 4:
    {

        deleteatbegin();
        break;
    }
    case 5:
    {
        deleteatend();
        break;
    }
    case 6:
    {
        printf("Enter the Element to be Deleted:");
        scanf("%d", &i);
        delete (i);
        break;
    }
    case 7:
    {
        lengthp();
        break;
    }
    case 8:
    {
        
        search();
        break;
    }
    case 9:
    {
        display();
        break;
    }
    default:
    {
        printf("Enter a valid input.\n");
        main();
        
        return 0;
    }
    }
    printf("To continue enter 1 and To exit enter 0\n");
    scanf("%d", &c);
    if (c == 0)
    {
        
        
        return 0;
    }
    else
    {
        main();
        return 0;
    }
}
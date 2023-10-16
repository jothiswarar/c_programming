#include "stack.c"
//#include "stackarr.c"
void main(){
         int n;
    do{
        printf("Enter choice\n1.push\n2.pop\n3.exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                {
            int a;
            printf("enter the element:");
            scanf("%d",&a);
            push(a);
            printf("pushed sucessfully.\n");
            break;
            }
            case 2:
                {
                    int i=pop();
                    if(i!=-1)
                        printf("Recent elment:%d\n",i);
                    break;
                }

            default:
                {
                    return 0;
                }
        }
    }while(1);
}
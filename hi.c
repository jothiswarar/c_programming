#include <stdio.h>

struct employee{
    int empy_id;
    char name[25];
    char address[25];
    char phone_no[10];
    int basic;
    int hra;
    int da;
    int sa;
    int incentives;
    int salary;
};
int main(){
    int n;
    scanf("%d",&n);
    struct employee member[n],*a;
    for(int i=0;i<n;i++){
        a=&member[i];
        printf("Enter Employee's Name:");
        scanf("%s",a->name);
        printf("Enter Employee's Id:");
        scanf("%d",&(a->empy_id));
        printf("Enter Employee's address:");
        scanf("%s",a->address);
        printf("Enter Employee's PhoneNo:");
        scanf("%s",a->phone_no);
        printf("Enter Basic Salary:");
        scanf("%d",&(a->basic));
        printf("Enter Hra:");
        scanf("%d",&(a->hra));
        printf("Enter Da:");
        scanf("%d",&(a->da));
        printf("Enter Sa:");
        scanf("%d",&(a->sa));
        if(a->sa != 0){
            printf("Enter Incentives:");
            scanf("%d",&(a->incentives));
            a->salary=(a->basic)+(a->da)+(a->hra)+(a->sa)+(a->incentives);
        }
        a->salary=(a->basic)+(a->da)+(a->hra);
    }
    for(int i=0;i<n;i++){
        a=&member[i];
        printf("\nEmployee No.%d Details:\n",i+1);
        printf("\nEmployee's Id:%d",a->empy_id);
        printf("\nEmployee's name:%s",a->name);
        printf("\nEmployee's Address:%s",a->address);
        printf("\nEmployee's Phone No:%s",a->phone_no);
        printf("\nEmployee's salary:%d\n",a->salary);
    }
}
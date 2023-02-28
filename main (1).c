#include<stdio.h>
#include<stdlib.h>
#define size 10
typedef struct transaction
{
    int T_ID;
    char T_DATE[10];
    float amount;
    char T_TYPE[10];
}TXN;
int main()
{
    TXN stack[size],txn;
    int stack_empty(int top);
    void push(TXN txn,int *top,TXN stack[]);
    void display(int top,TXN stack[]);
    int ch;
    int top=-1;
    for(;;)
    {
        printf("ENTER \n1.TO ENTER DETAILS\n2.TO DISPLAY MINI STATEMENT\n3.TO EXIT\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    printf("ENTER TRANSACTION DETAILS\n");
                    printf("ENTER TRANSACTION ID:");
                    scanf("%d",&txn.T_ID);
                    printf("ENTER DATE OF TRANSACTION IN dd/mm/yyyy:");
                    scanf("%s",txn.T_DATE);
                    printf("ENTER TRANSACTION TYPE:");
                    scanf("%s",txn.T_TYPE);
                    printf("ENTER THE AMOUNT:");
                    scanf("%f",&txn.amount);
                    push(txn,&top,stack);
                    break;
            case 2:if(stack_empty(top))
                    {
                        printf("NO TRANSACTIONS YET!!\n");
                    }
                    else
                    {
                        display(top,stack);
                    }
                    break;
            case 3:exit(0);
            default:printf("ENTER 1,2 OR 3");
        }
    }
}
int stack_empty(int top)
{
    if(top==-1)
    return 1;
    return 0;
}
void push(TXN txn,int *top,TXN stack[])
{
    stack[++(*top)]=txn;
}
void display(int top,TXN stack[])
{
    printf("****************************************************MINI STATEMENT****************************************************************\n");
    if(top>=5)
    {
        for(int i=top;i>top-5;i--)
        {
            printf("SERIAL NO:\tTRANSACTION ID:\tTRANSACTION DATE:\tAMOUNT\tTRANSACTION TYPE:\t\n");
            printf("%d\t\t%d\t\t%s\t\t%f\t\t%s\t",i+1,(stack+i)->T_ID,(stack+i)->T_DATE,(stack+i)->amount,(stack+i)->T_TYPE);
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    else
    {
        for(int i=top;i>=0;i--)
        { printf("SERIAL NO:\tTRANSACTION ID:\tTRANSACTION DATE:\tAMOUNT\tTRANSACTION TYPE:\t\n");
            printf("%d\t\t%d\t\t%s\t\t%f\t\t\t%s\t",i+1,(stack+i)->T_ID,(stack+i)->T_DATE,(stack+i)->amount,(stack+i)->T_TYPE);
            printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    printf("**********************************************************************************************************************************\n");
}




#include <stdio.h>


int mutex=1;
int n=5;
int full=0;
int empty=5;
// int buffer[n];

void wait()
{
    --mutex;
}
void signal()
{
    ++mutex;
}


void produce()
{
    if(mutex==0)
    {
        printf("Locked");
    }
    else
    {
        if (full==n)
        {
            printf("Buffer is full\n");
        }
        wait();
        full+=1;
        empty-=1;
        printf("The item is produced\n");

    }
    signal();
}

void consume()
{

    if(mutex==0)
    {
        printf("Locked\n");
    }
    else
    {
        if(empty==n)
        {
            printf("Buffer is empty\n");
        }
        wait();
        full-=1;
        empty+=1;
        printf("The item is consumed\n");

    }
    signal();

}
int main()
{
    int choice;
    while(1)
    {
        
        printf("Enter 0:prodecer\n1:consumer");
                      
        scanf("%d",&choice);
        if (choice==0)
        {
            produce();
        }
        if(choice==1){
            consume();
        }
    }


    
}

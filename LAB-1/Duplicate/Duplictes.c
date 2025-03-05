#include <stdio.h>
int main()
{
    int data[5];
    
    int count=0;
    
    printf("Enter");
    
    for(int i=0;i<5;i++)
    {
        scanf("%d",&data[i]);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(data[i]==data[j])
            {
                count+=1;
            }
        }
        
    }
    printf("count is %d",count);
}
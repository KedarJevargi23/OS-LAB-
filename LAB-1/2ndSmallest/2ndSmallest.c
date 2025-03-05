#include <stdio.h>
int main()
{
    int data[] = {25, 50, 75, 100};
    int smallest = data[0];
    int ssmallest = 1000; 
    
    for (int i = 0; i < 4; i++)
    {
        if (data[i] < smallest)
        {
            smallest = data[i];
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (data[i] < ssmallest && data[i] > smallest)
        {
            ssmallest = data[i];
        }
    }
    
    printf("%d", ssmallest);
    
    return 0;
}
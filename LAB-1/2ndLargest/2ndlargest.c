#include <stdio.h>
int main()
{
    int data[] = {25, 50, 75, 100};
    int largest = 0;
    int slargest = 0;
    
    for (int i = 0; i < 4; i++)
    {
        if (data[i] > largest)
        {
            largest = data[i];
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (data[i] > slargest && data[i] != largest)
        {
            slargest = data[i];
        }
    }
    
    printf("%d", slargest);
    
    return 0;
}
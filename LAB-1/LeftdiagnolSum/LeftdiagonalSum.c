#include <stdio.h>
int main()
{
    int row;
    int column;
    printf("Enter the row");
    scanf("%d",&row);
    printf("Enter the column");
    scanf("%d",&column);
    printf("Enter the values");
    int martix[row][column];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            scanf("%d",&martix[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(i==j)
            {
                sum+=martix[i][j];
            }
            
        }
    }
    printf("The sum is %d",sum);
}
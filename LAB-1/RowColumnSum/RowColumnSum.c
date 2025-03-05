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
    
   
    for(int i=0;i<row;i++)
    
    {
        int rowsum=0;
        for(int j=0;j<column;j++)
        {
            rowsum+=martix[i][j];
        }
        printf("row %d sum is %d \n",i,rowsum);
    }
    for(int i=0;i<row;i++)
    
    {
        int columnsum=0;
        for(int j=0;j<column;j++)
        {
            columnsum+=martix[j][i];
        }
        printf("column %d sum is %d \n",i,columnsum);
    }
}
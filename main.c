
1
#include <stdio.h>

int main()
{
    int data[] = {25, 50, 75, 100};
    int largest=0;
    int slargest=0;
    for (int i=0;i<4;i++)
    {
        if(data[i]>largest)
        {
            largest=data[i];
        }
        
    }
    for (int i=0;i<4;i++)
    {
        if(data[i]>slargest && data[i]!=largest)
        {
            slargest=data[i];
        }
    }
    printf("%d",slargest);
}

// ---------------------------------------------------
// 2 
// #include <stdio.h>

// int main()
// {
//     int row;
//     int column;
//     printf("Enter the row");
//     scanf("%d",&row);
//     printf("Enter the column");
//     scanf("%d",&column);
//     printf("Enter the values");
//     int martix[row][column];
//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<column;j++)
//         {
//             scanf("%d",&martix[i][j]);
//         }
//     }

//     int sum=0;

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<column;j++)
//         {
//             if(i==j)
//             {
//                 sum+=martix[i][j];

//             }
            
//         }
//     }

//     printf("The sum is %d",sum);

// }
// -------------------------------------------

// 3.

// #include <stdio.h>

// int main()
// {
//     int row;
//     int column;
//     printf("Enter the row");
//     scanf("%d",&row);
//     printf("Enter the column");
//     scanf("%d",&column);
//     printf("Enter the values");
//     int martix[row][column];
//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<column;j++)
//         {
//             scanf("%d",&martix[i][j]);
//         }
//     }

    
   
//     for(int i=0;i<row;i++)
    
//     {
//         int rowsum=0;
//         for(int j=0;j<column;j++)
//         {
//             rowsum+=martix[i][j];
//         }
//         printf("row %d sum is %d \n",i,rowsum);
//     }


//     for(int i=0;i<row;i++)
    
//     {
//         int columnsum=0;
//         for(int j=0;j<column;j++)
//         {
//             columnsum+=martix[j][i];
//         }
//         printf("column %d sum is %d \n",i,columnsum);
//     }
// }
// // ------------------------------------

// // 4. 




// #include <stdio.h>

// int main()
// {
   
//     int data[5];
    
//     int count=0;
    

//     printf("Enter");
    
//     for(int i=0;i<5;i++)
//     {
//         scanf("%d",&data[i]);
//     }

//     for(int i=0;i<5;i++)
//     {
//         for(int j=i+1;j<5;j++)
//         {
//             if(data[i]==data[j])
//             {
//                 count+=1;
//             }
//         }
        
//     }

//     printf("count is %d",count);

// }



// 1
// #include <stdio.h>

// int main()
// {
//     int data[] = {25, 50, 75, 100};
//     int smallest=data[i];
//     int ssmallest=data[i];
//     for (int i=0;i<4;i++)
//     {
//         if(data[i]<smallest)
//         {
//             smallest=data[i];
//         }
        
//     }
//     for (int i=0;i<4;i++)
//     {
//         if(data[i]<ssmallest && data[i]!=smallest)
//         {
//             ssmallest=data[i];
//         }
//     }
//     printf("%d",ssmallest);
// }
#include <stdio.h>
void main()

{

int pos,n,num,i;

printf("enter the size of array :");

scanf("%d",&n);

int a[n];

printf("enter the elements : ");

for(i=0;i<n;i++)

{

scanf("%d",&a[i]);

}

printf("enter position from which element should be deleted : ");

scanf("%d",&pos);

for(i=pos;i<n-1;i++)

{

a[i]=a[i+1];

}

n--;

printf("\n The array after deletion is : ");

for(i=0;i<=n-1;i++)

printf(" %d \t",a[i]);

}




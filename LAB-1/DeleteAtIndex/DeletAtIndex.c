#include <stdio.h>
void main()
{
    int pos, n, num, i;
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
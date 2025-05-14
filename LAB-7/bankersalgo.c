#include<stdio.h>
#include<stdbool.h>

void main()
{
    int n, r;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int finish[n];
    int safe[n];
    int k = 0;
    printf("Enter number of resources: ");
    scanf("%d", &r);
    int alloc[n][r], max[n][r], need[n][r], available[r];


    printf("Enter the allocation and max matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (int i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {}
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    while (count < n) {
        bool allocated = false;

        for (int i = 0; i < n; i++) {
       
            if (finish[i] == 0) {
                bool canAllocate = true;
                
                for (int j = 0; j < r; j++) {1
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

               
                if (canAllocate) {
                    printf("Process %d is granted\n", i);
                    for (int j = 0; j < r; j++) {
                        available[j] += alloc[i][j];  
                    }
                    safe[k++] = i;  
                    finish[i] = 1; 
                    allocated = true;
                    count++;
                    break;
                }
            }
        }

        if (!allocated) {
            printf("System is in a deadlock state.\n");
            break;
        }
    }

   
    if (count == n) {
        printf("Safe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", safe[i]);
        }
        printf("\n");
    }
}

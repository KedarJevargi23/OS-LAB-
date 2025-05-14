#include<stdio.h>
int max=100;
int arr[100];
int available = Max;

void allocate(int numblocks, int fnum){
    if(numblocks>available) {
        printf("Can not allocate memory contiguosly\n");
        return;
    }

    int idx;
    for(int i=0; i<max; i++){
        if(arr[i]==0){
            idx = i;
            break;
        }
    }

    for(int i= 1; i<=numblocks; i++){
        arr[idx++] = fnum;
        available--;
    }
    printf("Memory allocated successfully:\n");
}

void deallocate(int fnum){
    int flag = 0;
    int idx;

    for(int i=0; i<max; i++){
        if(arr[i]==fnum){
            flag = 1; 
            break;
        }
    }
    
    if(flag==0){
        printf("Memory can't be deallocated as the file is not allocated:\n");
        return;
    }

    for(int i=0; i<max; i++){
        if(arr[i]==fnum){
            idx = i;
            break;
        }
    }

    while(arr[idx]==fnum){
        arr[idx++] = 0;
        available++;
    }
    printf("Successfully deallocated memory:\n");
}

void main(){
    int fnum,choice,numblocks;
    printf("1:Allocate\n 2:Deallocate\n 3:Exit\n");
    while(1){
        printf("Enter your choice here:\n");
        scanf("%d", & choice);
        if(choice==1){
            printf("Enter the file number:\n");
            scanf("%d", &fnum);
            printf("Enter the number of blocks to allocate:\n");
            scanf("%d", &numblocks);
            allocate(numblocks,fnum);
        }

        else if(choice==2){
            printf("Enter the file number:\n");
            scanf("%d", &fnum);
            deallocate(fnum);
        }
        else break;
    }
}

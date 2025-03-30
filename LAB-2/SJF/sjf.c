#include<stdio.h>

    int n, i, j, pos, temp, bt[20], wt[20], tat[20], process[20], total=0;

    float Tavg=0, Wavg=0;



int SJF()

{
    for(i=0;i<n;i++)
    {
        pos=i;

        for(j=i+1;j<n;j++)

        {
            if(bt[j]<bt[pos])

                pos=j;
        }

        temp=bt[i];

        bt[i]=bt[pos];

        bt[pos]=temp;


        temp=process[i];

        process[i]=process[pos];

        process[pos]=temp;

    }

        wt[0]=0;

    for(i=1;i<n;i++)

    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }

    Wavg=(float)total/n;
    total=0;

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");


    for(i=0;i<n;i++)

    {
        tat[i]=bt[i]+wt[i];

        total+=tat[i];

        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",process[i],bt[i],wt[i],tat[i]);

    }

    Tavg=(float)total/n;

    printf("\n\nAverage Waiting Time=%f",Wavg);

    printf("\nAverage Turnaround Time=%f\n",Tavg);

}

int main()

{

    printf("Enter the total number of processes:");

    scanf("%d",&n);



    printf("\nEnter Burst Time:\n");

    for(i=0;i<n;i++)

    {
        printf("P[%d]:",i+1);

        scanf("%d",&bt[i]);

        process[i]=i+1;

    }

        printf("\nSJF Scheduling\n");

        SJF();

    return 0;

}

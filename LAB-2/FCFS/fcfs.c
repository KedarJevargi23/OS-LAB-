#include<stdio.h>

    int n, i, j, pos, temp, choice, bt[20], wt[20], tat[20], process[20], total=0;

    float Tavg=0, Wavg=0;



int FCFS()

{

    wt[0]=0;

    for(i=1;i<n;i++)

    {

        wt[i]=0;

        for(j=0;j<i;j++)

            wt[i]+=bt[j];

    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

    for(i=0;i<n;i++)

    {

        tat[i]=bt[i]+wt[i];

        Wavg+=wt[i];

        Tavg+=tat[i];

        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,bt[i],wt[i],tat[i]);

    }



    Wavg =(float)(Wavg)/(float)i;

    Tavg=(float)(Tavg)/(float)i;

    printf("\nAverage Waiting Time:%.2f",Wavg);

    printf("\nAverage Turnaround Time:%.2f\n",Tavg);

    return 0;

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


        printf("\nFCFS Scheduling\n");

        FCFS();


    return 0;

}
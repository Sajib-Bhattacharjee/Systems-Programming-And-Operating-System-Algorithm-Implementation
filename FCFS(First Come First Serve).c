#include<stdio.h>
#include<conio.h>

int main()
{

    int p[100],bt[100],wt[100],tat[100];
    int i,n;
    float total_wt,total_tat;

    printf("\n\n \t\t\t First Come First Serve Algorithm \n\n");
    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("Enter the process sequence: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
    }

     //Calculating waiting time and completion time...
    for(i=0; i<n;i++)
    {
        wt[0]=0;
        tat[0]=bt[0];
        wt[i+1] = wt[i]+bt[i];
        tat[i+1] = wt[i+1]+bt[i+1];

        total_tat= total_tat + tat[i];
        total_wt=total_wt + wt[i];
    }

    //Calculation total waiting time and total turnaround time..


    printf("\n\n Solution: \n");
    printf("Process Burst_Time Waiting_Time Turnaround_Time \n");
    for(i=0; i<n; i++)
    {
        printf("P%d\t  %d\t\t  %d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }

    //Printing average waiting time and average turnaround time...
    printf("\n\nAverage Waiting Time: %f\n",total_wt/n);
    printf("Average Turnaround Time: %f\n",total_tat/n);



    getch();
}

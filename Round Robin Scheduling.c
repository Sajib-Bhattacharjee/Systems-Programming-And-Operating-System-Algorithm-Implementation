

#include<stdio.h>
#include<conio.h>

int main()
{

    int p[100],bt[100],wt[100],tat[100],rem_bt[100];
    int i,n,temp,tq,sum=0,count;
    float total_wt,total_tat;

    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter process sequence: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter Burst Time: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }

    printf("Enter Time Quantime: ");
    scanf("%d",&tq);
    while(1)
    {
        for(count=0,i=0; i<n; i++)
        {
            temp = tq;
            if(rem_bt[i]==0)
            {
                count ++ ;
                continue;
            }
            if(rem_bt[i]>tq)
            {
                rem_bt[i] = rem_bt[i] - tq;
            }
            else if(rem_bt[i] <= tq)
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sum = sum + temp;
            tat[i] = sum;
        }
        if(count == n)
        {
            break;
        }
    }

    for(i=0; i<n; i++)
    {
       wt[i]=tat[i]-bt[i];

       total_wt = total_wt + wt[i];
       total_tat = total_tat + tat[i];

    }

    printf("Proces BurstTime WaitingTime TurnaroundTime\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }

     printf("AVG_wt: %f\n",total_wt/n);
     printf("AVG_tat: %f\n",total_tat/n);


    getch();
}

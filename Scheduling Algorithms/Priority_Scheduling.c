#include<stdio.h>

int main()
{
    int BT[10],pr[10],wt[10],p[10],process,i,j,temp,position;
    double Avg_WT,WT;
    printf("Enter number of process:\n");
    scanf("%d",&process);
    for(i=0;i<process;i++)
    {
        printf("Enter Burst time for process: P%d\n",i+1);
        scanf("%d",&BT[i]);
        printf("Enter priority for process: P%d\n",i+1);
        scanf("%d",&pr[i]);
    }

    for(i=0;i<process;i++)
    {
       position=i;
       for(j=i+1;j<process;j++)
       {
           if(pr[j]<pr[position])
           {
               position=j;
           }
       }
        temp=pr[i];
        pr[i]=pr[position];
        pr[position]=temp;

        temp=BT[i];
        BT[i]=BT[position];
        BT[position]=temp;

        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }

    for(i=1;i<process;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]+=BT[j];
        }
        WT+=wt[i];
    }
    Avg_WT=WT/process;
    printf("Average Waiting time is: %lf",Avg_WT);
    return 0;
}

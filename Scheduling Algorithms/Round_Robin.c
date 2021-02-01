#include<stdio.h>
int main()
{
    int process,BT[10],wt[10],arrival[10],rt[10],quantum,i,j=0,remain=0,temp;
    double avgWT,WT;
    printf("Enter Number of process:\n");
    scanf("%d",&process);
    printf("Enter number of Quantum:\n");
    scanf("%d",&quantum);
    for(i=0;i<process;i++)
    {
        printf("Enter burst time for process: P%d\n",i+1);
        scanf("%d",&BT[i]);
        rt[i]=BT[i];
    }
    while(1)
    {
        for(i=0,j=0;i<process;i++)
        {
            temp=quantum;
            if(rt[i]==0)
            {
                j++;
                continue;
            }
            if(rt[i]>quantum)
            rt[i]=rt[i]-quantum;
            else
            if(rt[i]>=0)
            {
                temp=rt[i];
                rt[i]=0;
            }
            remain=remain+temp;
            arrival[i]=remain;
        }
        if(process==j)
        break;
    }
        for(i=0;i<process;i++)
        {
            wt[i]=arrival[i]-BT[i];
            WT=WT+wt[i];
        }
    avgWT=WT/process;
    printf("Average Waiting Time is: %lf",avgWT);
    return 0;
}

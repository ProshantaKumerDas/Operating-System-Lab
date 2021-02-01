#include<stdio.h>

int main()
{
    int process,arT[10],BT[10],temp[10],finish,i,j;
    int count=0,small;
    double avgWT,WT;
    printf("Enter Number of process:\n");
    scanf("%d",&process);

    for(i=0;i<process;i++)
    {
        printf("Enter arrival time for process: P%d\n",i+1);
        scanf("%d",&arT[i]);
        printf("Enter burst time for process: P%d\n",i+1);
        scanf("%d",&BT[i]);
        temp[i]=BT[i];
    }
    BT[9]=100000;
    for(j=0;count!=process;j++)
    {
        small=9;
        for(i=0;i<process;i++)
        {
            if(arT[i]<=j && BT[i]<BT[small] && BT[i]>0)
            {
                small=i;
            }
        }
        BT[small]--;
        if(BT[small]==0)
        {
            count++;
            finish=j+1;
            WT=WT+finish-arT[small]-temp[small];
        }
    }
    avgWT=WT/process;
    printf("Average Waiting Time = %lf",avgWT);

    return 0;
}

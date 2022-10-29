#include <stdio.h>

int main()
{
	int n,i,tottat=0,totwt=0,ts,gtime=0,cpyn;
	printf("Enter the number of Processes: ");
	scanf("%d",&n);
	cpyn = n;
	int p[n],bt[n],wt[n],tat[n],remain[n];
	float avgtat=0,avgwt=0;
	for(i=0;i<n;i++)
	{
		printf("Burst time of P %d: ",i);
		scanf("%d",&bt[i]);
		p[i]=i;
		remain[i] = bt[i];
	}
	printf("Enter the time slice: ");
	scanf("%d",&ts);
	for(i=0;cpyn!=0;i=(i+1)%n)
	{
		if((remain[i]<=ts) && (remain[i]>0))
		{
			gtime += remain[i];
			remain[i] = 0;
			cpyn --;
			tat[i] = gtime;
			wt[i] = tat[i] - bt[i];
			tottat+=tat[i];
			totwt+=wt[i];
		}
		else if (remain[i]>0)
		{
			gtime+=ts;
			remain[i] -= ts;
		}
	}
	avgwt = (float)totwt/n;
	avgtat = (float)tottat/n;
	printf("Process\tBT\tTAT\tWT\t\n");
	for(i=0;i<n;i++)
		printf("%d \t %d \t %d \t %d \n",p[i],bt[i],tat[i],wt[i]);
	printf("AVG tat = %f",avgtat);
	printf("\nAVG wt = %f",avgwt);
	return 0;
}

#include <stdio.h>

int main()
{
	int n,i;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int p[n],bt[n],tat[n],wt[n],tottat=0,totwt=0;
	float avgtat,avgwt;
	for(i=0;i<n;i++)
	{
		printf("Burst time of P %d: ",i);
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			tat[i]=bt[i];
		else
			tat[i] = tat[i-1] + bt[i];
		tottat+=tat[i];
		wt[i] = tat[i] - bt[i];
		totwt+=wt[i];
	}
	printf("Process\tBT\tTAT\tWT\t\n");
	for(i=0;i<n;i++)
		printf("%d \t %d \t %d \t %d \n",p[i],bt[i],tat[i],wt[i]);
	avgtat = (float)tottat/n;
	avgwt = (float)totwt/n;
	printf("AVG tat = %f",avgtat);
	printf("\nAVG wt = %f",avgwt);
	return 0;
}

#include <stdio.h>

int main()
{
	int n,i,j,temp,tottat=0,totwt=0;
	printf("Enter the number of Processes: ");
	scanf("%d",&n);
	int p[n],bt[n],wt[n],tat[n],pri[n];
	float avgtat=0,avgwt=0;
	for(i=0;i<n;i++)
	{
		printf("Burst time of P %d: ",i);
		scanf("%d",&bt[i]);
		printf("Priority of P %d: ",i);
		scanf("%d",&pri[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(pri[j]>pri[j+1])
			{
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				temp = pri[j];
				pri[j] = pri[j+1];
				pri[j+1] = temp;
				
			}
		}
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
	printf("Process\tPriority BT\tTAT\tWT\n");
	for(i=0;i<n;i++)
		printf("%d \t %d \t %d \t %d \t %d \n",p[i],pri[i],bt[i],tat[i],wt[i]);
	avgtat = (float)tottat/n;
	avgwt = (float)totwt/n;
	printf("AVG tat = %f",avgtat);
	printf("\nAVG wt = %f",avgwt);
	return 0;
}

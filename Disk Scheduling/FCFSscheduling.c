// FCFS Disk Scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inihead, n, totheadmom= 0, i;
    printf("Enter the no. of Requests: ");
    scanf("%d", &n);
    
    int rq[n];
    printf("Enter the Request sequence:\n");
    for(i= 0; i< n; i++)
        scanf("%d", &rq[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &inihead);

    for(i= 0; i< n; i++)
    {
        totheadmom += abs(rq[i]- inihead);
        inihead= rq[i];
    }
    printf("Total head moment = %d", totheadmom);
    return 0;
}

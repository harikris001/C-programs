// First fit memory allocation

#include<stdio.h>

int main()
{
    int prc, blk, i, j, bstIdx;
    printf("Enter the no. of process: ");
    scanf("%d", &prc);
    printf("Enter the no. of blocks: ");
    scanf("%d", &blk);
    int p[prc], b[blk], alloc[prc];
    printf("Enter the process sizes:\n");
    for(i= 0; i< prc; i++)
        scanf("%d", &p[i]);
    printf("Enter the block sizes:\n");
    for(i= 0; i< blk; i++)
        scanf("%d", &b[i]);

    // alloc[i] or same as the ith process = which block the process is allocated
    // initially no blocks are allocated to any process
    for(i= 0; i< prc; i++)
        alloc[i]= -1;

    for(i= 0; i< prc; i++)
    {
        // bstIdx holds the suitable block size index for each process. This value is then copied to alloc[i]
        bstIdx= -1;
        for(j= 0; j< blk; j++)
        {
            if(b[j]>= p[i])
            {
                bstIdx= j;
                break;
            }
        }
        // after we find the best index, we have to reduce the block size of the bstIdx
        if(bstIdx != -1)
        {
            alloc[i]= bstIdx;
            b[bstIdx] -= p[i];
        }
    }

    printf("Process no.\tProcess size\tAllocated block no.\n");
    for(i= 0; i< prc; i++)
    {
        printf("%d\t\t%d\t\t", i, p[i]);
        if(alloc[i] != -1)
            printf("%d", alloc[i]);
        else
            printf("Not allocated");
        printf("\n");
    }
    return 0;
}

// FIFO

#include<stdio.h>
int main()
{
    int np, nf, i, j, pagefault= 0, f_count= 0;
    printf("Enter the no. of pages requested by the CPU: ");
    scanf("%d", &np);
    printf("Enter the total number of frames in memory: ");
    scanf("%d", &nf);

    int p[np], f[nf];
    printf("Enter the page numbers requested: \n");
    for(i= 0; i< np; i++)
        scanf("%d", &p[i]);

    // initially all the frames are empty
    for(i= 0; i< nf; i++)
        f[i]= -1;
    
    printf("Frame 1\tFrame 2\tFrame 3\n");
    for(i= 0; i< np; i++)
    {
        for(j= 0; j< nf; j++)
        {
            // This is the Hit condition
            if(p[i] == f[j])
                break;
        }        
        // suppose if we donot find a hit condition after looping the frame array completely
        // it means that this is a Miss condition
        // so we have to increase the pagefault and store the page number to the frames array
        if(j == nf)
        {
            pagefault++;
            f[f_count]= p[i];
            f_count= (f_count+ 1)% nf;
        }
        // printing frames
        for(j= 0; j< nf; j++)
            printf("%d\t", f[j]);
        printf("\n");
    }
    printf("Total page faults = %d", pagefault);
    return 0;
}

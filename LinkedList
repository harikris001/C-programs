#include <stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    struct node
    {
        int data;
        struct node*next;
    };
    struct node*head,*new,*temp1,*temp2;
    head = 0;
    while(1)
    {
        printf("\nEnter the choice:\n");
        printf("\t1.new entry\n\t2.print\n\t3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                new = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d",&new->data);
                new->next=0;
                if(head==0)
                {
                 head = new;
                 temp1 = new;
                }
                else
                {
                    temp1->next=new;
                    temp1 = new;
                }
                break;
            }
            case 2:
            {
                temp2 = head;
                while (temp2!=0)
                {
                    printf("%d\t",temp2->data);
                    temp2 =temp2 ->next;
                }
                break;
            }
            case 3:
            exit(1);
            default :
            printf("Enter a correct choice!!");
        }
    }
    return 0;
}

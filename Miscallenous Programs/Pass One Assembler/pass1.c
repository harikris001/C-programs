#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *f1,*f2,*f3;
	int lc,sa,opl,o,len,x;
	char ml[20],la[20],op[20],otp[20];
	f1 = fopen("input.txt","r");
	f3 = fopen("symtab.txt","w");
	f2 = fopen("optab.txt","r");
	//opl = sa;

	while((fscanf(f1,"%s %s %s",la,ml,op))!=EOF)
	{
		if(strcmp(la,"**")==0)
		{
			if(strcmp(ml,"START") == 0)
			{
				sa = atoi(op);
				lc = sa;
				printf("\n%s %s %s",la,ml,op);
				
			}
			else
			{
				rewind(f2);
				x = 0;
			
				
				while((fscanf(f2,"%s %d",otp,&o))!= EOF)
				{
					if(strcmp(ml,otp)==0)
					{
						x =1;
					}
					fscanf(f2,"%s %d",otp,&o);
				}
				if(x == 1)
				{
					printf("\n%d %s %s",lc,ml,op);
					lc += 3;
				}
			}
		}
	else{
				if(strcmp(ml,"WORD") == 0)
				{
					fprintf(f3,"%d %s\n",lc,la);
					printf("\n%d %s %s %s",lc,la,ml,op);
					lc=lc+3;
				}
				else if (strcmp(ml,"RESW") == 0)	
				{
					fprintf(f3,"%d %s\n",lc,la);
					printf("\n%d %s %s %d",lc,la,ml,opl);
					opl = atoi(op);
					lc = lc+(3*opl);
				}
				else if(strcmp(ml,"BYTE") == 0)
				{
					fprintf(f3,"%d %s\n",lc,la);
					printf("\n%d %s %s %d",lc,la,ml,opl);
					if(op[0] == 'X')
					lc=lc+1;
					else
					{
						len = strlen(op)-2;
						lc = lc+len;
					}
				}
				else if(strcmp(ml,"RESB") == 0)
				{
					fprintf(f3,"%d %s\n",lc,op);
					printf("\n%d %s %s %d",lc,la,ml,opl);
					opl = atoi(op);
					lc = lc+ opl;
				}
				else
				{
					fprintf(f3,"%d %s\n",lc,op);
					printf("\n%d %s %s %d",lc,la,ml,opl);
					opl = atoi(op);
					lc = lc+ opl;
				}
		}	
	
	//fclose(f1);
	//fclose(f2);
	//fclose(f3);

}
printf("\nProgram length : %d", lc-sa-3);
return 0;
}

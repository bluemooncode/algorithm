#include<stdio.h>
#include<stdlib.h>

int main()
{
FILE *fptr;
fptr=fopen("unsortednum.txt","w");
for(int i=0;i<100000;i++)
	fprintf(fptr,"%d\n",rand()%1000+1);
fclose(fptr);
return 0;
}

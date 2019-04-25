#include<stdio.h>
#include<stdlib.h>

int main()
{
FILE *fptr=NULL;
fptr=fopen("uniquenum.txt","w");
if(fptr==NULL) printf("Error in file\n");
else
{
  for(int i=0;i<100000;i++)
	fprintf(fptr,"%d\n",i);

fclose(fptr);

}

return 0;
}

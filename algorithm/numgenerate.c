#include<stdio.h>
#include<stdlib.h>

int main()
{
FILE *fptr=NULL;
fptr=fopen("gcdnumbers.txt","w");
if(fptr==NULL) printf("Error in file\n");
for(int i=0;i<5000;i++)
fprintf(fptr,"%d\n",rand()%(1000));
fclose(fptr);
return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fptr=NULL;
fptr=fopen("stringdata.txt","w");
if(fptr==NULL) printf("Error in file\n");
else
{
for(int i=0;i<1005;i++)
{

if(i%10==0)fprintf(fptr,"abc");
else
fprintf(fptr,"ax");
}

fprintf(fptr,"abab");

fclose(fptr);
}
return 0;
}

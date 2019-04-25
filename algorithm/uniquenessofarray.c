#include<stdio.h>
#include<stdlib.h>
int uniqueness(int *ar,int n)
{
int count=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			count++;
			if(ar[j]==ar[i]) return count;
		}
	}
return count;
}

int main()
{
FILE *fptr=NULL,*time=NULL;

fptr=fopen("unsortednum.txt","r");
time=fopen("uniqtime.txt","a");
if(fptr==NULL || time==NULL) printf("Error in file\n");

else
{
int ar[10000];

for(int i=0;i<10000;i++)
	fscanf(fptr,"%d",(ar+i));

for(int i=0;i<10000;i=i+100)
	fprintf(time,"%d %d\n",i,uniqueness(ar,i));

fclose(fptr);
fclose(time);
}

return 0;
}

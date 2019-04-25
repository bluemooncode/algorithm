#include<stdio.h>
#include<stdlib.h>

int matrixmul(int *ar,int *b,int n)
{
int count=0,temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				temp=ar[i*n+k]*b[k*n+j];
				count++;
			}

		}

	}

return count;

}

int main()
{
FILE *fptr=NULL,*time=NULL;
fptr=fopen("gcdnumbers.txt","r");
time=fopen("matrixmultime.txt","w");
if(fptr==NULL|| time==NULL) printf("Error in file\n");
else
{
	int ar[10000];
	for(int i=0;i<10000;i++)
		fscanf(fptr,"%d",(ar+i));
	for(int i=0;i<100;i=i+2)
	{
		fprintf(time,"%d %d\n",i,matrixmul(ar,ar,i));
	}
	fclose(fptr);
}
return 0;
}

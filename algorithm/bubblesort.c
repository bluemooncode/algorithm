#include<stdio.h>
#include<stdlib.h>

int bubblesort(int *ar,int n)
{
	int temp,scount,num;
	for(int i=0;i<n;i++)
	{
		scount=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(ar[j]>ar[j+1])
			{
				scount++;
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
			num++;
		}
		if(scount==0) break;
	}
return num;
}
int main()
{
FILE *fptr=NULL,*time=NULL;
fptr=fopen("sortednum.txt","r");
time=fopen("bubblesorttime.txt","a");
int n=10,*ar;
if(fptr==NULL || time==NULL)
	printf("error in file\n");
else
{
ar=(int*)malloc(sizeof(int)*1001);
for(int i=0;i<1001;i++)
	fscanf(fptr,"%d",(ar+i));



for(int i=10;n<1001;n=n+i)
	fprintf(time,"%d %d\n",n,bubblesort(ar,n));


fclose(fptr);
fclose(time);

}

return 0;
}

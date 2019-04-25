#include<stdio.h>
#include<stdlib.h>
int b[10];

void merge(int *a,int low, int mid, int high) {
int l1,l2,i=0;

for(l1=low,l2=mid+1;l1<=mid && l2<=high ;i++)
{
if(a[l1]>a[l2])l2++;
else l1++;
}
while(l1<=mid)
b[i++]=a[l1++];
while(l2<=high)
b[i++]=a[l2++];

for(i=low;i<=high;i++)
a[i]=b[i];

}

void mergesort(int *ar,int l, int r)
{
if(l>=r)
return;
int m=(l+r)/2;

mergesort(ar,l,m);
mergesort(ar,m+1,r);
merge(ar,l,m,r);
}


int main()
{
FILE *fptr=NULL;
fptr=fopen("unsortednum.txt","r");

if(fptr==NULL)printf("Error in file\n");

else
{
	int *ar=(int*)malloc(sizeof(int)*10);
	for (int i=0;i<10;i++)
	{
		fscanf(fptr,"%d",(ar+i));
	}
	for(int i=0;i<10;i++)
	{
		printf("%d ",*(ar+i));
	}
printf("\n");
	mergesort(ar,0,10);
	printf("After sorting\n");
	for(int i=0;i<10;i++)
	{
		printf("%d ",*(ar+i));
	}

	fclose(fptr);
}
return 0;
}




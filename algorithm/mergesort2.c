#include<stdio.h>
#include<stdlib.h>
int count=0;
void merge(int *ar,int l,int m,int h)
{
int br[h],l1=l,l2=m+1,i=l;
while(l1<=m&&l2<=h)
{
	count++;
	if(ar[l1]>ar[l2]) br[i++]=ar[l1++];
	else br[i++]=ar[l2++];
}
while(l1<=m)
br[i++]=ar[l1++];

while(l2<=h)
br[i++]=ar[l2++];
for(i=l;i<=h;i++)
ar[i]=br[i];


}
void mergesort(int *ar,int l,int h)
{
if(l>=h) return ;
int m=(l+h)/2;

mergesort(ar,l,m);

mergesort(ar,m+1,h);

merge(ar,l,m,h);
}
int main()
{

FILE *fptr=NULL,*time=NULL;
time=fopen("mergesorttime.txt","w");
fptr=fopen("unsortednum.txt","r");

int n=10;
if(fptr==NULL||time==NULL)
printf("Error in file\n");

else
{
int *ar=(int*)malloc(sizeof(int)*10000);
for(int i=0;i<10000;i++)
fscanf(fptr,"%d",(ar+i));


for(int j=10;n<1000;n=n+j)
{
	mergesort(ar,0,n-1);
	fprintf(time,"%d %d\n",n,count);
	count=0;
}


}
return 0;
}


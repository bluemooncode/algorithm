#include<stdio.h>
#include<stdlib.h>

void quicksort(int *ar,int l,int r)
{
if(l>=r)
return;
int i=l+1,j=r,p=l,temp;
while(i<=j&&i<r)
{
while(ar[i]<ar[p]&&i<r)
i++;

while(ar[j]>ar[p])
j--;

temp=ar[i];
ar[i]=ar[j];
ar[j]=temp;
}
temp=ar[i];
ar[i]=ar[p];
ar[p]=temp;
quicksort(ar,l,i-1);
quicksort(ar,i+1,r);

}
/*void quicksort(int *ar,int l,int r)
{
//printf("%d l=%d r=%d\n",l,r,*(ar+l));
if(l>=r)
return;

int i=l+1,j=r,p=l,temp;
while(i<=j&&i<r)
{

while(ar[i]<ar[p]&&i<r)
{
i++;
}
while(ar[j]>ar[p])
{
j--;
}
temp=ar[j];
ar[j]=ar[i];
ar[i]=temp;

}
temp=ar[p];
ar[p]=ar[i];
ar[i]=temp;

if(l<=i-1)
quicksort(ar,l,i-1);
if(i+1<=r)
quicksort(ar,i+1,r);


return;
}*/

int main()
{
FILE *fptr=NULL;
fptr=fopen("unsortednum.txt","r");
int *ar=(int*)malloc(sizeof(int)*5);

if(fptr==NULL)printf("Error in file\n");
else{
for(int i=0;i<10;i++)
{
	fscanf(fptr,"%d",(ar+i));
}
for(int i=0;i<10;i++)
{
	printf("%d ",*(ar+i));
}
printf("\n");
quicksort(ar,0,9);
printf("After sort\n");
for(int i=0;i<10;i++)
{
	printf("%d ",*(ar+i));
}

fclose(fptr);


}

return 0;
}

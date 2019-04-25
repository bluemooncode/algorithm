#include<stdio.h>
#include<stdlib.h>

int count;
int * factors(int n)
{

int *ar=(int*)malloc(sizeof(int)),size=1;
ar[0]=0; //Here the first element holds the size of thea array
for(int i=2;;)
{
	count++;

	if(n%i==0)
	{
		ar=(int*)realloc(ar,sizeof(int)*(++size));
		ar[0]++;
		ar[size-1]=i;
		n=n/i;
	}
	else
	{

		if(i<=n) i++;
		else break;
	}

}
return ar;

}


void gcd(int n,int m)
{
int gcd=1;
int *ar1=factors(n);
int *ar2=factors(m);

if(ar1[0]==0||ar2[0]==0) return;
else{
for(int i=1;i<=ar2[0];i++)
{
	for(int j=1;i<=ar1[0];i++)
	{
		count++;
		if(ar2[i]==ar1[j]) 
		{
			gcd*=ar2[i];
			break;
		}
	}
}

return;
}

}

int main()
{
int arn[100],m;
FILE *fptr=fopen("smallnumbers.txt","r"),*time=fopen("gcd2time.txt","w");
printf("Enter the value of m");
scanf("%d",&m);

for(int i=0;i<100;i++)
	fscanf(fptr,"%d",&arn[i]);

for(int i=0;i<10;i++)
{
	count=0;
	gcd(arn[i],m);
	fprintf(time,"%d %d\n",arn[i],count);
}

return 0;
}

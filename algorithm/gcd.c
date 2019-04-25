#include<stdio.h>
#include<stdlib.h>
int count=0;
int gcd(int n,int m)
{
int temp,i=0;
if(m<=0)return 0;

	for(i=0;;i++)
	{
		temp=n-m;
		if(temp<=0) break;
		if(temp<m) 
		{   
			n=m;			
			m=temp;
		}
		else
		{
		n=temp;		
		}
		
		}
		
	return i;
}
int main()
{
FILE *fptr=NULL,*time=NULL;
fptr=fopen("gcdnumbers.txt","r");
time=fopen("gcdtime.txt","w");
int n,m=5;
if(fptr==NULL || time==NULL) printf("Error in file");
else{
for(int i=0;i<1000;i++)
{

fscanf(fptr,"%d",&n);

fprintf(time,"%d %d\n",n,gcd(n,m));
}
fclose(fptr);
fclose(time);
}
return 0;
}

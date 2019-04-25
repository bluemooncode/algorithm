#include<stdio.h>
#include<stdlib.h>
int count=0;
void tower(int n,char s,char t,char d)
{
count++;
if(n<=1) return;
tower(n-1,s,d,t);
tower(n-1,t,s,d);

}
int main()
{
FILE *fptr=NULL;
fptr=fopen("towerofhtime.txt","w");
if(fptr==NULL) printf("Error in file");
else{
	for(int n=0;n<20;n++)
	{
		count=0;
		tower(n,'s','t','d');
		fprintf(fptr,"%d %d\n",n,count);
	}
	fclose(fptr);
}
return 0;
}

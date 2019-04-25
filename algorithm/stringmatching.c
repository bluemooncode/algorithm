#include<stdio.h>
#include<stdlib.h>

int match(char *str,char *p,int n,int m)
{
int count=1,j;
	for(int i=0;i<n-m;i++)
	{
		count++;
		for(j=0;j<m&&str[i+j]==p[j];j++)
		{
			
		}
		count=count+j;
		if(j==m) {printf("yes");return count;}
	}

return count;
}
int main()
{
char str[1000],p[3]="abc";
FILE *fptr=NULL,*time=NULL;
fptr=fopen("stringdata.txt","r");
time=fopen("strmatchtime.txt","w");
if(fptr==NULL || time==NULL)printf("Error in file\n");
else{
for(int i=0;i<1000;i++)
fscanf(fptr,"%c",(str+i));

for(int i=5;i<1000;i=i+10)
{
fprintf(time,"%d %d\n",i,match(str,p,i,3));

}
fclose(fptr);
fclose(time);
}
return 0;
}

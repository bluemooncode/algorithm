#include<stdio.h>
#include<stdlib.h>

int stringmatch(char *ar,char *p,int n,int m)
{
int count=0,j;
	for(int i=0;i<n-m;i++)
	{	j=0;
		count++;
		while(ar[i+j]==p[j])
		{ j++;
		  count++;
		}
		if(j==m-1)break;
	}
	return count;
}
int main()
{
char pattern[]="man",str[]="adsadasdamandf";
printf("%d",stringmatch(str,pattern,sizeof(str),sizeof(pattern)));
return 0;
}

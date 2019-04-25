#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int selectionSort(int n,int *ar)
{
int min,num=0,temp;
    for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(ar[min]>ar[j]) min=j;
			num++;
		}

		temp=ar[min];
		ar[min]=ar[i];
		ar[i]=temp;
	}
	return num;
}

int main()
{
    int *ar=NULL,*dest=NULL,i,j,t;
    ar=(int*)malloc(sizeof(int)*10000);
    dest=(int*)malloc(sizeof(int)*10000);
    FILE *f,*tf;
	printf("ok");
    tf=fopen("selectionsorttime.txt","w+");
    f=fopen("numbers.txt","r");

    for(j=10;j<1001;j=j+10)
    {
        i=0;
        while(!feof(f)&&i<j)
        {
            fscanf(f,"%d",(ar+1));
            i++;
        }
        t=selectionSort(j,ar);
        fprintf(tf,"%d %d\n",j,t);
    }

fclose(tf);
fclose(f);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main()
{
    FILE *f;
    int i=0,j=0;
    
    f=fopen("numbers.txt","w");
    while(i!=10000)
    {
        fprintf(f,"%d\n",rand());
        i++;
    }
    
    fclose(f);

    
    return 0;
}
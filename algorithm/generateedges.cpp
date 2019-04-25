#include<iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;

int main()
{
fstream fptr("edges.txt",ios::out);
if(fptr.is_open())
{
for(int i=0;i<1000;i++)
	fptr<<rand()%10<<" "<<rand()%10<<"\n";
}
else cout<<"File error\n";
//fptr<<rand()%100<<" "<<rand()%50<<"\n";
return 0;
}

#include<iostream>
using namespace std;

int ar[3][3],flg[3];
int getadj(int n,int v)
{
int i=0;

for(i=0;i<n;i++)
{
if(ar[v][i]==1&&flg[i]==0)
{
ar[v][i]=0;

return i;

}
}
return -1;
}
int main()
{
int n;
n=3;
int stack[n],stkptr=-1,temp,start=0;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		ar[i][j]=0;
		
	}
	flg[i]=0;
}
ar[0][1]=1;
ar[1][0]=1;
ar[2][0]=1;
//ar[1][2]=1;

do
{
do
{
if(flg[start]==0)
cout<<start<<endl;

flg[start]=1;
temp=getadj(n,start);
if(temp==-1) break;
stack[++stkptr]=start;
start=temp;


}while(1);


if(stkptr==-1)break;

start=stack[stkptr--];

}while(1);


return 0;
}

#include<iostream>
#include<list>
#include<fstream>

using namespace std;

class Graph
{
int **ar;
int size;
public:
Graph(int n){
//*matrix=new int[n];
ar=new int*[n];
for(int i=0;i<n;i++)
	*(ar+i)=new int[n];
size=n;
}
void getData();
void disp();
void traverse(int);
int getadj(int,int*);
};

int Graph::getadj(int s,int *f)
{
for(int i=0;i<size;i++)
{
if(ar[s][i]==1&&f[i]!=1)
	{
		ar[s][i]=0;
		return i;
	}
}
return -1;
}

void Graph::traverse(int start)
{
int stack[size],stkptr=-1,flg[size],temp,allvistited=0;
for(int i=0;i<size;i++) flg[i]=0;
nexttree:
do
{
do
{
if(flg[start]!=1)
{
	cout<<start<<endl;
	flg[start]=1;
}
temp=getadj(start,flg);
if(temp==-1)
	break;
stack[++stkptr]=start;
start=temp;
}while(1);
if(stkptr==-1) break;

start=stack[stkptr--];

}while(1);

for(int i=0;i<size;i++){
for(int j=0;j<size;j++)
{
if(ar[i][j]==1&&flg[j]==0){ start=j;goto nexttree;	}
}
}

}
void Graph::getData()
{
fstream fptr("edges.txt",ios::in);
int p1,p2;
for(int i=0;i<size;i++)
	{

		fptr>>p1>>p2;
		
		//cout<<p1<<" "<<p2<<endl;
		ar[p1%size-1][p2%size-1]=1;
	}

}
void Graph::disp()
{
for(int i=0;i<this->size;i++){
	for(int j=0;j<this->size;j++)
		cout<<ar[i][j]<<" ";
	cout<<"\n";
}

}

int main()
{
Graph g(10);
g.getData();
//g.disp();
g.traverse(0);


return 0;
}

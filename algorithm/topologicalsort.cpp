#include<iostream>

using namespace std;

class Graph{
int **ar;
int size;
public:
Graph(int n);
void reverseDirection();
void toposort();
void getData();
void disp();

int findvector(int*);
};

int Graph::findvector(int *visit)
{
	int j,i;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++){if(ar[i][j]==1)break;}
		if(j==size&&visit[i]==0)
{
			return i;
}
		

	}
	return -1;
}

void Graph::toposort()
{
int v,visit[size];
for(int i=0;i<size;i++)visit[i]=0;

	for(int i=0;i<size;i++)
	{
		v=findvector(visit);
		visit[v]=1;
		if(v==-1) break;
		cout<<endl<<v;
		for(int j=0;j<size;j++)
		{
			ar[j][v]=0;  //very important line.
		}

	

	}

}
void Graph::getData()
{
for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
		ar[i][j]=0;

ar[4][2]=ar[4][5]=1;
ar[2][1]=ar[2][3]=1;
ar[5][1]=ar[5][3]=1;
ar[1][0]=ar[3][0]=1;

}
void Graph::reverseDirection()
{
int temp[size][size];

for(int i=0;i<size;i++)
{

	for(int j=0;j<size;j++){
		temp[i][j]=0;
		
	}
}

for(int i=0;i<size;i++)
{

	for(int j=0;j<size;j++){
		if(ar[i][j]==1)
		{
			temp[j][i]=1;
		}
	}
}
for(int i=0;i<size;i++)
{
for(int j=0;j<size;j++)
ar[i][j]=temp[i][j];
}




}

void Graph::disp()
{
for(int i=0;i<size;i++){
	for(int j=0;j<size;j++)
		cout<<ar[i][j]<<" ";
	cout<<endl;
}

}
Graph::Graph(int n)
{
size=n;
ar=new int*[n];
for(int i=0;i<n;i++)
	*(ar+i)=new int[n];
}
int main()
{
Graph g(6);
g.getData();
g.disp();
g.reverseDirection();
cout<<endl;
g.disp();
g.toposort();
return 0;
}

#include<iostream>
#include<fstream>

using namespace std;

int edge[100][3],treeEdges[100][2],ptr=0,ne=0,visited[100];

void disp(){
	for(int i=0;i<ne;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;
}

void getdata(){
	int p1,p2;
	fstream f("edges.txt");
	for(int i=0;i<10;i++)
	{
		f>>p1>>p2;
		edge[i][0]=p1;
		edge[i][1]=p2;
		edge[i][2]=(p1+p2)%23;
		ne++;
	}

	for(int i=0;i<100;i++)
		visited[i]=0;
}

void prims(){
	int min=999,mini=-1;
	for(int i=0;i<ne;i++){
		if(visited[edge[i][0]]==1&&visited[edge[i][1]]!=1)
		{
			if(min>edge[i][2]){
				min=edge[i][2];mini=i;
			}
		}

		else if(visited[edge[i][1]]==1&&visited[edge[i][0]]!=1)
		{
			if(min>edge[i][2]){
				min=edge[i][2];mini=i;
			}
		}
	}

	if(mini!=-1){
		visited[edge[mini][1]]=visited[edge[mini][0]]=1;
		treeEdges[ptr][0]=edge[mini][0];treeEdges[ptr++][1]=edge[mini][1];
		prims();
	}

}


void dispedges(){
	for(int i=0;i<ptr;i++)
		cout<<treeEdges[i][0]<<" "<<treeEdges[i][1]<<endl;

}

int main(){
	getdata();
	disp();
	visited[edge[0][0]]=1;
	prims();
	dispedges();

	return 0;
}

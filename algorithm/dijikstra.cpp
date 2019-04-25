#include<iostream>
#include<fstream>

using namespace std;

int edge[100][3],ne=0,visited[100],treeEdge[100][3],ptr=0;

void getdata(){
	fstream f("edges.txt");
	int p1,p2;
	for(int i=0;i<30;i++)
	{
		f>>p1>>p2;
		edge[i][0]=p1;
		edge[i][1]=p2;
		edge[ne++][2]=(p1+p2)%23;
	}
	for(int i=0;i<100;i++)visited[i]=0;
}

int getpathweight(int e){
	
	for(int i=0;i<ptr;i++)
	{
		if(treeEdge[i][1]==e){
			return treeEdge[i][2]+getpathweight(treeEdge[i][0]);
			
		}
	}
	return 0;
}

int getweight(int e){
	if(visited[e]==0)return 0;
	return getpathweight(e);
}

void mst(){
	int min=999,mini=-1,w1,w2;
	for(int i=0;i<ne;i++){
		w1=getweight(edge[i][0]);
		w2=getweight(edge[i][1]);
		if(visited[edge[i][0]]==1&&visited[edge[i][1]]!=1&&(edge[i][2]+w1)<min){
		min=edge[i][2];
		mini=i;
		}
		else if(visited[edge[i][1]]==1&&visited[edge[i][0]]!=1&&(edge[i][2]+w2)<min){
		min=edge[i][2];
		mini=i;
		}
	}
	if(mini!=-1){
		treeEdge[ptr][0]=visited[edge[mini][0]]==1?edge[mini][0]:edge[mini][1];
		treeEdge[ptr][1]=visited[edge[mini][0]]==1?edge[mini][1]:edge[mini][0];
		treeEdge[ptr++][2]=edge[mini][2];
		visited[edge[mini][1]]=visited[edge[mini][0]]=1;
		mst();
	}
	
}

void getpath(int e){
	cout<<e<<" ";
	for(int i=0;i<ptr;i++)
	{
		if(treeEdge[i][1]==e){
			getpath(treeEdge[i][0]);
			return;
		}
	}
}

void disp(){

for(int i=0;i<ptr;i++)cout<<treeEdge[i][0]<<" "<<treeEdge[i][1]<<" "<<treeEdge[i][2]<<endl;
}

int main(){


	getdata();
	visited[edge[0][0]]=1;
	mst();
	disp();
	for(int i=0;i<ptr;i++){
	getpath(edge[i][1]);
	cout<<endl;
	}
return 0;
}

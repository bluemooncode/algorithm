#include<iostream>
#include<fstream>

using namespace std;

int edge[100][3],ne=0,name=0,treeEdges[100][2],pptr=0;

int isCycle(int p1,int p2){
int name=1,subset[100];
	for(int i=0;i<100;i++)
		subset[i]=-1;

	for(int i=0;i<pptr;i++)
	{
		subset[treeEdges[i][0]]=0;
		subset[treeEdges[i][1]]=0;
		
	}

	for(int i=0;i<pptr;i++)
	{
		if(subset[treeEdges[i][0]]==0&&subset[treeEdges[i][1]]!=0)subset[treeEdges[i][0]]=subset[treeEdges[i][1]];
		
		else if(subset[treeEdges[i][1]]==0&&subset[treeEdges[i][0]]!=0)subset[treeEdges[i][1]]=subset[treeEdges[i][0]];
	
		else if(subset[treeEdges[i][0]]==0&&subset[treeEdges[i][1]]==0){subset[treeEdges[i][1]]=name;subset[treeEdges[i][0]]=name++;}

		else if(subset[edge[i][0]]!=subset[edge[i][1]]){
			int temp=subset[edge[i][0]],temp2=subset[edge[i][1]];
			for(int k=0;k<100;k++)
				{
					if(temp2==subset[k])subset[k]=temp;
				}
		}
	}

	
	
	if(subset[p1]==subset[p2]&&subset[p1]!=-1) return 1;

	return 0;


}

void getdata(){
	int p1,p2;
	fstream f("edges.txt");

	
	for(int i=0;i<20;i++)
	{
		f>>p1>>p2;
		edge[i][0]=p1;
		edge[i][1]=p2;
		edge[i][2]=(p1+p2)%23;
		edge[i][3]=0;
		ne++;

	}

}

void sort(){

	int min,temp;
	for(int i=0;i<ne;i++){
		min=i;
		for(int j=i;j<ne;j++){
			if(edge[min][2]>edge[j][2])min=j;

		}
		temp=edge[i][0];
		edge[i][0]=edge[min][0];
		edge[min][0]=temp;

		temp=edge[i][1];
		edge[i][1]=edge[min][1];
		edge[min][1]=temp;

		temp=edge[i][2];
		edge[i][2]=edge[min][2];
		edge[min][2]=temp;

	}


}

void kruskal(){

	
	treeEdges[0][0]=edge[0][0];
	treeEdges[0][1]=edge[0][1];
	pptr=1;
	for(int i=1;i<ne;i++){
		if(isCycle(edge[i][0],edge[i][1])==1) continue;

		else{
			treeEdges[pptr][0]=edge[i][0];
			treeEdges[pptr++][1]=edge[i][1];
		}
	}

}

void disp(){

	for(int i=0;i<ne;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;

	
}
void dispmst(){
	for(int i=0;i<pptr;i++)
		cout<<treeEdges[i][0]<<"  "<<treeEdges[i][1]<<endl;

}

int main(){

	getdata();
	//disp();
	sort();
	disp();
	kruskal();
	dispmst();

	return 0;

}

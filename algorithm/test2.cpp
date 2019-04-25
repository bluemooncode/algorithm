#include<iostream>
#include<fstream>

using namespace std;

int edge[100][4],visited[100],ne,bfstree[100],treeptr=0,q[100],qptrf=0,qptrb=-1,temp[100][2],ptr=0;;
void bfs(int);
void visitall(){
	for(int i=0;i<ne;i++){
		if(visited[edge[i][0]]!=1)
			bfs(edge[i][0]);
		else if(visited[edge[i][1]]!=1)
			bfs(edge[i][1]);


	}

}

void bfs(int e){

	if(visited[e]==0){
		q[++qptrb]=e;
		visited[e]=1;
		cout<<e<<" ";
	}

		for(int i=0;i<ne;i++){
			if(edge[i][0]==e&&visited[edge[i][1]]!=1){
				q[++qptrb]=edge[i][1];
				visited[edge[i][1]]=1;
				edge[i][3]=1;
				//cout<<e<<edge[i][1]<<endl;
			}

			else if(edge[i][1]==e&&visited[edge[i][0]]!=1){
				q[++qptrb]=edge[i][0];
				visited[edge[i][0]]=1;
				edge[i][3]=1;
				//cout<<edge[i][0]<<e<<endl;
			}
		}
	

	if(qptrf<=qptrb)
		bfs(q[qptrf++]);
	

}

void getdata(){
	int p1,p2;
	fstream f("edges.txt");

	for(int i=0;i<100;i++)
		visited[i]=0;
	for(int i=0;i<10;i++)
	{
		f>>p1>>p2;
		edge[i][0]=p1;
		edge[i][1]=p2;
		edge[i][2]=(p1+p2)%23;
		edge[i][3]=0;
		ne++;

	}

}

void disp(){
	for(int i=0;i<ne;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<" "<<edge[i][3]<<endl;

}

int main(){
	getdata();
	disp();
	
	visitall();
	cout<<endl;
	disp();
for(int i=0;i<ptr;i++)
	cout<<temp[i][0]<<" "<<temp[i][1]<<endl;

	return 0;
}


#include<iostream>
#include<fstream>

using namespace std;

int edge[100][3],visited[100],vptr,ne;

void dfs(int w){
	if(visited[w]!=1){
		cout<<w<<endl;
		visited[w]=1;
	}

	for(int i=0;i<100;i++){
		if(edge[i][0]==w&&visited[edge[i][1]]!=1){
			dfs(edge[i][1]);
		}
		else if(edge[i][1]==w&&visited[edge[i][0]]!=1){
			dfs(edge[i][0]);
		}
	}
}
void disp(){
	for(int i=0;i<ne;i++)
		cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;


}
void getdata(){
	fstream f("edges.txt");
	ne=0;vptr=0;
	for(int i=0;i<10;i++)
	{
		ne++;
		f>>edge[i][0]>>edge[i][1];
		edge[i][2]=(3*edge[i][0]+2*edge[i][0])%97;
	}
	for(int i=0;i<100;i++)
	{
		visited[i]=0;
	}

}

int main(){
	getdata();
	disp();
	dfs(edge[0][0]);

return 0;
}

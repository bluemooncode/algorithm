#include<iostream>
#include<fstream>

using namespace std;

struct node{
	int info;
	struct node *link;

};
typedef struct node node;

node ar[5];
int edge[10][2],ne=0,visited[100],nv=0;

void getdata(){
	fstream f("dag.txt");
	for(int i=0;i<5;i++)
	{
		f>>edge[i][0]>>edge[i][1];
		ne++;
	}
	for(int i=0;i<ne;i++){
		if(visited[edge[i][0]]!=1){
			ar[nv++].info=edge[i][0];
			ar[nv-1].link=NULL;
			visited[edge[i][0]]=1;
		}
		else if(visited[edge[i][1]]!=1){
			ar[nv++].info=edge[i][1];
			ar[nv-1].link=NULL;
			visited[edge[i][1]]=1;
		}
	}

	for(int i=0;i<nv;i++){
		for(int j=0;j<ne;j++){

			node *newnode=new node;
			newnode->link=NULL;
			if(edge[j][0]==ar[i].info){
				newnode->info=edge[j][1];
				newnode->link=ar[i].link;
				ar[i].link=newnode;
			}
			

		}
	
	}

	for(int i=0;i<100;i++)
		visited[i]=0;
}
void deletenode(int i,int n){

	for(int k=0;k<nv;k++){
				if(visited[ar[k].info]!=1){
					node *temp=ar[k].link,*prev=ar+k;
					while(temp!=NULL){
						if(temp->info==n){
							
							prev->link=temp->link;
							temp=prev->link;
						}
						else{
							prev=temp;
							temp=temp->link;
						}
						
					}
				}
			}
			visited[ar[i].info]=1;


}
void disp(){

	for(int i=0;i<nv;i++){
		node *temp;
		temp=ar[i].link;
		cout<<ar[i].info<<" -----> ";
		while(temp!=NULL){
			cout<<temp->info<<" ";
			temp=temp->link;
		}
		cout<<endl;

	}

}

void toposort(){
	int i;
	for(i=0;i<nv;i++){
		if(visited[ar[i].info]!=1&&ar[i].link==NULL){
			deletenode(i,ar[i].info);
			//disp();cout<<endl;
			break;
		}
	}
	if(i!=nv)
		toposort();

}


int main(){

	getdata();
	disp();
	toposort();
	disp();

	return 0;
}

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Graph{
    public:
    int temp[100][3],edge[100][3],ne,nv,visited[100],ar[100][100],prev,cycle[100],c;

    Graph(){
        ne=c=0;
        nv=5;

    }
    void addEdge(int i,int j){
        temp[ne][0]=i;
        temp[ne][1]=j;
        temp[ne++][2]=(i+j)%11;
    }
    void dispEdge(){
        for(int i=0;i<ne;i++){
            cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<endl;
        }
    }
    void sort();
    void vistAllnode();
    void dfs(int);
};
void Graph::sort(){
    int max,t1,t2,t3;
    for(int i=0;i<ne;i++){
        max=0;
        for(int j=1;j<ne-i;j++){
    
            if(temp[max][2]<temp[j][2]){
                max=j;cout<<temp[max][2]<<temp[j][2];
            }
        }
        t1=temp[i][0];
        t2=temp[i][1];
        t3=temp[i][2];
        temp[i][0]=temp[max][0];
        temp[i][1]=temp[max][1];
        temp[i][2]=temp[max][2];
        temp[max][0]=t1;
        temp[max][1]=t2;
        temp[max][2]=t3;


    }
    for(int i=0;i<ne;i++){
        edge[i][0]=temp[i][0];
        edge[i][2]=temp[i][2];
        edge[i][1]=temp[i][1];
    }
}
void Graph::vistAllnode(){
    for(int i=0;i<100;i++){
        visited[i]=0;
        for(int j=0;j<100;j++ ){
            ar[i][j]=0;
        
        }
    }
    
    for(int i=0;i<ne;i++){
        ar[edge[i][0]][edge[i][1]]=ar[edge[i][1]][edge[i][0]]=edge[i][2];
    }

    for(int i=0;i<nv;i++){
        
        dfs(i);

    }
    for(int y=0;y<c;y++){
        cout<<cycle[y]<<endl;
    }
}

void Graph::dfs(int e){
    
    if(visited[e]!=1){
    cycle[c++]=e;
      
    }
    visited[e]=1;
    
    for(int i=0;i<nv;i++){
        if(ar[e][i]!=0&&visited[i]==0){
            prev=e;
             dfs(i);
            
        } 
        if(ar[e][i]!=0){
           for(int y=0;y<c;y++){
              
               if(cycle[y]==i){
                    int diff=abs(e-i);
                    if(diff>1)
                        cout<<e<<"match"<<i<<endl;
               }
           }
        }  
    }
    
}

int main(){

    int p1,p2;
    Graph g;
    fstream f("edges.txt");
    for(int i=0;i<5;i++){
       
        f>>p1>>p2;
        g.addEdge(p1,p2);
    }
    g.dispEdge();
    g.sort();
    g.dispEdge();
    g.vistAllnode();
    return 0;
}
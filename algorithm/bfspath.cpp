#include<iostream>
#include<fstream>

using namespace std;

class Graph{
    public:
    int edge[100][3],nv,ne,q[100],qptrf,qptrb,visited[100],vptr,path[100][2],pathptr;
    Graph(){
        nv=ne=0;
        qptrf=vptr=0;
        qptrb=-1;
        pathptr=0;
    }
    void dispEdge(){
        for(int i=0;i<ne;i++)
            cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;
    }
    void addEdge(int i,int j){
        edge[ne][0]=i;
        edge[ne][1]=j;
        edge[ne++][2]=(i*j)%23;
    }
    void vistAllNode();
    void bfs(int);
    void getPath();
    void discoverpath(int);
};
void Graph::vistAllNode(){
    
    for(int i=0;i<ne;i++){
        if(visited[edge[i][0]]!=1)
            bfs(edge[i][0]);
    }
}

void Graph::bfs(int e){
    
    cout<<e<<"\t";
    visited[e]=1;
    int next=-1;
    if(1){
        
        
        for(int i=0;i<ne;i++){
            if(edge[i][0]==e){
                
                next=edge[i][1];
            }
            else if(edge[i][1]==e){
                
                next=edge[i][0];
            }
            
            if(next!=-1&&visited[next]!=1){
                visited[next]=1;
               // cout<<e<<" pushed "<<next<<endl;
                path[pathptr][0]=e;
                path[pathptr++][1]=next;
                q[++qptrb]=next;
            }
        }
        if(qptrb>=qptrf){
            bfs(q[qptrf++]);
        }
    
    }
}

void Graph::getPath(){
    discoverpath(9);
    cout<<endl;
    discoverpath(8);
}
void Graph::discoverpath(int e){
    cout<<e<<" ";
    for(int i=0;i<pathptr;i++){
        if(path[i][1]==e){
            discoverpath(path[i][0]);
            return;
        }
    }
}

int main(){

    int p1,p2;
    Graph g;
    fstream f("edges.txt");
    for(int i=0;i<10;i++){
        f>>p1>>p2;
        g.addEdge(p1,p2);
    }
    g.dispEdge();
    g.vistAllNode();
    cout<<endl;
    g.getPath();
    return 0;
}

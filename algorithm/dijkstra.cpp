#include<iostream>
#include<fstream>


using namespace std;

class Graph{
public:
int edge[100][3],visited[100],ne,path[100][3],pathptr;
Graph(){
    ne=pathptr=0;
    for(int i=0;i<100;i++){
        visited[i]=0;
    }
}

void addEdge(int i,int j){
    edge[ne][0]=i;
    edge[ne][1]=j;
    edge[ne++][2]=(i+j)%23+(i*j)/23;
}
void dispEdge();
void getShortestPath();

void generatePath();
void dispPath();
void findPath(int);

};

void Graph::findPath(int e){
    cout<<e<<" ";
    for(int i=0;i<pathptr;i++){
        if(path[i][1]==e){
            findPath(path[i][0]);
            return;
        }
    }
}

void Graph::generatePath(){
    for(int i=0;i<100;i++){
        if(visited[i]==1)
        {    
            findPath(i);
            cout<<endl;

        }
    }
}

void Graph::dispPath(){
    for(int i=0;i<pathptr;i++)
        cout<<path[i][0]<<"-->"<<path[i][1]<<" = "<<edge[i][2]<<endl;
}

void Graph::dispEdge(){
    for(int i=0;i<ne;i++){
        cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<endl;
    }
}

void Graph::getShortestPath(){

    int min=0,flg=0,minv,v,m=999;
    for(int i=0;i<100;i++){
        if(visited[i]==1){
            v=i;
            for(int i=0;i<ne;i++){
            // cout<<e<<edge[i][0]<<edge[i][1]<<endl;
                if(edge[i][0]==v&&visited[edge[i][1]]!=1&&m>=edge[i][2]){
                    min=i;
                    m=edge[i][2];
                    flg=1;
                    minv=v;
                   // cout<<edge[i][0]<<edge[i][1]<<endl;
                }
                else if(edge[i][1]==v&&visited[edge[i][0]]!=1&&m>=edge[min][2]){
                    min=i;
                    m=edge[i][2];
                    flg=1;
                    minv=v;
                   // cout<<edge[i][0]<<edge[i][0]<<endl;
                }

            }
        }
    }
    if(flg){
        visited[edge[min][0]]=visited[edge[min][1]]=1;
        path[pathptr][0]=minv;
        path[pathptr][2]=m;
        path[pathptr++][1]=(minv==edge[min][0]?edge[min][1]:edge[min][0]);

        getShortestPath();   
    }
}


int main(){

    int p1,p2;
    Graph g;

    fstream f("edges.txt");

    for(int i=0;i<20;i++){
        f>>p1>>p2;
        g.addEdge(p1,p2);
    }

    g.dispEdge();
    cout<<endl;
    g.visited[g.edge[0][0]]=1;
    g.getShortestPath();
    g.generatePath();

    return 0;
}
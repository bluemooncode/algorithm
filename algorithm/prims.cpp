#include<iostream>
#include<fstream>


using namespace std;

typedef struct edge edge;
class Graph{
    public:
    int nv,ne;
    int v[100][3];
    Graph(){
        nv=ne=0;
    }
    void addEdge(int i,int j){
        ne++;
        nv=5;
        v[ne-1][0]=i;
        v[ne-1][1]=j;
        v[ne-1][2]=i*j%5+i*j%11+i*j/5+i*i/3+j*j/7+j%7;
        

    }
    void dispEdges(){
        for(int i=0;i<ne;i++){
            cout<<v[i][0]<<"\t"<<v[i][1]<<"\t"<<v[i][2]<<endl;
        }
    }
    void prims();

};
void Graph::prims(){
    int ar[ne][4],visited[ne],visistcount=1,j=0,mini,minj=-1,min=9999;
    visited[0]=v[0][0];
    for(int i=0;i<ne;i++){
        ar[i][0]=v[i][0];
        ar[i][1]=v[i][1];
        ar[i][2]=v[i][2];
        ar[i][3]=0;
    }
    for(int o=0;o<9;o++){
        mini=-1;minj=-1;min=9999;
        for(j=0;j<visistcount;j++){
            
            for(int i=0;i<ne;i++){
                
                    if(ar[i][0]==visited[j]&&ar[i][3]==0){
                        if(min>ar[i][2]){
                            min=ar[i][2];
                            mini=i;
                            minj=0;
                        }
                    }
                    else if(ar[i][1]==visited[j]&&ar[i][3]==0){
                        if(min>ar[i][2]){
                            min=ar[i][2];
                            mini=i;
                            minj=1;
                        }
                    }
                }
        }

        if(min!=9999&& mini!=-1){
             
            ar[mini][3]=1;
            int m;
            for(m=0;m<visistcount;m++){
                if(ar[mini][(minj+1)%2]==visited[m]){
                   
                    break;}
            }
            if(m==visistcount){
                visited[visistcount++]=ar[mini][(minj+1)%2];
            }
            cout<<ar[mini][0]<<" "<<ar[mini][1]<<" "<<ar[mini][2]<<" "<<"\t";
        }
    }


    
}

int main(){

    Graph g;
    fstream f;
    f.open("edges.txt");
    int p1,p2;
    

    for(int i=0;i<20;i++){
        f>>p1>>p2;
        g.addEdge(p1,p2);
    } 
    g.dispEdges();
    g.prims();
    return 0;
}
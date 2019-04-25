#include<iostream>
#include<fstream>

using namespace std;

class Sack{
    public:
    int capacity,numberofiteams,**ar,**iteams,optimal,*optimallist,optimalptr;
    Sack(int,int);
    void getData();
    void disp();
    void calculateMatrix();
    void getIteamsList();

};

 Sack::Sack(int i,int j){
            capacity=i;
            numberofiteams=j;
            optimal=optimalptr=0;
            optimallist=new int[j];
            ar=new int*[j+1];
            iteams=new int*[j];
            for(int k=0;k<i+1;k++)
                ar[k]=new int[i+1];

            for(int k=0;k<j;k++)
                iteams[k]=new int[2];
}

void Sack::getData(){
    fstream f("sackiteams.txt");

    for(int i=0;i<numberofiteams;i++){
        f>>iteams[i][0]>>iteams[i][1];
    }
}

void Sack::disp(){
    cout<<"Weight\tValue"<<endl;
    for(int i=0;i<numberofiteams;i++)
        cout<<iteams[i][0]<<"\t"<<iteams[i][1]<<endl;

    for(int i=0;i<=numberofiteams;i++)
    {
        for(int j=0;j<=capacity;j++)
            cout<<ar[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Iteams are :";
    for(int i=0;i<optimalptr;i++)
        cout<<optimallist[i]<<" ";

    cout<<endl;
}

void Sack::calculateMatrix(){

    for(int i=0;i<=capacity;i++){
        ar[0][i]=0;
    }
    for(int i=0;i<=numberofiteams;i++){
        ar[i][0]=0;
    }

   for(int i=1;i<=numberofiteams;i++){
        for(int j=1;j<capacity+1;j++){
            if(j>=iteams[i-1][0]){
                if((iteams[i-1][1]+ar[i-1][j-iteams[i-1][0]])>ar[i-1][j]){
                   ar[i][j]=iteams[i-1][1]+ar[i-1][j-iteams[i-1][0]];
                  
                }
                else{
                    ar[i][j]=ar[i-1][j];
                }
            }
            else{
                ar[i][j]=ar[i-1][j];
            }
        }
    }
    optimal=ar[numberofiteams][capacity];
}


void Sack::getIteamsList(){
  int v=ar[numberofiteams][capacity],i;
    for(int j=numberofiteams;j>0;j--){
        
        for(i=capacity;i>0;i--){
            if(v==ar[j-1][i]){
                break;
            }
        }
        if(i==0){
            
            optimallist[optimalptr++]=j;
            v=v-iteams[j-1][1];
        }

    }
    
}


int main(){

    Sack s(5,4);

    s.getData();
    s.calculateMatrix();
    s.getIteamsList();
    s.disp();
    return 0;
}
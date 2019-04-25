#include<iostream>

using namespace std;

class Heap{
    public:
        int *ar;
        int size,last;
        Heap(int n){
            size=n;
            last=1;
            ar=new int[n+1];
        }
        void insert(int num){
            ar[last++]=num;
        }
        void heapify();
        void disp();
};
void Heap::disp(){
    for(int i=0;i<=size;i++)
        cout<<ar[i]<<endl;
}
void Heap::heapify(){
   int i,j,k,v,n=size,flg;
   for(i=size/2;i>0;i--){
       v=ar[i];
       k=i;
       flg=0;
       while(2*k<=n&&flg!=1){
           j=2*k;
           if(ar[j]<ar[j+1]){
               j=j+1;
           }
           if(v<ar[j]){
               ar[k]=ar[j];
               k=j;
           }
           else{
               flg=1;
           }
       }
       ar[k]=v;
   }
}


int main(){

    Heap h(10);
    int ar[10]={12,34,45,6,3,2,1,90,7,5},n=10;
    for(int i=0;i<n;i++)
        h.insert(ar[i]);

    h.disp();

    h.heapify();
cout<<endl;
    h.disp();

    return 0;
}
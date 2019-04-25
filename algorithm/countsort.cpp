#include<iostream>

using namespace std;

class SortedArray{
    int *ar,*freq;
    int size,min,max;
    public:
        SortedArray(int n)
        {
            ar=new int[n];
            freq=new int[n];
            size=n;
        
        }
       
        void disp();
        void sort();
        void getData();
       
};
void SortedArray::getData(){
    for(int i=0;i<size;i++)
        ar[i]=size-i+1;
}

 void SortedArray::disp()
        {
            for(int i=0;i<size;i++)
                cout<<ar[i]<<" ";
            cout<<"\n";
        }
void SortedArray::sort(){
            for(int i=0;i<size;i++)
            {
                for(int j=i+1;j<size;j++)
                {
                    if(ar[i]>ar[j])freq[i]++;
                    else freq[j]++;
                }
            }
            int temp[size];
            for(int i=0;i<size;i++)
                temp[freq[i]]=ar[i];
            for(int i=0;i<size;i++)
                ar[i]=temp[i];
        }

        int main()
        {
            SortedArray a(10);
            a.getData();
            cout<<"Beforesort\n";
            a.disp();
            a.sort();
            cout<<"After sorting\n";
            a.disp();
            return 0;
        }
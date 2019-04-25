#include<iostream>
#include<fstream>

using namespace std;

int ar[100],n=0;

void getdata(){
	fstream f("unsortednum.txt");
	for(int i=0;i<10;i++)
		f>>ar[n++];
}

void merge(int l,int m,int h){

	int b[100];
	int i=l,j=m+1,k=0;
	while(i<=m&&j<=h){
		if(ar[i]>ar[j])b[k++]=ar[j++];
		else b[k++]=ar[i++];

	}

	while(i<=m)
		b[k++]=ar[i++];

	while(j<=h)
		b[k++]=ar[j++];

	i=0;
	while(i<k)
		ar[i+l]=b[i++];

}

void sort(int l,int h){

	if(l>=h) return;

	int m=(l+h)/2;
	sort(l,m);
	sort(m+1,h);

	merge(l,m,h);

}

void disp(){

	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}
int main(){

	getdata();
	disp();
	sort(0,9);
	disp();

	return 0;
}



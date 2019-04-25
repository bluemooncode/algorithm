#include<iostream>
#include<fstream>

using namespace std;

int ar[1000],n=15;
void disp();
void getdata(){
	fstream f("unsortednum.txt");
	for(int i=0;i<1000;i++)
		f>>ar[i];

}

/*void quicksort(int low,int high){
	int temp;
	if(low>=high)return;
	int p=low,i=low+1,j=high;
	while(i<j){
		while(ar[i]<ar[p])i++;
		while(ar[j]>ar[p])j--;

		temp=ar[i];
		ar[i]=ar[j];
		ar[j]=temp;
	
	}
	temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
	
	temp=ar[p];
	ar[p]=ar[j];
	ar[j]=temp;
	quicksort(low,j-1);
	quicksort(j+1,high);
}
*/

void quicksort(int l,int h){

	if(l>=h) return;

	int temp;
	int p=l,i=l+1,j=h;
	while(i<j){
		while(ar[p]>ar[i])i++;
		while(ar[p]<ar[j])j--;

		temp=ar[i];
		ar[i]=ar[j];
		ar[j]=temp;
	}

	temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;

	temp=ar[p];
	ar[p]=ar[j];
	ar[j]=temp;

	quicksort(l,j-1);
	quicksort(j+1,h);
}
void disp(){

	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

int main(){

	getdata();
	disp();
	quicksort(0,n-1);
	disp();

	cout<<endl;
	return 0;
}

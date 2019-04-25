#include<iostream>
#include<string.h>

using namespace std;

struct lookup{
    char c;
    int len;
};
typedef struct lookup lookup;

class MyString{
char *str,*pattern;
int n,m;
lookup *table;
public:
    MyString();
    void disp();
    int match();

};
void MyString::disp()
{
    
    for(int i=0;i<255;i++){
        cout<<table[i].c<<" "<<table[i].len <<endl;
    }
}
int MyString::match()
{
    int j;
    for(int i=m-1;i<n;){
        for(j=0;j<m;j++){
            //cout<<str[i-j]<<" "<<pattern[m-j-1]<<"    ";
            if(str[i-j]!=pattern[m-j-1]) break;
        }
        
        if(j==m) return i-m+1;
        
        i=i+m;
        
        for(int k=0;k<255;k++){
            if(table[k].c==str[i]){
                i=i+table[k].len-m;
              
                break;
            }
        }


    }
    return -1;
}
MyString::MyString()
{
    int j;
    str=new char[100];
    pattern=new char[10];

    cin>>str;
    cin>>pattern;

    n=strlen(str);
    m=strlen(pattern);
    


    table=new lookup[256];
   
    for(int i=0;i<255;i++)
    {
        j=0;
        while(j<m-1)
        {
            if(pattern[j]==char(i)) break;
            j++;
        }

        if(j==(m-1)) table[i].len=m;

        else table[i].len=m-1-j;

        table[i].c=char(i);
    }
}
int main()
{
MyString str;
cout<<"Index is "<<str.match()<<endl;
    
    return 0;
}

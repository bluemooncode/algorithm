#include<iostream>

using namespace std;

struct node{
    int data,bfactor,rheight,lheight;
    struct node *llink,*rlink;
};
typedef struct node node;


class Tree{
    public:
    node *root,*prevnode,*unbalencednode;
        Tree()
        {
            prevnode=unbalencednode=root=NULL;

        }
        void addNode(int);
        void disp(node *);
        int updateBalenceFactor(node *);
        void rotate(int,node*,node *);
        void balenceTheTree(int);
        void traverse(node*);
       
};
void Tree::traverse(node *r){
    if(r==NULL) return;
    
    traverse(r->llink);
    traverse(r->rlink);
    if(r->bfactor>1||r->bfactor<(-1)&&unbalencednode==NULL){
        unbalencednode=r;
        cout<<unbalencednode->data<<endl;
        return;
    }
    
}
void Tree::balenceTheTree(int num){
   
   unbalencednode=prevnode=NULL;
    traverse(root);
    //getting previous node
    if(unbalencednode!=NULL){
        node* temp=root;
        while(temp!=unbalencednode){
            prevnode=temp;
            if(unbalencednode->data>temp->data) temp=temp->rlink;
            else temp=temp->llink;
        }
        cout<<prevnode->data<<" "<<unbalencednode->data;
        rotate(num,this->unbalencednode,this->prevnode);
    }
    else{
        cout<<"no";
    }
    
}
void Tree::rotate(int n,node* unbalenced,node* prev){
    char ar[2];
    node *temp=unbalenced,*temp2,*temp3,*newroot=unbalenced;
    int i=0,j;
    while(temp!=NULL&&i<2){
        
        if(temp->data>n){
            ar[i]='l';
            temp=temp->llink;
        }
        else{
            ar[i]='r';
            temp=temp->rlink;
        }
        i++;
    }
    cout<<ar[0]<<ar[1]<<endl;
    if(ar[0]=='l'&&ar[0]=='l'){
        
        temp=unbalenced->llink->rlink;
        newroot=unbalenced->llink;
        unbalenced->llink->rlink=unbalenced;
        unbalenced->llink=temp;
        
         
    }
    
    else if (ar[0]=='r'&&ar[1]=='r')
    {
        
        temp=unbalenced->rlink->llink;
        newroot=unbalenced->rlink;
        unbalenced->rlink->llink=unbalenced;
        unbalenced->rlink=temp;
        root=newroot;

    }
    else if(ar[0]=='r'&& ar[1]=='l'){
        cout<<"Rl";
       /* j=unbalenced->data;
        unbalenced->data=unbalenced->rlink->llink->data;
        unbalenced->rlink->llink->data=j;
        temp=unbalenced->rlink->llink->llink;
        temp2=unbalenced->rlink->llink->rlink;
        temp3=unbalenced->llink;
        unbalenced->llink=unbalenced->rlink->llink;
        unbalenced->rlink->llink=temp2;
        unbalenced->llink->rlink=temp;
        unbalenced->llink->llink=temp3;*/
        

    }
    else if(ar[0]=='l'&& ar[1]=='r'){
        cout<<"Lr";
        /*j=unbalenced->data;
        unbalenced->data=unbalenced->llink->rlink->data;
        unbalenced->llink->rlink->data=j;
        temp=unbalenced->llink->rlink->llink;
        temp2=unbalenced->llink->rlink->rlink;
        temp3=unbalenced->rlink;
        unbalenced->rlink=unbalenced->llink->rlink;
        unbalenced->llink->rlink=temp;
        unbalenced->rlink->llink=temp2;
        unbalenced->rlink->llink=temp3;*/
        
    }
    prev=newroot;
    
}
int Tree::updateBalenceFactor(node *r){
    if(r==NULL) return 0;

    r->rheight+=updateBalenceFactor(r->rlink)+1;
    r->lheight+=updateBalenceFactor(r->llink)+1;

    r->bfactor=r->lheight-r->rheight;

    return(r->lheight>r->rheight?r->lheight:r->rheight);
}
void Tree::disp(node *r){

    if(r!=NULL){
        disp(r->llink);
        cout<<r->data<<" Bf "<<r->bfactor<<" rheight "<<r->rheight<<" lheight "<<r->lheight<<endl;
        disp(r->rlink);
        
        
    }
}
void Tree::addNode(int n){

            if(root==NULL){
                root=new node;
                root->data=n;
                root->llink=root->rlink=NULL;
            }
            else{
                
                node *newnode=new node;
                newnode->llink=newnode->rlink=NULL;
                newnode->lheight=newnode->rheight=0;
                newnode->bfactor=0;
                newnode->data=n;
                node *temproot=root,*prev=root;
                while(temproot!=NULL){
                    prev=temproot;
                    if(temproot->data>n){
                        temproot=temproot->llink;
                    }
                    else{
                        temproot=temproot->rlink;
                    }
                }
             
                
                if(n<prev->data){
                    prev->llink=newnode;
                    cout<<"L "<<prev->llink->data<<" "<<prev->data<<endl;
                }
                else{
                    prev->rlink=newnode;
                    cout<<"R "<<prev->rlink->data<<" "<<prev->data<<endl;
                }
            }
}
int main(){
Tree rootnode;
//int ar[10]={11,23,4,56,7,89,1,45,3,6},n=10;
int ar[5]={11,23,45,50},n=4;
for(int i=0;i<n;i++){
    rootnode.addNode(ar[i]);
}
rootnode.updateBalenceFactor(rootnode.root);
rootnode.disp(rootnode.root);
rootnode.balenceTheTree(50);
cout<<endl;
rootnode.disp(rootnode.root);


    return 0;
}
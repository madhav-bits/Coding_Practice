#include <iostream>
#include<cstdlib>

using namespace std;


struct node{
    int val;
    node* left;
    node* right;
    
};

node* newNode(int val){
    node* root=new struct node;//Didn't understand this line's significance. I think this is how objects are created.
    root->left=NULL;
    root->right=NULL;
    root->val=val;
    return root;
}

int maxWidthTree(node* root){
    cout<<"hi"<<endl;
}


int main()
{
   cout << "Hello World" << endl;
   node* root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   maxWidthTree(root);
   cout<<"End"<<endl;
   return 0;
}


#include <iostream>
#include<cstdlib>

using namespace std;

//PreOrder Printing of a Tree's elements using recursive algorithm.

struct node{
    int val;
    node* left;
    node* right;
};

struct node* newNode(int value){
    node* root= new struct node;
    root->val=value;// Here pointer points to the new address alloted to the value and saves it in the pointer. Creating variable for the integer isn't required.
    root->left=NULL;//Here pointer points to the new address alloted to the NULL value and also saves this address in the pointer.
    root->right=NULL;//Here pointer points to the new address alloted to the NULL value and also saves this address in the pointer.
    return root;
}

int preOrder(node* root){
    if (root==NULL) 
        return 0;
    preOrder(root->left);
    cout<<"ss: "<<root->val<<endl;
    preOrder(root->right);
    return 0;
}

int main()
{
   cout << "Hello World" << endl;
   node * root=newNode(1);
   root->left= newNode(2);
   root->right=newNode(3);
   root->left->left= newNode(4);
   cout<<root->val<<endl;
   preOrder(root);
   
   return 0;
}


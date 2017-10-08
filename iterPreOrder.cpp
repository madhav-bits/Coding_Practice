#include <iostream>
#include<cstdlib>
#include<stack>


using namespace std;

//PreOrder Printing of a Tree's elements using iterative algorithm.

struct node{
    int val;
    node* left;
    node* right;
};

struct node* newNode(int value){
    node* root= new struct node;
    root->val=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}


void iterPreOrder(node* root){
    stack<node*> s;
    s.push(root);
    do{
        node* temp=s.top();
        cout<<temp->val<<endl;
        s.pop();
        if(temp->right!=NULL)
            s.push(temp->right);
        if(temp->left!=NULL)
            s.push(temp->left);
    }
    while(s.size()!=0);
    return ;
}

int main()
{
   cout << "Hello World" << endl;
   node * root=newNode(10);
   root->left= newNode(8);
   root->right=newNode(2);
   root->left->left= newNode(3);
   root->left->right= newNode(5);
   root->right->left=newNode(2);
   iterPreOrder(root);
   
   return 0;
}


#include <iostream>
#include<cstdlib>
#include<stack>
#include<queue>


using namespace std;

//Level Order Printing of a Tree's elements using iterative algorithm.

struct node{
    int val;
    node* left;
    node* right;
};

struct node* newNode(int value){
    node* root= new struct node;// Initializing a node pointer and equating to the newly created heap memory of size "node".
    root->val=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}


void levelOrderTree(node* root){
    queue<node*> q;
    q.push(root);
    do{
        node* temp=q.front();
        cout<<temp->val<<endl;
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    while(q.size()!=0);    
    
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
   root->right->right=newNode(1);
   levelOrderTree(root);
   
   return 0;
}

// Exptected output is: 10,8,2,3,5,2,1


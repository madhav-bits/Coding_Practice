#include <iostream>
#include<cstdlib>

using namespace std;

//Insertion Sort Algorithm.

struct node{
    int val;
    node* left;
    node* right;
};

struct datas{
    int val1;
    int val2;
    char name;
};

struct node* newNode(int value){
    node* root= new struct node;
    root->val=value;// Here pointer points to the new address alloted to the value and saves address in the pointer. Creating variable for the integer isn't required.
    root->left=NULL;//Here pointer points to the new address alloted to the NULL value and also saves this address in the pointer.
    root->right=NULL;//Here pointer points to the new address alloted to the NULL value and also saves this address in the pointer.
    return root;
}

int main()
{
   cout << "Hello World" << endl;
   node * root=newNode(1);
   root->left= newNode(2);
   root->right=newNode(3);
   cout<<root->val<<endl;
   datas data1;
   datas data2;
   data1.val1=10; data1.val2=11; data2.val1=12; data2.val2=13;
   cout<<data1.val1<<endl;
   typedef long int* pint; // Works sort of alias.
   pint x;// Now x is a long int pointer.
   *x=32;// Pointer is directly pointing to the address where this value is stored, without the need of a variable.
   cout<<*x<<endl;
   return 0;
}


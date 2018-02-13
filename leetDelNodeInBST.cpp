/*
*
//*********************************************************450. Delete Node in a BST.************************************************

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

	
	
	
	
	
	
	

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,3,6,2,4,null,7]
3

[20,10,30,5,15,25,35,3,7,12,17,null,null,32,37]


[20,10,30,5,15,25,35,3,7,12,17,null,null,32,37]
35


[5,3,6,2,4,null,7]
7


// Time Complexity: O(logn).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).			
// This algorithm finds the value to be replace, then finds the next greatest or smallest to repalce it, then deletes the replacing value's node,
// through recursive calls.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            if(!root->right){
                TreeNode* left=root->left;
                delete root;
                return left;
            }
            else{
                TreeNode* right=root->right;
                while(right->left)
                    right=right->left;
                swap(root->val,right->val);
                root->right=deleteNode(root->right, key);
                return root;
            }
        }
            
        if(root->val>key) root->left=deleteNode(root->left, key);						// Passing to the left child.
        if(root->val<key) root->right=deleteNode(root->right, key);
        
        return root;
    }
};



//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).			
// This algorithm finds the node to replace, then finds the next greatest or smallest to repalce it, then deletes the replacing value's node. There
// were lot of cases to look after. This algorithm had passed 79/85 cases.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root;
        TreeNode* repl=NULL;
        TreeNode* prev2=root;
        int a=0;
        if(root==NULL || (root->val==key && root->left==NULL && root->right==NULL) )
            return NULL;
        while(temp!=NULL && temp->val!=key){
            prev2=temp;
            if(temp->val<key){
                a=1;
                temp=temp->right;
            }
            else{
                temp=temp->left;
                a=-1;
            }
        }
        if(temp==NULL) return root;
        if(temp->left==NULL && temp->right==NULL){
            if(a==1)
                prev2->right=NULL;
            else
                prev2->left=NULL;
            return root;
        }
            
        TreeNode* lt=temp->left;
        TreeNode* rt=temp->right;
        TreeNode* prev=temp;
        if(lt!=NULL){
            cout<<"Inside left if "<<endl;
            while(lt->right!=NULL){
                prev=lt;
                lt=lt->right;
            }
            if(lt->left!=NULL){
                repl=lt;
                prev->right=lt->left;
            }
            else if(lt->left==NULL){
                repl=lt;
                if(prev!=temp){
                    prev->right=NULL;
                    //lt=NULL;
                }
                else
                    prev->left=NULL;
                
            }
        
        }
        else if(rt!=NULL){
            cout<<"Inside right if "<<endl;
            prev=temp;

            while(rt->left!=NULL){
                prev=rt;
                rt=rt->left;
            }
            if(rt->right!=NULL){
                repl=rt;
                prev->left=rt->right;
            }
             else if(rt->right==NULL){
                 repl=rt;
                 if(prev!=temp){
                     prev->left=NULL;
                     //rt=NULL;
                 }
                 else
                     prev->right=NULL;
             }
        }
        temp->val=repl->val;
        return root;
    }
};
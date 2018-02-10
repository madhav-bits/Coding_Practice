/*
*
//****************************************************623. Add One Row to Tree.*******************************************

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root 
node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with 
value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left 
subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is 
no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new 
root's left subtree.

Example 1:
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Example 2:
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.
[4,2,6,3,1,5,null,null, 10, null,11,null,12]
1
3


[1,4,null,2,6,3,1,5,null,null,10,null,11,null,12]
1
2


[1,1,1,4,null,null,null,2,6,3,1,5,null,null,10,null,11,null,12]
1
4




// Time Complexity: O(n).
// Space Complexity: O(logn).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).			
// This algorithm is Level Order Traversal using queues. Saving all the nodes at level-"d-1" and making their child as left and right child of
// newly created left and right child of the nodes at level-"d-1". Strange is that the algorithm using recursive formulation performs well in 
// this question. Eventhough it iterates through the entire tree.


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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root==NULL) return root;
        if(d==1){													// If, "d=1", we make root as the left child as the left child of new node.
            TreeNode* temp= new TreeNode(v);
            temp->left=root;
            return temp;
        }
        else{
            queue<TreeNode*> q;
            q.push(root);
            int level=1, count=0;
            int num=1;
            while(!q.empty()){										// Doing a Level Order Traversal, saving nodes at a level in queue.
                if(level==d-1)										// As, we we need is nodes at level-"d-1".
                    break;
                TreeNode* temp2=q.front();
                q.pop();
                count++;
                if(temp2->left!=NULL) q.push(temp2->left);
                if(temp2->right!=NULL) q.push(temp2->right);
                if(count==num){
                    level++;
                    num=q.size();
                    count=0;
                }
            }
            
            while(!q.empty()){										// By here, we have all nodes in the level- "d-1". We change their child.
                TreeNode* temp3=q.front();
                q.pop();
                TreeNode* lt=temp3->left;							// This is my way of chaning values.
				TreeNode* rt=temp3->right;							// Saving the curr. child.
                temp3->left=new TreeNode(v);						// Updating the left, right child.
                temp3->right= new TreeNode(v);
                temp3->left->left=lt;								// Updating child of left and right childs of node at level-"d-1".
                temp3->right->right=rt;
				/*       											// Another way to change values, improved perf. by 1 ms.
				TreeNode* lt=new TreeNode(v); TreeNode* rt=new TreeNode(v);
                lt->left=temp3->left;
                rt->right=temp3->right;
                temp3->left=lt;
                temp3->right=rt;
				*/
            }
            return root;											// Returning the node of the tree.
        }
            
            
    }
};
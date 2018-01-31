/*
*
//*****************************************************662. Maximum Width of Binary Tree.**********************************************

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

//These are the cases I had created, tweaked and worked on.
[1,3,2,5,null,null,9, 6,null,7,null, null,6,null,9]
[2,3,null,1,2,1,null,null,4]

// Time Complexity: O(n).
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(logn).
// Here I am assigning values to each node indicating it's distance from the root, towards left or right and claculating the distance b/w
// cornermost(edge) nodes(max and min. values in a level). Calc. the maxm. distance b/w edge nodes of all the levels which is the maxm. width of
// the tree.



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
    vector<vector<int>>u;					//Vector whose value at index "i" contains the edge values for height "i-1"(root's height=0).
    void preOrderTrav(TreeNode* temp, int height, int val,int side){
        if(temp==NULL) return ;
        if(u.size()== height)									//Creating a vector entry to save the edge positions of a new level.
            u.push_back({INT_MAX,INT_MIN});
        u[height][0]=min(u[height][0], val);
        u[height][1]=max(u[height][1], val);
        
        if(side==0){											//Assigning vlaues of the left subtree of root.
            preOrderTrav(temp->left,height+1, 2*val,0);
            preOrderTrav(temp->right,height+1, 2*val+1,0);
        }
        
        else if(side==1){										//Assigning vlaues of the right subtree of root.
            preOrderTrav(temp->left,height+1, 2*val-1,1);
            preOrderTrav(temp->right,height+1, 2*val,1);
        }
        else{													//This condition is for the root.
            preOrderTrav(temp->left,height+1, val-1,0);
            preOrderTrav(temp->right,height+1, val+1,1);
        }
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        preOrderTrav(root,0,0,-1);
        int maxm=INT_MIN;
        for(int i=0;i<u.size();i++){						//At each row Index-0 stores left end value and Index-1 stores right end value.
            //cout<<"The level is: "<<i+1<<" and width is: "<<u[i][1]-u[i][0]<<" max is: "<<u[i][1]<<" and min. is: "<<u[i][0]<<endl;
            if(u[i][1]>0 && u[i][0]<0)						//If both edge values are belongs to left and right subtrees of root.
                maxm=max(maxm,u[i][1]-u[i][0]);
            else											//If both edge values are belongs to same side of(subtree) of root.
                maxm=max(maxm,abs(u[i][1]-u[i][0])+1);		//Calc. the diff. b/w edge values to get width of that level.
        }
        //cout<<"The result is: "<<maxm<<endl;
        return maxm;										//Returning the maxm. width of the tree.
    }
};
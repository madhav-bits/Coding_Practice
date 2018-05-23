/*
*
//******************************************************538. Convert BST to Greater Tree.***********************************************

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key 
plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[20,10,15,5,null, 12,17]
[20,10,15,5,null, 12,17,4,8,null,null,null,null,null,null,6,9]
[]
[1,2,null,3,null,4,null,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based solution. At each step we forward the sum of greater valued nodes to a right child, it adds it's 
// value to the sum and returns the udpated sum. The parent node update it's value using the udpated sum and forward the sum to the left child, it 
// returns the updated sum, which we will return from the curr. parent node.





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
    int updateVal(TreeNode* node, int sum){
        if(node==NULL) return sum;											// If NULL, return the sum.
        int temp;
        temp=updateVal(node->right, sum);                       			// Adding values from parent and right child.
        //cout<<"sum is: "<<sum<<" and the right child val is: "<<temp<<endl;
        //cout<<"node value: "<<node->val<<" changed to: "<<node->val+temp<<endl;
        node->val+=temp;													// Updating the value of curr. node.
        sum=node->val;                                              		// Updating the sum value to be passed to the left child.
        //cout<<"Sum after right is: "<<sum<<endl; 
        sum=updateVal(node->left, sum);                        				// Adding values form left child.
        
        //cout<<"Returning the sum: "<<sum<<endl;
        return sum;                                             			// Returning the overall sum from the curr. node and it's child.
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        updateVal(root,sum);
        return root;
    }
};



//***************************************************************************************************************************************
//This is the same as the above solution, just that all the redundant variables are removed.
//***************************************************************************************************************************************




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
    int updateVal(TreeNode* node, int sum){
        if(node==NULL) return sum;										// If node==NULL, return sum.
        //int temp;
        node->val+=updateVal(node->right, sum);                      	 // Adding values from parent and right child and updating curr. node.
        //cout<<"sum is: "<<sum<<" and the right child val is: "<<temp<<endl;
        //cout<<"node value: "<<node->val<<" changed to: "<<node->val+temp<<endl;
        //node->val+=temp;
        //sum=node->val;                                              	
        //cout<<"Sum after right is: "<<sum<<endl; 
        return updateVal(node->left, node->val);                     	// Adding values form left child and returning the sum.
        
        //cout<<"Returning the sum: "<<sum<<endl;
        //return sum;                                             		// Returning the overall sum.
        
    }
    TreeNode* convertBST(TreeNode* root) {
        updateVal(root,0);
        return root;
    }
};
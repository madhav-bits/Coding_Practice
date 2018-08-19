/*
*
//*******************************************889. Construct Binary Tree from Preorder and Postorder Traversal.*************************************

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,4,1,2]
[1,4,2,3]


[1,2,4,3,5,7,6]
[4,2,7,5,6,3,1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. We use preOrder to track curr. node we are working on. Post Order to seggregate #nodes in left child and 
// right child. Upon creating the node with val. in preIndex. If preIndex is only one in the range of values of itself and it's child, we
// just return the node. If not we inc. the preIndex to get the left child of curr. node, We find this val. in postOrder, based on that we 
// classify left and right child range. Give recursive call to get their children formed. 








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
    
    TreeNode* makeTree(vector<int>&pre, vector<int>&post,int &index,int l,int h){
        if(index>=pre.size() || l>h) return NULL;							// If curr. node with those range of values doesn't exist.
        TreeNode* node=new TreeNode(pre[index]);							// Creating curr. node with valid range of values.
        // cout<<"Inside the fn. with node val: "<<node->val<<" l: "<<l<<" and h: "<<h<<endl;
        index++;															// Inc. the index to get left child value.
        if(index>=pre.size()) return node;									// If there is no left child(out of bound index), return curr. node.
        if(l==h){															// If this is val. in this range, then return curr. node.
            // cout<<"One node, so return"<<endl;
            return node;
        } 
        int i;																// Stores index of left child in postOrder.
        for(i=l;i<=h;i++){													// Calc. left child index in postOrder.
            // cout<<"Inside iter. with i: "<<i<<endl;
            if(post[i]==pre[index]) break;									// Found left child index.
        }
        // cout<<"Matching index: "<<i<<endl;
        node->left=makeTree(pre,post,index,l,i);							// Calling fn. to create left child.
        // cout<<"Called right with l: "<<i+1<<" and h: "<<h-1<<" where l: "<<l<<" and h: "<<h<<endl;
        node->right=makeTree(pre,post,index,i+1,h-1);						// Calling fn. to create right child.		
        return node;														// Returning the curr. node with both child created.
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int index=0;														// Used to track on node we are currently working on.
        return makeTree(pre,post,index,0,post.size()-1);					// Calling fn. to create Binary Tree.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration and Stack based. Here, we iterate through preOrder array, forming parent child rlns, pushing the curr. node, as 
// we need to create it's child. Here, we track the first active value in postOrder, which doesn't have anny child or had been 
// created in the sln. If, we reach any such point we pop it from the stack, as it's got both child created/ no child for it. We iterate till 
// preOrder had been iterated.






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
    
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size()==0) return NULL;										// If empty tree provided, return NULL.
        stack<TreeNode*>st;													// Stores nodes for which child needs to be formed.
        TreeNode* root=new TreeNode(pre[0]);								// Creating the root of the Tree.
        int postIndex=0;													// Tracks the first node which had got child created/ no child exists.
        st.push(root);														// Pushing root into stack.
        for(int i=1;i<pre.size();i++){										// Iter. through preOrder array.
            TreeNode* curr= new TreeNode(pre[i]);							// Creating curr. node.
            if(st.top()->left==NULL) st.top()->left=curr;					// If left child hadn't been created, make curr. node as left chlid.
            else st.top()->right=curr;										// Else, make curr. node as right child.
            st.push(curr);													// Push curr. node into stack( As it's child needs to be Created).
            while(!st.empty() && postIndex<=post.size() && post[postIndex]==st.top()->val){// If top node has last child/both child formed.
                postIndex++;												// Inc. the postIndex.
                st.pop();													// Pop the top node from the stack.
            }	
        }
        return root;														// Return the root of the tree formed.
        
    }
};
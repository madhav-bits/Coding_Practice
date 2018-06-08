/*
*
//******************************************************145. Binary Tree Postorder Traversal.***********************************************

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,2,3,6,4,5,null,7]


[1,2,3,4,null,null,5]

[]


[1,2,3,4,null,null,5]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recurison based. I do a Pre Order Traversal, but store the result in stack in the order the nodes are visited, at each step
// the child are pushed into stack in the order(NRL) whose values on reversing would form (LRN) form of Post Order. After the entire iteration,
// I reverse the stack to get the result.






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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return res;
        stack<int>s;																// Which stores the result temp.
        stack<TreeNode*>st;															// Which stores the nodes.
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            s.push(temp->val);														// Storing the visited values temp.
            if(temp->left!=NULL) st.push(temp->left);								// Pushing left child into stack.
            if(temp->right!=NULL) st.push(temp->right);								// Pushing right child into stack.
        }
        
        while(!s.empty()){															// Reversing the stack values.
            res.push_back(s.top());													// Push values onto result vector.
            s.pop();
        }
        return res;
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS 	AN UGLY METHOD, BUT WORKS.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recurison based. At each step, if a node has child, I push the child into stack, if it doesn't have child, push the node's
// val. into result vec. To prevent repushing the nodes into stack once again, when child are pushed into stack, the child are detached from 
// parent node.







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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return res;
        stack<int>s;
        stack<TreeNode*>st;														// Stores the nodes.
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            if(temp->left==NULL && temp->right==NULL){							// If a node doesn't have child, push the node's value into res.
                res.push_back(temp->val);
                st.pop();														// Pop the node from the stack.
            }
            else{																// If a node has any child, push the child into stack.
                //s.push(temp->val);
                
                if(temp->right!=NULL) st.push(temp->right);
                if(temp->left!=NULL) st.push(temp->left);
                temp->left=NULL; temp->right=NULL;								// Detach child from curr. node, to prevent repushing the nodes.
            }
        }
        
        return res;																// Returning the final result vec.
    }	
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recurison based. I push all the left child in a sequence into stack. When NULL encountered, I check whether prev. non-NULL
// node has a right child, if it has push it into stack, go on pushing right child's chlid onto stack. If not push the curr. node's val onto
// stack. Then we set the condition, such that node's value isn't stored twice. After the entire iteratin,we have our final res. vec.









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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;																// Final result vec.
        stack<TreeNode*>st;																// Stores all nodes.
        TreeNode* curr=root, *prev=NULL;												// Curr. & prev. scanning node.
        while(curr || !st.empty()){									
            if(curr ){																	// If curr. is not NULL. we push it into stack.
                //cout<<"Inside if with curr.: "<<curr->val<<endl;
                st.push(curr);
                curr=curr->left;														// Iteratively go deep into tree, on left childs.
            }
            else{
                TreeNode* temp=st.top();												// Top of stack(Prev. non-NULL node).
                //cout<<"Inside if with top: "<<curr->val<<endl;
                if(temp->right && temp->right!=prev){									// If the right child isn't visited, move to right child.
                    curr=temp->right;
                }
                else {																	// If right child doesn't exist/just visited(val. stored).
                    res.push_back(temp->val);											// Push curr. node's val. into final result vec.
                    st.pop();															// Pop it from stack.
                    prev=temp;															// Make the curr. stored node as prev. node.
                }
            }
            
            
        }
        return res;																		// Return the final result vec.
    }
};
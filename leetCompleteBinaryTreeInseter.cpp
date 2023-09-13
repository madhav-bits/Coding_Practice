/*
*
//************************************************919. Complete Binary Tree Inserter.**************************************************

https://leetcode.com/problems/complete-binary-tree-inserter/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["CBTInserter","insert","insert","get_root"]
[[[1,2]],[3],[4],[]]
["CBTInserter","insert","insert","insert","insert","get_root","insert","insert","get_root"]
[[[1,2,4,5,6,7,8,9,10]],[11],[12],[13],[14],[],[15],[16],[]]
["CBTInserter","insert","insert","insert","get_root"]
[[[1]],[2],[3],[4],[]]
["CBTInserter","insert","insert","insert","get_root"]
[[[1]],[2],[3],[4],[]]



// Time Complexity: O(1).													// For every insert, getRoot oper., O(n) for initial setup.
// Space Complexity: O(n).													// n-Total #nodes in the tree.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).													// For every insert, getRoot oper., O(n) for initial setup.
// Space Complexity: O(n).													// n-Total #nodes in the tree.	
// This algorithm is Queue based. We use Queue to do Level Order Traversal and pop those nodes which have both children. Thus at the end of traversal we have
// leave nodes in the Queue. For every req. to insert Node in tree, we get the leftmost node with either or both of child missing, we create child node
// accordingly and pop the node if both the child are present now. For getRoot request we simply return the root ptr to the tree.







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root=NULL;
    queue<TreeNode*>q;
    CBTInserter(TreeNode* node) {
        root=node;
        
        // Catch Leaves.
        q.push(node);
        while(!q.empty()) {													// Level Order Traversal.
            if(q.front()->left) q.push(q.front()->left);					// Push non-empty nodes into Queue.
            if(q.front()->right) q.push(q.front()->right);
            if(q.front()->left && q.front()->right) q.pop();				// If both child are present we pop curr. node.
            else break;														// If either or both child are NULL, we break the loop.
        }
        
    }
    
    int insert(int val) {
        int res=q.front()->val;
        if(!q.front()->left) {												// If left child not present, we create new one.
            q.front()->left=new TreeNode(val);
            q.push(q.front()->left);
        }
        else if(!q.front()->right) {										// If right child not present, we create new one.
            q.front()->right=new TreeNode(val);
            q.push(q.front()->right);
            q.pop();														// We pop curr. node as both child are present now.
        }
        return res;
    }
    
    TreeNode* get_root() {
        return root;														// Returning the root node of the Tree.
    }
};


/*
*
//******************************************************559. Maximum Depth of N-ary Tree.***********************************************

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a 3-ary tree:

 


 
We should return its max depth, which is 3.

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Not so cricial test cases I had worked on.



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate through all nodes, extract max. depth from each children, add plus 1 to it and return it. If 
// a node doesn't have any child, return 1.




/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    int maxDepth(Node* root) {	
        if(!root) return 0;													// If empty node, return 0.
        int maxm=0;															// Tracks maxm. depth of the children.
        for(int i=0;i<root->children.size();i++){							// Iter. through all children.
            int res=maxDepth(root->children[i]);							// Extracting depth from each child.	
            maxm=max(res,maxm);												// Maintaining max. depth.
        }
        return maxm+1;														// Returning max. depth of the curr. node.
    }
};
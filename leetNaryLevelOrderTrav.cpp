/*
*
//******************************************************429. N-ary Tree Level Order Traversal.***********************************************

Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example, given a 3-ary tree:

 


 
We should return its level order traversal:

 

 

[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Queue based. We start from the root, we collect all it's children in a single iteration. In the next iteration we visit, all
// it's chlidren and push them into result vector, at the same time, we push all curr. level's children into queue to be pushed into result 
// vector in the next iteration. This way, we collect each level's elem. in each iteration.







/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;												// Stores the final result.
        if(!root) return res;												// If empty tree provided, return empty vector.
        queue<Node*>q;														// Stores curr. and next level's nodes to be visited.
        q.push(root);														// Start with the root.
        while(!q.empty()){													// Until all nodes are visited.
            int len=q.size();												// #Elem. in curr. level.
            res.push_back({});												// We add an empty vector into curr. level in result.
            for(int i=0;i<len;i++){											// Iter. over all elem. in curr. level.
                Node* curr=q.front();
                q.pop();	
                res[res.size()-1].push_back(curr->val);						// Pushing curr. level's node's values into final result vector.
                for(int j=0;j<curr->children.size();j++)					// Iter. over each node's children list and pushing them into queue.
                    q.push(curr->children[j]);
            }
            
            
        }
        return res;															// Returning the final result vector with all tree node's values.
    }
};
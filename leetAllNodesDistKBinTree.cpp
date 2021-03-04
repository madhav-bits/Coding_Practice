/*
*
//******************************************************863. All Nodes Distance K in Binary Tree.*************************************************

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[3,5,1,6,2,0,8,null,null,7,4]
5
2


[0,2,1,null,null,3]
3
3



// Time Complexity: O(n).  
// Space Complexity: O(n).													// Map to store link from child to parent and track visited nodes.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).													// Map to store link from child to parent and track visited nodes.
// This algorithm is DFS,BFS and observation based. Here, while calculating the K distance from target node, we also travel from child to parent. So, in 
// the first iteration, we store the link b/w child and parent. In the second iteration we start BFS from the target node, we travel towards child, parent
// for K steps. We take the values of all nodes in the queue after K steps.









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
    
    void linkParent(TreeNode* node, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>&m){	// Linking child to parent.
        if(!node) return ;
        m[node]=prev;
        linkParent(node->left, node, m);
        linkParent(node->right, node, m);
        return ;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        linkParent(root, NULL, parent);										// Links child with parent.
        queue<TreeNode*>q;													// Start BFS from target node.
        q.push(target);
        unordered_set<TreeNode*>st;											// Tracks visited nodes.
        st.insert(target);													
        while(k){															// Perform BFS for K steps.
            k--;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && st.count(curr->left)==0){					// If left child is not visited, push it to queue.
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right && st.count(curr->right)==0){
                    q.push(curr->right);
                    st.insert(curr->right);
                }
                
                if(parent[curr]!=NULL && st.count(parent[curr])==0){		// If parent is not visited, push it to queue.
                    q.push(parent[curr]);
                    st.insert(parent[curr]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){													// Collecting nodes at K distance from target node.
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;															// Returning values of nodes at K distance from target node.
    }
};

/*
*
//******************************************************742. Closest Leaf in a Binary Tree.***********************************************

Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a 
leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,null,null,null,5,null,6,7,8]
4


[1,2,3,4,null,15,16,null,5,null,6,7,8]
3


[1]
1

[]
1



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the tree recursively in the first iteration. As, the shortest path to left can be on the left/right child or in any
// other child which traversed by travelling back to parent, and reaching any other leaf. We in the first iteration, extract shortest dist. to
// all nodes to closest leaves in their child. In the second iteration, we pass to each child it's shortest dist. to leat, as this path might
// be the shortest path to leaf from it's child(where it also has it's shortest to leaf from it's child already stored in map). So, we compare
// both these values and get the min. value, which is the min. dist from this node to any leaf in the tree.



// Pair's first is curr. node's shortest dist. to lef, second is the closest leaf.


//***************************************************************************************************************************************
// Another cool algo, which uses DFS+BFS to get the result. I thought of using BFS, but as it would be slightly tricky to get the parents and 
// iterating, I went ahead with the below simple algo. This is the link for that algo.
https://leetcode.com/problems/closest-leaf-in-a-binary-tree/discuss/109960/Java-DFS-+-BFS-27ms




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
    int res;														// Stores Leaf resulting in shortest dist. from target node.
    pair<int,int> findDist(TreeNode* node, unordered_map<int,pair<int,int>>&m){// Extracts closest dist. from all nodes to a leaf in it's child.
        if(!node) return make_pair(INT_MAX,-1);						// As, it's not a child, return INT_MAX.
        if(!node->left && !node->right){							// As it's a child, return 0, create a pair with 0 and return it.
            pair<int,int>q=make_pair(0,node->val);					// Create pair with dist. to leaf=0, curr. node value.
            m[node->val]=q;											// Update map.
            return q;  
        } 
        pair<int,int> lt=findDist(node->left,m);					// Extract shortest dist. from both child.
        pair<int,int> rt=findDist(node->right,m);
        pair<int,int>p;
        if(lt.first<rt.first) p=make_pair(lt.first+1,lt.second);	// Extract min. dist of the both.Add 1 and assign to curr. node.
        else p=make_pair(rt.first+1,rt.second);
        
        m[node->val]=p;												// Update the map.
        return p;													// Return the pair.
        
    }
		
																	// Extract shortest dist. from target node to a leave in tree.
    void getDist(TreeNode* node, pair<int,int>&p, int &target,unordered_map<int,pair<int,int>>&m){
        if(!node) return ;
        pair<int,int>temp;
        if(p.first<m[node->val].first) temp=p;						// If shortest dist. from leaf>shortest dist. from parent,temp=val. from parent.
        else temp=m[node->val];										// If shortest dist. from leaf<shortest dist. from parent,temp=val. from child.
        
        if(node->val==target){										// If target reached, return temp's second value(Leaf resulting in least value).
            res=temp.second;
            return ;
        } 
        temp.first++;												// Inc. the dist. to shortest path by one and passing it to child.
        getDist(node->left, temp,target,m);							// Checking for target node in the child.
        getDist(node->right, temp, target,m);
    }
	
	
	
    int findClosestLeaf(TreeNode* root, int k) {
        if(!root) return 0;
		unordered_map<int,pair<int,int>>m;							// Tracks shortest dist. from a curr. node and leaf resulting in short dist.			
        findDist(root,m);											// Extracts closest dist. from all nodes to a leaf in it's child.
        getDist(root, m[root->val],k),m;							// Extract shortest dist. from target node to a leave in tree.
        return res;													// Returning the closest leave to target node.
    }
};

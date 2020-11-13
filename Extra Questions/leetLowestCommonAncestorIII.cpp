/*
*
//****************************************1650. Lowest Common Ancestor of a Binary Tree III.********************************************

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[1,2]
1
2



// Time Complexity: O(logn).  
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(logn).	
// This algorithm is HashSet based. Here, since we want a lowest common ancestor, this would be the first common node in both node's
// path to root node. So, we iter. from one of the given nodes to root node, we store them in hash set, we travel from other node
// to root node, if the node in path is previously encountered in the path of other node, this is the LCAncestor.







/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*>st;												// Stores nodes encountered in the path to root node.
        Node* node=p;
        while(node){														// Iter. from first node to root node.
            st.insert(node);												// Store the nodes in path to hash set.
            node=node->parent;
        }
        node=q;
        while(node){														// Iter. from second node to root node.
            if(st.count(node)) return node;									// If node in path is encountered in other path, return it.
            node=node->parent;
        }
        return NULL;
    }
};
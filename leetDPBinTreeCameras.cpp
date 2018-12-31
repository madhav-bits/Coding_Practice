/*
*
//************************************************************968. Binary Tree Cameras.*****************************************************

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera 
placement.

Note:

1) The number of nodes in the given tree will be in the range [1, 1000].
2) Every node has value 0.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.




[0,1,null,2,5,null,3,8,null,4,7,10,null]



[0,1,null,2,5,11,3,8,null,4,7,10,12]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. We go recursively into children, we build from the bottom. As, here the placement of cams effects
// it's adjacent nodes, there are only three states to take care of. So, at every stage, we calc. these three values and return it to it's parent.
// First is #cams req. to cover this subtree with cam being placed on this node.
// Second is #cams req. to cover this subtree with no cam on this node.
// This is #cams req. to ceratinly cover this subtree except curr. node(uncertainly), which would be covered by it's parent node.
// For the first one, since cam on this node, child may/maynot have cams on them. We extract min. of those 3 cases from both chlid and add 1.
// For second one, there is no cam on this node, any one of child has to have cam to cover curr. node and other may/may not have cam on it. Get
// min. of those two cases and assign it to curr. node.
// Here, as parent covers curr. node, child may/may not have cams in them. We take min. of each side and add both the values and assign it to curr. 
// node.



//***********************************************************I SOLVED THIS UNEXPECTEDLY.*************************************************



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
    
    struct Data{
        int used1;												// Stores #Cameras used to cover this subtree, with no cam on this node. 
        int used2;												// Stores #Cameras used to cover this subtree, with a cam on this node.
        int unused;												// Stores #Cameras used to cover this subtree, with it's parent's cam covering 
																// this node, child may/maynot have cams.
        Data(int x, int y , int z){
            used1=x;
            used2=y;
            unused=z;
        }
    };
    
    
    Data findCamera(TreeNode* node){
        if(!node) return Data(0,INT_MAX/2,0);					// As first, third vals are for no cams on node set to zero,second set to big value.
        
        // cout<<"calling left child"<<endl;
        Data lt=findCamera(node->left);							// Calling left child.
        // cout<<"calling right child"<<endl;
        Data rt=findCamera(node->right);						// Calling right child.
        int z=min(lt.used1, lt.used2)+min(rt.used1, rt.used2);	// When parent covers this node, child may/may not have cam in them. 
        int ltVal,rtVal;										// Tracks min. of both child being covered by their child/themselves.
        ltVal=min(lt.used1, lt.used2);							
        rtVal=min(rt.used1, rt.used2);
        int y=min(ltVal, lt.unused)+min(rtVal, rt.unused)+1;	// As cam is on this node, child may/may not be covered by cam till now. So, we 
																// take min. from both children and add 1 cam on this node.
        
        int x=min(lt.used2+rtVal, rt.used2+ltVal);				// As, this node don't have cam and child has to cover it, one of the child has to 
																// have cam and other may/may not have cam on it.
        // cout<<"node val: "<<node->val<<endl;
        // cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
        return Data(x,y,z);										// Returning all values.
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        Data res= Data(0,0,0);
        res=findCamera(root);									// Call to get min. cams to cover Tree.
        return min(res.used1, res.used2);						// Returning min. of both cases where all nodes are covered by itself/children.
    }
};
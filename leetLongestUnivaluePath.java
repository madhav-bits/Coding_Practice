/*
*
//******************************************************687. Longest Univalue Path.***********************************************

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass 
through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,5,4,4,8,null,null,4,null,4]
[]
[1]
[1,4,5,4,4,8,null,null,4,null,5,8,8,null,null,5,null,8]
[1,4,5,4,7,8]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. If the curr. node's val is equal to left and right node's val.Then inc. the path len. by 2 and try to update
// the maxPath. Else if curr. node val and left/right child val are equal we pass the lValue+1 or (rValue)+1 to the curr. node's parent. In the
// we start a new Path from the curr. node, where we pass 0 to the curr. node. After the entire recursion maxPath is saved in maxPath var.








/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int maxPath=0;																// Max. Univalue Path.
    
	int findPath(TreeNode node){	
        if(node==null) return 0;												// In case of NULL, return 0.
        //System.out.println("Inside findPath with node.val: "+node.val);
        int lValue= findPath(node.left);										// Extracting max path values from left and right child.
        int rValue= findPath(node.right);
        
        if((node.left!=null && node.val==node.left.val) && node.right!=null && node.val==node.right.val){
            //System.out.println("Inside findPath with node.val: "+node.val+"left: "+node.left.val+"right: "+node.right.val);
            maxPath=Math.max(lValue+rValue+2, maxPath);							//If the curr. val= left and right child val, compare to maxPath.
            return lValue>rValue?lValue+1:rValue+1;								// Return the max among child's value+1 to curr. node's parent.
        }
        else if(node.left!=null && node.val==node.left.val){					// If the left child val.= node val, then return lValue+1.
            maxPath=Math.max(lValue+1, maxPath);								// Try to update the maxPath.
            return lValue+1;
        }
        else if(node.right!=null && node.val==node.right.val){					// If the right child val.= node val, then return rValue+1.
            maxPath=Math.max(rValue+1, maxPath);								// Try to update the maxPath.
            return rValue+1;
        }
        return 0;																// In the worst case, start path from here(return 0).
        
    }
	
	
    public int longestUnivaluePath(TreeNode root) {
        findPath(root);															// Calling fn. to extract the maxPath.
        return maxPath;															// Returning the maxPath.
    }
}
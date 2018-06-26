/*
*
//**************************************************************663. Equal Tree Partition.******************************************************

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values 
after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[0,-1,1]

[5,10,10,null,null,2,3]

[1,2,10,null,null,2,20]






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion based. We do this in a single iteration using a HashMap. We extract sum of subtrees at each node, add them to the 
// value of curr. node and store in the map that this sum has occured. After the entire iteration of the tree. We check for sum/2 value, if it's 
// present, we return else false. One special case, is of sum=2, for that count of zeros have to be 1, for the result have to be true else
// we return false.








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
    int findSum(TreeNode* node, unordered_map<int,int> &m){					// Iterates through tree and stores the sum of subtrees in map.
        if(node==NULL) return 0;
        int lt=findSum(node->left,m);										// Extracting curr. node's left child's sum.
        int rt=findSum(node->right,m);
        m[lt+rt+node->val]++;												// Storing sum of subtree starting from curr. node in map.
        return lt+rt+node->val;												// Returning sum of subtree to it's parent.
    }
    
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int,int>m;											// Stores all subtrees sums.
        int sum=findSum(root,m);											// Calling fn. to extract sum of all subtrees.
        if(sum%2!=0) return false;											// If sum is odd, can't be broken into two, return false.
        if(sum==0) return (m[0]>1)?true:false;								// If sum=0, it's count has to >1, for true/else false.
        return (m.count(sum/2)==1)? true:false;								// If sum/2 had occured, then return true.
        
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the Tree 2 times. In the first iterations, we get sum of all elem. in the tree. In the second iteration, we iterate
// to get the sum/2 value subsum starting from curr. node, if the sum is target/2, in the left child, we directly return true, same
// is the case with right child, we gather sums from both children, add curr. node->val check for target/2, to return true else return false.



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
    int getSum(TreeNode* node){												// Get sum of all nodes in tree.
        if(node==NULL) return 0;
        return node->val+getSum(node->left)+ getSum(node->right);
    }
    
    bool findPart(TreeNode* node, int& subSum, int target){
        if(node==NULL) return false;										// As, there no elem. can't be broken here. so, return false.
        if(findPart(node->left, subSum,target)) return true;				// If break possible in left child, return true.
        int lt=subSum;														// sum of values in left chid.
        subSum=0;															// Refreshing, as we need to get subtree sum from right child.
        if(findPart(node->right,subSum,target)) return true;				// If break possible in right child, return true.
        // cout<<"At node: "<<node->val<<" Obtained sums: "<<lt+subSum+node->val<<endl;
        if(lt+subSum+node->val==target) return true;						// Checking for break in curr. node.
        subSum+=lt+node->val;												// Passing the subTree Sum to curr. node's parent.
        return false;														// Break not possible at this node.
    }
    bool checkEqualTree(TreeNode* root) {
        int sum=getSum(root);												// Extracts sum of all elem. of the tree.
        if(sum%2!=0) return false;											// If sum is odd, it's unbreakable into 2 parts.
        int subSum=0, subSum2=0;											// Tracks sum of subtree elem. at each stage.
        // cout<<"Target: "<<sum/2<<endl;
        return findPart(root->left,subSum, sum/2)?true: findPart(root->right,subSum2,sum/2);// Calling fn. to find breaks.
    }
};
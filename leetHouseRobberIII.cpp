/*
*
//******************************************************337. House Robber III.***********************************************

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the 
root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






[3,2,3,4,3,7,6,3,5,6,7]





// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm is Dynamic Programming based. This is a 2 level DP problem.(Thinking ahead by 2 steps.) In which we compare two states 
// of a level(that level is counted towards max. sum or not. At each level, we compare the sums of two levels and return the best of them. 


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
    
    vector<int> robMax(TreeNode* temp){
        vector<int> v(2,0), lt(2,0), rt(2,0);
        if(temp==NULL) return vector<int>(2,0);
        lt=robMax(temp->left);
        rt=robMax(temp->right);
        
        v[0]=max(lt[0], lt[1])+ max(rt[0],rt[1]);				// As, curr. is not robbed, returning the sum of max. from two child.
        v[1]=temp->val+lt[0]+rt[0];								// As curr. is robbed, returning the money if child is not robbed plus the- 
        return v;												// curr. node value.
        
    }
    
    int rob(TreeNode* root) {
        vector<int> res(2,0);                                    //zero index indicates max. value if the curr. node is not robbed.
        res=robMax(root);                                        //One index indicates max. value if the curr. node is robbed.
        return max(res[0], res[1]);								// Returning the best of the two possibilities.
        
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************TIME LIMIT EXCEEDED ERROR.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).			
// It’s recursive and expands the meaning of the function. 
// This algorithm is Dynamic Programming based. This is a  2 level DP. I didn't thought that specifically and implemented a N level DP. It failed
// on the last test case.31 st case. Passed 30 cases.





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
    
    int findSum(TreeNode* root, int height, int target){
        if(root==NULL) return 0;
        
        int sum1=findSum(root->left, height+1, 0);
        sum1+=findSum(root->right, height+1, 0);
        if(target==1){												// Parent node is robbed.
            //int lt=findSum(root->left, height+1, 0);
            //int rt=findSum(root->right, height+1, 0);
            return sum1;//lt+rt;
        }
        else{														// Parent node is not robbed.
            //int sum1=findSum(root->left, height+1, 0);			// Then the curr. node can be robbed or not robbed. 
            //sum1+=findSum(root->right, height+1, 0);
            int sum2=findSum(root->left, height+1, 1);
            sum2+=findSum(root->right, height+1, 1);
            return (sum1>sum2+root->val)?sum1:sum2+root->val;		// Returning the best of the two possiblities(curr. node incl. or not.)
        }
        
        
    }
    
    int rob(TreeNode* root) {
        int sum1=findSum(root, 0,0);								// Curr. node is not counted.
        int sum2=findSum(root, 0,1);								// Curr. node is counted.
        return sum1>sum2?sum1:sum2;									// Returning the best of the two possibilities.
        
    }
};
/*
*
//**********************************************************654. Maximum Binary Tree.***************************************************

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers 
to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].


//These are the examples I had created, tweaked and worked on.
[3,2,1,6,0,5,12,64,2,6,8,3,4,2]


// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This algorithm finds the index of max. value in the array under consideration and recursively works on left and right subarray of max. elem.

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
    TreeNode* maxBinary(vector<int> v, int start, int close){
        //cout<<"Start is: "<<start<<" and close is: "<<close<<endl;
        int index;							// To store the index of the largest value in this range of indices.
        if(start>close)						// When such subarray doesn't exist.
            return NULL;
        if(start==close)					// If subarray contains only 1 element.(That will be the max. elem.).
            return new TreeNode(v[start]);
        else								//Finding the index of max. value in the given range of indices(start, close).
            index=distance(v.begin()+start,max_element(v.begin()+start, v.begin()+close+1));  // Find the correct variables.
        //cout<<"index is: "<<index<<endl<<endl;
        TreeNode* temp= new TreeNode(v[index+start]);	//Creating a new node.
        //cout<<"Calling left part."<<endl;
        temp->left=maxBinary(v,start, start+index-1);	//Creating a left subtree.
        //cout<<"Calling left part."<<endl;
        temp->right=maxBinary(v,start+index+1, close);	//Creating a right subtree.
        //cout<<"Done calling both sides."<<endl;
        return temp;									//Returning the node created in this call.
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& v) {
        //TreeNode* temp;
        //temp=maxBinary(v,0,v.size()-1);
        //cout<<"After the function."<<endl;
        return maxBinary(v,0,v.size()-1);
    }
};
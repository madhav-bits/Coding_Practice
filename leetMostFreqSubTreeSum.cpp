/*
*
//****************************************************508. Most Frequent Subtree Sum.*******************************************

Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of 
all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum 
value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.


//These are the examples I had created, tweaked and worked on.
[5,2,-5,2,4,null,5,7]



// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// This is accumulating the sum of the subsets including the curr. node in the curr. node and saving the no. of such sums in a map, and 
// parallely tracking the maxm no. of occurances in varible-maxm. At the end of iteration, scanning the map to get the keys-whose value equals
// the maxm no. of occurances kep track of.

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
    map<int, int> m;													// Keeps track of no. of occurances of a sum.
    int maxm=INT_MIN;													// Keeps track of maxm no. of occurances.
    int findSum(TreeNode* temp){
        if(temp==NULL) return 0;
        temp->val=temp->val+findSum(temp->left)+findSum(temp->right);	// Updating the sum of subets including the curr. node.
        m[temp->val]++;
        maxm=max(maxm,m[temp->val]);									// Keeps track of maxm no. of occurances.
        return temp->val;												// Returns the sum of nodes till then.
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        //map<int, int> m;
        //int maxm=INT_MIN;
        int sum=findSum(root);
        map<int, int>::iterator it1;
        for(it1=m.begin();it1!=m.end();it1++){
            //cout<<"Key is: "<<it1->first<<" and value is: "<<it1->second<<endl;
            if(it1->second==maxm)										// Extracts the sum with maxm no. of occurances.
                v.push_back(it1->first);								// Pushing them into the final result vector.
        }
        
        return v;														// Returning the vector containing the sum with max no. of occurences.
    }
};
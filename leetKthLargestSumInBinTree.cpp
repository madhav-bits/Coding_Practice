/*
*
//************************************************2583. Kth Largest Sum in a Binary Tree.***********************************************

https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


5,8,9,2,1,3,7,4,6]
2
[1,2,null,3]
1
[5,8,9,2,1,null,3,7,4,6,null,2,1,3,null,4,null,null,1]
2
[1,1]
2




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Quick Sorting based. First, we iterate over the tree and collect the sum of nodes at each level of the tree in an array, then we quick sort the array to find the value in 
// kth psn from end if array is sorted.








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void iterateTree(TreeNode* node, int depth, vector<long long>&v) {									// Storing the sum of nodes at each level in an array.
        if(!node) return ;
        if(depth==v.size()) v.push_back(0);
        v[depth]+=node->val;
        iterateTree(node->left, depth+1, v);
        iterateTree(node->right, depth+1, v);
        return ;
    }
    
    void findKthLargest(vector<long long>&v, int low, int high, int psn) {								// Quick Sort to find the value in target index if array is sorted.
        if(low==high) return ;
        // cout<<"low: "<<low<<" and high: "<<high<<endl;
        int randomIndex=low+(rand()%(high-low+1));
        swap(v[randomIndex], v[high]);
        int i=low, j=low;
        while(i<=high) {
            if(v[i]<=v[high]) swap(v[j++], v[i]);
            i++;
        }
        j--;
        if(j==psn) return ;																				// If split index is the target Index, we stop the recursion and return the call.
        if(j<psn) return findKthLargest(v, j+1, high, psn);												// If target index is in right half of split, we process right half in recursive call.
        return findKthLargest(v, low, j-1, psn);														// If target index is in left half of split, we process left half in recursive call.
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int>v;
        iterateTree(root, 0, v);
        if(v.size()<k) return -1;
        findKthLargest(v, 0, v.size()-1, v.size()-k);													// Quick Sort call to find the value in target Index if array is sorted.
        return v[v.size()-k];																			// Accessing the value from the target Index.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).
// Space Complexity: O(n).	
// This algorithm is Quick Sorting and Level Order Traversal based. First, we iterate over the tree and collect the sum of nodes at each level of the tree in an array, then we quick sort the 
// array to find the value in kth psn from end if array is sorted.








class Solution {
public:
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int>v;
        
        priority_queue<long long int, vector<long long int>, greater<long long int>>pq;					// Defining a Min Heap Queue.	
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {																				// Level Order Traversal of Tree.
            int len=q.size();
            long long int currLevelTotal=0;																// Stores sum of nodes at each level.
            for(int i=0;i<len;i++) {
                TreeNode* node=q.front();
                q.pop();
                currLevelTotal+=node->val;
                
                // Adding next level nodes to the queue.
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(currLevelTotal);																	// Stores sum of nodes at each level in the Min Heap PQ.
            if(pq.size()>k) pq.pop();																	// If the pq size>k, we remove that total as we want kth largest total, 
																										// any smaller total is of no use, so we can ignore the total.
        }
        
        return (pq.size()<k)?-1:pq.top();																// If #entries/levels is less than k, we return -1 else return the kth largest level total.
    }
};






/*
*
//**********************************************************327. Count of Range Sum.***************************************************

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-2,0,-1]
-2
2


[]
-2
2



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Segment tree based, but doesn't work for quite a lot inteval scenarios. Need to work on it. Instead can shift to BITree.



class Solution {
public:
    struct TreeNode{
        int sum;
        int begin;
        int end;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x, int lower, int upper):sum(x),begin(lower), end(upper),left(NULL), right(NULL){}
        TreeNode(int lower, int upper):sum(0),begin(lower), end(upper),left(NULL), right(NULL){}
    };
    
    int constructTree(TreeNode* node, vector<int>nums,int lower, int upper){
        if(lower==upper){
            // new TreeNode(nums[lower],lower,lower);
            node->sum=nums[lower];
            return node->sum;
        }
        int mid=lower+(upper-lower)/2;
        node->left= new TreeNode(lower,mid);
        node->right= new TreeNode(mid+1,upper);
        node->sum+=constructTree(node->left,nums,lower,mid);
        node->sum+=constructTree(node->right,nums,mid+1,upper);
        // cout<<"The sum of int. start: "<<lower<<" and end: "<<upper<<" is: "<<node->sum<<endl;
        return node->sum;
    }
    
    void extractInt(TreeNode* node,int lower,int upper, int &count){
        // if(node) cout<<"Inside the fn. with start: "<<node->begin<<" and end: "<<node->end<<" with sum: "<<node->sum<<endl;
        if(node==NULL) return ;
        if(node->sum>=lower && node->sum<=upper){
            // cout<<"Inc. the count in the int with start: "<<node->begin<<" and end: "<<node->end<<endl;
            count++;    
        } 
        extractInt(node->left, lower,upper,count);
        extractInt(node->right, lower, upper, count);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return 0;
        TreeNode* root= new TreeNode(0,nums.size()-1);
        constructTree(root,nums,0,nums.size()-1);
        int count=0;
        extractInt(root,lower,upper, count);
        return count;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Merge Sort based. We first get the prefix sum to all indices in the in the array. We sort the contents of this array. While
// merging subarrays in this Merge Sort. We choose a interval from first half, and iterate to a interval with sum >=lower target, intervals
// with value>upper target. We extract the no. of intervals b/w these intervals, as they satisfiy the qsn's condition([lower, upper]) and indices
// i<=j, indices of prefix sum.






class Solution {
public:
    
    int findIntervals(vector<long>&v,int lower, int upper, int start, int end){
																			// End is the index which won't be used in this recur. call's calc.
        if(end-start<=1) return 0;											// Interval with 1/0 elements.
        int mid=(end+start)/2;												// Calc. mid value.
        int j=mid, k=mid, count=0;
        count+=findIntervals(v,lower, upper, start,mid)+ findIntervals(v,lower, upper, mid, end);	// Calling recur. for both halfs.
        for(int i=start;i<mid;i++){
            while(j<end && v[j]-v[i]<lower) j++;							// Interval with total sum with curr. int. in 1st half>= lower value.
            while(k<end && v[k]-v[i]<=upper) k++;							// Interval with total sum with curr. int. in 1st half> upper value.
            count+=k-j;														// Extracting the #satisfiying intervals.
        }
        inplace_merge(v.begin()+start, v.begin()+mid, v.begin()+end);		// Now, sort the given prefix sum array.
        return count;														// Return the #intervals satisfiying above cdn.
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return 0;
        vector<long>pre(nums.size()+1,0);								// Stores prefix sum.
        for(int i=0;i<nums.size();i++) pre[i+1]=pre[i]+nums[i];         // Index-0 indicates interval starts and end prior to ind-0(0 elem).
        return findIntervals(pre, lower, upper, 0, nums.size()+1);		// Return the total #intervals satisfiying above cdn.
    }
};
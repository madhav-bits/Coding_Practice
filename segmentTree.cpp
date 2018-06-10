/*
*
//**********************************************************SEGMENT TREE INITIAZLIATION.***************************************************





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
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is for differnet purpose, but this gives a proper implementation of initializing a Segment Tree.
// Initialization and utilizatin of a segment Tree can also be perfectly 2D Array Sum Mutable.








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
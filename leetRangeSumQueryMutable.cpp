/*
*
//******************************************************307. Range Sum Query - Mutable.***********************************************

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["NumArray","sumRange","update","sumRange"]
[[[1,3,5]],[0,2],[2,2],[1,2]]

["NumArray","sumRange","update","sumRange"]
[[[1,3,5]],[0,2],[1,2],[0,2]]



// Time Complexity: O(logn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(n).	
// This algorithm is Segment Tree based. We maintain a segment tree where, each node represents an interval of array, with sum of numbers in that
// interval. When updating we udpate only the overlapping intervals. While extracting the sum, we also extract values only from the fully 
// overlapped intervals. As, at each interval we encounter only 4 nodes at max, the updating and extracting Sum takes O(logn) time.






class NumArray {
    
private:
    struct segmentTree{														// Structure of segment Tree.
        int sum;															// Sum of child intervals.
        segmentTree *left, *right;											// Prts to left and right tree.
        int start, end;														// The interval that this node represents.
        
        segmentTree(int x, int y): sum(0), left(NULL), right(NULL), start(x), end(y){}
        
    };
    
    
public:
    
    
    segmentTree* buildTree(vector<int> nums, int start, int end){			// Building the Segment Tree with inital node values.
        if(start>end) return NULL;
        segmentTree* node= new segmentTree(start, end);
        if(start==end) node->sum=nums[start];
        else{
            int mid= start+(end-start)/2;
            node->left=buildTree(nums, start, mid);
            node->right=buildTree(nums, mid+1, end);
            node->sum=node->left->sum+ node->right->sum;
        }
        return node;
    }
    
    void updateVal(segmentTree* node, int val, int pos){						// Updating only the partially/fully overlapping intervals.
        if(node==NULL) return ;
        int mid=node->start+(node->end-node->start)/2;
        if(node->start == node->end){
            node->sum=val;
            return ;
        } 
        else if(pos<=mid) updateVal(node->left, val, pos);
        else updateVal(node->right, val, pos);
        int temp=node->sum;
        node->sum=0;
        node->sum+=node->left==NULL?0:node->left->sum;
        node->sum+=node->right==NULL?0:node->right->sum;
        // cout<<"Node's value got updated from: "<<temp<<"to: "<<node->sum<<endl;
        //node->sum=node->left->sum+node->right->sum;
        
    }
    
    int extractSum(segmentTree* node,int start, int end){							// ExtractSum from partially/fully overlapping intervals.
        //cout<<"Inside the node with start: "<<start<<" and end: "<<end<<endl;
        if(node==NULL) return 0;
        if(node->start==start && node->end==end) return node->sum;
        int mid= node->start+(node->end-node->start)/2;
        if(end<=mid) return extractSum(node->left, start, end);
        else if(mid<start) return extractSum(node->right, start, end);
        else{
            return extractSum(node->left, start, mid)+ extractSum(node->right, mid+1, end);
        }
        
    }
    
    
    segmentTree *root;
    NumArray(vector<int> nums) {
        root=buildTree(nums, 0, nums.size()-1);
        
    }
    
    void update(int i, int val) {
        updateVal(root,val, i);
    }
    
    int sumRange(int i, int j) {
        return extractSum(root,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
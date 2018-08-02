/*
*
//************************************************************881. Random Flip Matrix.*****************************************************

You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function 
flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a 
function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space 
complexity.

Note:

1 <= n_rows, n_cols <= 10000
0 <= row.id < n_rows and 0 <= col.id < n_cols
flip will not be called when the matrix has no 0 values left.
the total number of calls to flip and reset will not exceed 1000.
Example 1:

Input: 
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
Output: [null,[0,1],[1,2],[1,0],[1,1]]
Example 2:

Input: 
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
Output: [null,[0,0],[0,1],null,[0,0]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, n_rows and n_cols. flip and reset 
have no arguments. Arguments are always wrapped with a list, even if there aren't any.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]


["Solution", "flip", "flip", "reset", "flip"]
[[1, 2], [], [], [], []]




// Time Complexity: O(1).  
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(m*n).	
// This algorithm is vector based. We create a 1D array of length equals size of 2D array. Each time we predict a random value from 0 to total-1,
// we extract row, clmn from it by dividing it with clmn, and calc. remainder when divided with clmn. If we get a value other than total-1, then
// we swap curr. val and total-1 index's coordinates, then we dec. total by one, such that the next range of values to extract are consecutive.

// This is not Leet Accepted code, because I had created an array of given size, where the calls are very low. So, instead I should have worked 
// on not allowed indices by storing(tracking) them.






class Solution {
public:
    vector<pair<int,int>>changed;
    int row,clmn;
    int total,curr2;
    Solution(int n_rows, int n_cols) {
        total=n_rows*n_cols;												// Storing row*clmn value.
        //curr=total;
        row=n_rows;
        clmn=n_cols;
        changed=vector<pair<int,int>>(row*clmn);
        int ind=0;
        for(int i=0;i<row;i++){												// Storing the indices(row, clmn) in every index.
            for(int j=0;j<clmn;j++){
                changed[ind]={i,j};
                ind++;
            }
        }
    }
    
    vector<int> flip() {
        int ind=rand()%total;												// Genrating random value.
        pair<int,int>curr=changed[ind];										// Extracting row, clmn in that index.
        // cout<<"ind: "<<ind<<" first: "<<curr.first<<" and second: "<<curr.second<<endl;
        vector<int>res(2);	
        res[0]=curr.first;													// Creating result from that index.
        res[1]=curr.second;
        total--;															// Dec. the total value.
        if(ind==total) return res;											// If the generated random value is last in curr. range then skip swap.
        else{
            // cout<<"we had swapped ind: "<<ind<<" and total: "<<total<<endl;
            swap(changed[ind],changed[total]);								// Swap curr. index's val and last index's val.
            return res;														// Returning the result.	
        }
        
    }
    
    void reset() {
        total=row*clmn;														// INc. the range of values to given row*clmn.
        return ;															
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
 
 
 
 
 
 
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1*m*n).
// Space Complexity: O(m*n).	
// This algo. is Map based. Here, instead of  storing all allowed indices and checking whether the predicted is allowed or not. We, predict 
// an index, check whether it's in list or not?If not we directly return the value. If the predicted is not allowed, we predict the value once
// again, until we get a allowed index.
 
 
 
 
 
 
 
 class Solution {
public:
    int row,clmn;															// Stores max row, clmn.
    int total;																// Stores total allowed indices.
    unordered_map<int,int>m;												// Tracks all not allowed indices.
    Solution(int n_rows, int n_cols) {
        total=n_rows*n_cols;												// Init. total allowed indices.
        row=n_rows;
        clmn=n_cols;
    }
    
    vector<int> flip() {        
        int val=rand()%total;												// Generate random value.
        int x=val/clmn;	
        int y=val%clmn;
        // cout<<"val: "<<val<<endl;
        if(m.count(val)==1) return flip();									// If predicted val is not allowed, we predict once again.
        m[val]=1;        													// We mark curr. predicted as not allowed for following predic.
        return vector<int>({x,y});											// reutrn the curr. predicted val's row, clmn.
    }
    
    void reset() {
        m.clear();
        return ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
 
 
 
 
 
 
 
//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(m*n).	
// This algo. is Map based. Here, we predict a val, from which we extract curr. row and clmn. Here, instead of focusing and storing on allowed 
// vals. We use map to store the modified val that val represents, we do similar swapping as in Algo. 1. If our predicted val. is in map, then
// that val has some modified val assigned to it.So, we extract the modiified val, if not we return the default value it represents. If the 
// predicted val. <total-1, then we make the total-1, the modified val. that the curr. predicted val. represents.So, that we can have all allowed
// indices consecutively(We can use rand()%total).



 
 
 
 class Solution {
public:
    int row,clmn;
    int total;
    unordered_map<int,int>m;												// Stores modified val a val represent.
    Solution(int n_rows, int n_cols) {
        total=n_rows*n_cols;
        row=n_rows;
        clmn=n_cols;
    }
    
    vector<int> flip() {
        int val=rand()%total;
        // cout<<"val: "<<val<<endl;
        int res=val;
        res=(m.count(val)==1)?m[val]:val;									// Checking whether the pred. val holds any modified val or not?
        if(val<total-1) m[val]=m.count(total-1)?m[total-1]:(total-1);// If curr. val <total-1, then make val. in total-1 the modi. val of curr. val.
        total--;															// Dec. the total value.
        return vector<int>({res/clmn,res%clmn});							// Returning the row, clmn extracted from val that curr.val represents.
    }
    
    void reset() {
        m.clear();															// Emptying the modified representations list.
        total=row*clmn;														// Setting the total allowed indices to given row*clmn.
        return ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
/*
*
//*****************************************************************PRETTYPRINT.***********************************************************

https://www.interviewbit.com/problems/prettyprint/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1


4


5



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is BFS based. Here, we start filling from innermost indices, then check all adjacent indices for to fill the next value and push
// them into queue for further processing, we mark adjacent indices with next val. such that those indices won't be pushed twice into queue. Thus, 
// at the end, we have all indices filled.

// Here, each index is touch 8 times by it's 8 neighbors, so time complexity of (8*n^2)-> O(n^2).






vector<vector<int> > Solution::prettyPrint(int len) {
    vector<vector<int>>res((2*len)-1, vector<int>((2*len)-1, 0));			// Final result vector.
    int val=2;																// Value to mark the indices with.
    queue<pair<int,int>>q;													// Stores indices to be filled with vals.
    q.push({len-1, len-1});													// Starting with index with val-1.
    res[len-1][len-1]=1;
    while(!q.empty()){														// Until all indices are marked.
        int len=q.size();													// Size of indices with same val.
        for(int i=1;i<=len;i++){											// Iter. over indices with same val. in a loop.
            int row=q.front().first;
            int clmn=q.front().second;
            q.pop();
            if(row-1>=0 && res[row-1][clmn]==0){							// Checking(Valid index and unfilled) all adj. indices to fill next val.
                res[row-1][clmn]=val;
                q.push({row-1, clmn});
            }
            if(row-1>=0 && clmn-1>=0 && res[row-1][clmn-1]==0){
                res[row-1][clmn-1]=val;
                q.push({row-1, clmn-1});
            }
            if(row-1>=0 && clmn+1<res[0].size() && res[row-1][clmn+1]==0){
                res[row-1][clmn+1]=val;
                q.push({row-1, clmn+1});
            }
            
            if(clmn-1>=0 && res[row][clmn-1]==0){
                res[row][clmn-1]=val;
                q.push({row, clmn-1});
            }
            if(clmn+1<res[0].size() && res[row][clmn+1]==0){
                res[row][clmn+1]=val;
                q.push({row, clmn+1});
            }
            
            if(row+1<res.size() && res[row+1][clmn]==0){
                res[row+1][clmn]=val;
                q.push({row+1, clmn});
            }
            if(row+1<res.size() && clmn-1>=0 && res[row+1][clmn-1]==0){
                res[row+1][clmn-1]=val;
                q.push({row+1, clmn-1});
            }
            if(row+1<res.size() && clmn+1<res[0].size() && res[row+1][clmn+1]==0){
                res[row+1][clmn+1]=val;
                q.push({row+1, clmn+1});
            }
        }
        val++;																// Inc. the val to be filled in next loop.
    }
    
    return res;																// Returning the final result.
}

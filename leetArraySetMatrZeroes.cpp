/*
*
//********************************************************73. Set Matrix Zeroes.*************************************************

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?



//These are the examples I had created, tweaked and worked on.
[[1,1,1],[1,0,1],[1,1,1]]


// Time Complexity: O(n*2).
// Space Complexity: O(m+n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n*2).
// Space Complexity: O(m+n).
//This is the which meets the follow up requirements.
// This algorithm involves two arrays of lengths #rows and #clmns. Which stores whether are there any zeros in that indexed row and clmn resp.
// and will reiterate the array and equate the elements to zero, if there is a zero in that elem's row or clmn, which we can know from the two
// arrays.


class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        /*
        for(auto num:v){
            for(auto num:num)
                cout<<"The elem. is: "<<num<<" ";
            cout<<endl;
        }
        */
        
        if(v.size()==0) return;
        int clmn=v[0].size();
        int rows=v.size();
        vector<int> x(rows,1);					//Stores at index "i" whether there is a zero in that("ith") row.
        vector<int>y(clmn,1);					//Stores at index "i" whether there is a zero in that("ith") clmn.
        for(int i=0;i<rows;i++){
            for(int j=0;j<clmn;j++){
                if(v[i][j]==0){					// If 0 encountered making that indexed row and clmn array value to "0".
                    x[i]=0;
                    y[j]=0;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<clmn;j++){
                if(x[i]==0 ||y[j]==0 ){			//If you have zero in either of row or clmn.
                    v[i][j]=0;
                }
            }
        }
        return ;								//Returning void.
    }
};
/*
*
//******************************************************2428. Maximum Sum of an Hourglass.******************************************************

https://leetcode.com/problems/maximum-sum-of-an-hourglass/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
[[1,2,3],[4,5,6],[7,8,9]]
[[520626,685427,788912,800638,717251,683428],[23602,608915,697585,957500,154778,209236],[287585,588801,818234,73530,939116,252369]]




// Time Complexity: O(n*m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(1).	
// This algorithm is PrefixSum+iteration based. Here, we calc. prefixSum of indices for each row from left, while calculating hourglass indices total, we make use of this. We iter. over 
// entire matrix and try to update max. hourglass submatrix total and return the max total at the end of iter.







class Solution {
public:
    
    int getTotal(vector<vector<int>>&v, int row, int col) {					// Calc. the total of 3*3 submtarix indices values.
        int res=0;
        for(int i=-2;i<=0;i++) {
            for(int j=-2;j<=0;j++) {
                res+=v[row+i][col+j];
            }
        }
        return res;
    }
    
    int maxSum(vector<vector<int>>& v) {
		
		// This is another way to calculate the total of hourglass indices.
		// In this way we track the total of 3*3 sumatrix at present and remove the middle row values as needed and try to update the max. total of hourglass indices.
        // int res=0;
        // for(int i=2;i<v.size();i++) {
        //     int total=getTotal(v, i, 2);														// Calc. the total of 3*3 submatrix with bottom right being (i,2) index.
        //     if((total-v[i-1][0]-v[i-1][2])>res) res=(total-v[i-1][0]-v[i-1][2]);
        //     // cout<<"ending row: "<<i<<" ending col: "<<2<<" and total: "<<total-v[i-1][0]-v[i-1][2]<<endl;
        //     for(int j=3;j<v[0].size();j++) {
        //         total+=(v[i-2][j]+v[i-1][j]+v[i][j])-(v[i-2][j-3]+v[i-1][j-3]+v[i][j-3]);
        //         if((total-v[i-1][j]-v[i-1][j-2])> res) res=(total-v[i-1][j]-v[i-1][j-2]);	// We remove the middle indices and try to update the max. total of hourglass indices.
        //         // cout<<"endingg row: "<<i<<" ending col: "<<j<<" and total: "<<(total-v[i-1][j]-v[i-1][j-2])<<endl;
        //     }
        // }
        // return res;
        
        
        int res=0;
        for(int i=0;i<v.size();i++) {
            for(int j=1;j<v[0].size();j++) {
                v[i][j]+=v[i][j-1];											// We update matrix to prefixSum matrix, which stores prefixSum values for each row from left to right.
            }
        }
        
        for(int i=1;i<v.size()-1;i++) {
            for(int j=1;j<v[0].size()-1;j++) {
                int top=v[i-1][j+1];										// We get sum of indices on top row of hourglass.
                if(j-2>=0) top-=v[i-1][j-2];
                int mid=v[i][j]-v[i][j-1];									// We get sum of indices on middle row of hourglass.
                int bottom=v[i+1][j+1];										// We get sum of indices on bottom row of hourglass.
                if(j-2>=0) bottom-=v[i+1][j-2];
                if(top+mid+bottom>res) res=top+mid+bottom;					// We update the max sum of hourglass indices.
            }
        }
        return res;															// Return the max. hourglass indices total.
    }
};


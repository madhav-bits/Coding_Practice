/*
*
//*****************************************2033. Minimum Operations to Make a Uni-Value Grid.*****************************************

https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,4],[6,8]]
2
[[1,5],[2,3]]
1
[[1,2],[3,4]]
2
[[15,25],[35,45],[90,60],[20,30],[15,100],[45,55],[250,340],[20,30]]
5
[[15,25],[35,45],[90,60],[20,30],[15,100],[45,55],[250,340],[20,30]]
10
[[15,25],[35,45],[90,60],[20,30],[15,100],[45,55],[250,340],[20,30]]
2



// Time Complexity: O(n*m+k).												// n,m-row, cols of the matrix, k-range of the nums in the matrix.
// Space Complexity: O(k).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m+k).												// n,m-row, cols of the matrix, k-range of the nums in the matrix.
// Space Complexity: O(k).	
// This algorithm is Mathematics+Counting Sort based. The number at the minimum distance from all the nums in the matrix is the median of the nums in the 
// matrix. One other observation is that as we can only make changes in steps of 'x', all nums have to give same remainder when divided by 'x' else we can't 
// bring those nums to same value. In first iter. we iter. over matrix to confirm whether all gives same rem. when divided by 'x'. Since the range of nums 
// is low, we use Counting Sort and determine the Median of the nums. In second iter. We iter. over matrix once again, calc. #oper. needed for every val to 
// be = to median and add it to res and return res at the end of iter.



// Instead of Counting Sort, we can add all the values to an array and do parition Sort to get the middle index in psn and get the median value.
// nth_element(arr.begin(), arr.begin()+len/2, arr.end()); This makes 'len/2' index store the sorted val if entire array is sorted.








class Solution {
public:
    int minOperations(vector<vector<int>>& v, int x) {
        int rem=v[0][0]%x;
        vector<int>occur(100001,0);
																			// Bringing all nums close to median of the nums in the matrix.
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                if(v[i][j]%x!=rem) return -1;								// Checking whether all nums gives same remainder when div. by 'x'.
                occur[v[i][j]]++;											// Tracking #occur. of each num in the Counting Sort array.
            }
        }
        int midIndex=((v.size()*v[0].size())/2)+1, median=-1, res=0;
        for(int i=100000;i>0;i--) {											// Finding the Median of the nums in the matrix.
            if(occur[i]<midIndex) midIndex-=occur[i];			
            else {
                median=i;
                break;
            }
        }
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                if(v[i][j]>=median) res+=(v[i][j]-median)/x;				// Calc. #oper. needed for each num and add it to res.
                else res+=(median-v[i][j])/x;
            }
        }
        return res;															// Returning min. #oper. needed to make it Uni-Value matrix.
    }
};


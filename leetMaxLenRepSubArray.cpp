/*

//*********************************************718. Maximum Length of Repeated Subarray*************************************

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100


//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/
//*****************************************************Solution1:Dynamic Programming.*******************************************
// Time Complexity: O(m*n)													// m,n are length of the arrays.										
// Space Complexity: O(m*n)
// This algorithm is Dynamic Programming based. This approach is similar to Longest Common Subsequence approach, except that here since
// we want substrings, we only look diagonally into prev. row, getting info. about the len. of matching subarray till then.




class Solution {
public:
    int findLength(vector<int>& u, vector<int>& v) {
        int result=0;
        int arr[u.size()][v.size()]={};// If we use zero in the bracket, it's not initializing the array to 0.
  
        for(int i=0;i<u.size();i++){
            for(int j=0;j<v.size();j++){
                if(u[i]==v[j] && i>0 && j>0){
                    arr[i][j]=arr[i-1][j-1]+1;// Here current common subarray val. depends on the previous com. subarray.
                    result=max(result,arr[i][j]);
                }
                else if(u[i]==v[j]){// Here current common subarray val. won't depend on the previous com. subarray.
                    arr[i][j]=1;//So, just initialized to 1. This is sort of base case.
                    result=max(result,arr[i][j]);
                }
            }
        }
        //cout<<"The result is: "<<result<<endl;
        return result;
    }
};








//*****************************************************Solution2:Dynamic Programming.*******************************************
// Time Complexity: O(m*n)													// m,n are length of the arrays.										
// Space Complexity: O(n)
// This algorithm is similar to above solution. Since, in the dp array, curr. index depends only on prev. row, I had optimized the Space
// Complexity and created only two rows, which we use repetitively using (%2).





class Solution {
public:
    int findLength(vector<int>& u, vector<int>& v) {
        int result=0;
        int arr[u.size()][v.size()]={};// If we use zero in the bracket, it's not initializing the array to 0.
  
        for(int i=0;i<u.size();i++){
            for(int j=0;j<v.size();j++){
                if(u[i]==v[j] && i>0 && j>0){
                    arr[i][j]=arr[i-1][j-1]+1;// Here current common subarray val. depends on the previous com. subarray.
                    result=max(result,arr[i][j]);
                }
                else if(u[i]==v[j]){// Here current common subarray val. won't depend on the previous com. subarray.
                    arr[i][j]=1;//So, just initialized to 1. This is sort of base case.
                    result=max(result,arr[i][j]);
                }
            }
        }
        //cout<<"The result is: "<<result<<endl;
        return result;
    }
};


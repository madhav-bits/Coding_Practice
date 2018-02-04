/*
*
//***********************************************************216. Combination Sum III.*******************************************

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and 
each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.


//These are the examples I had created, tweaked and worked on.
3
7

5
24

// Time Complexity: O(n^2).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************DYNAMIC PROGRAMMING PARADIGM.*************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).
// This is DYNAMIC PROGRAMMING problem, I had tried to solve it iteratively, but there were some syntax errors and it was time consuming and 
// laborious as handling vectors is concerned. So, I had decided to go ahdead with this recursive DP algorithm.


class Solution {
public:
    
    void combSum(vector<vector<int>> &result, vector<int> dp, int k, int n){
        if(n==0 && dp.size()== k){ 					// Whenver the desired situation is met, we push the sln set into final result vector.
            result.push_back(dp);
            return ;
        }
        for(int i=dp.empty()?1:dp.back()+1;i<=9;i++){
            if(n-i<0) return ;
            dp.push_back(i);						// The curr. elem. might or might not get included in the final sum. So, first we include
            combSum(result, dp, k, n-i);			// in the dp, go ahead and solve, then remove it form dp and solve once again.
            dp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> dp;
        vector<vector<int>> result;
        combSum(result, dp,k,n );
        return result;
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
//*****************************************************DYNAMIC PROGRAMMING PARADIGM.*************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).
// This is DYNAMIC PROGRAMMING problem, I had tried to solve it iteratively, but there were some syntax errors and it was time consuming and 
// laborious as handling vectors is concerned. 






class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<vector<int>>> v;
        for(int i=0;i<n;i++)
            v.push_back({});
        for(int i=0;i<k;i++){
            for(int j=9;j>=1;j--){
                if(i-j>0 && v[i-j].size()>0){
                    for(int k=0;k<v[i-j].size();k++){
                        int len=v[i-j][k].size();
                        cout<<"The length is: "<<len<<endl;
                        ///*
                        if(i==len){
                            v[i-j]={};
                            vector<int> temp=v[i-j][k];
                            temp.push_back(i);
                            v[i-j].push_back(temp);
                        }
                        //*/
                    }
                }
                if(i-j==0 && v[i].size()==0)
                    v[i].push_back({i});
            }
        }
        for(int i=0;i<=v[n].size();i++)
            for(int j=0;j<v[n][i].size();j++)
            cout<<"The combi. is: "<<v[n][i][j]<<" ";
        return v[n];
    }
};


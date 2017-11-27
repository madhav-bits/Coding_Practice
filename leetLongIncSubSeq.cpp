/*

//******************************************************300. Longest Increasing Subsequence.**********************************************

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS 
combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.



//Time Complexity: O(n^2).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

// NEED TO IMPROVE THE CODE TO O(nlogn) COMPLEXITY.
//DONE USING DYNAMIC PROGRAMMING.

// To add a new number from the left, new number has to less than left most number. As we are comparing a single no.- 
// -for an entire sequence and building upon the results obtained till then, this comes under Dynamic Programming Algorithmic Paradigm.

class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int len=1;//As every index is a subset, min. len case.
        vector<int> u;//This vector says length of subseq starting at index "i".
        if(v.size()==0)
            return 0;
        for(const auto& num:v)// Initialzing each index to 1, as itself is a subseq.(Base Case).
            u.push_back(1);
        for(int i=v.size()-2;i>=0;i--){//Building up the cases starting from the last of the indices.
            for(int j=i+1;j<v.size();j++){
                if(v[j]>v[i] && u[j]>(u[i]-1)){//If the v[j]>v[i], then all the no. corres. to no. count in u[j] is also more than u[i].
                    //cout<<"v[i] is: "<<v[i]<<" and v[j] is: "<<v[j]<<endl;
                    u[i]=1+u[j];// As u[j] and no. of count of it also more than u[i]. Updating u[i] to 1 more than u[j], as u[i] is included
                    if(u[i]>len)
                        len=u[i];//Updating the len, as max. length sequence is what we need.
                }
                    
            }
        }
        return len;
    }
};
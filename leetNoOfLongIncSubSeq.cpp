/*

//***********************************************673. Number of Longest Increasing Subsequence.*****************************************

Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.





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
   class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int len=1, sum=0;//As every index is a subset, min. len case.
        if(v.size()==0)
            return 0;
        vector<int> u(v.size(),1),count(v.size(),1);//vector u saves the no. of inc. subseq. startig at u[i], count[i] says no. of incsubseq.
        for(int i=v.size()-2;i>=0;i--){//Building up the cases starting from the last of the indices.
            for(int j=i+1;j<v.size();j++){
                //cout<<"Outside if with i: "<<i<<"and u[i] is: "<<u[i]<<" and j: "<<j<<" u[j] is: "<<u[j]<<endl;
                if(v[j]>v[i]){//If the v[j]>v[i], then all the no. corres. to no. count in u[j] is also more than u[i].
                    if(u[j]>(u[i]-1)){
                        //cout<<"v[i] is: "<<v[i]<<" and v[j] is: "<<v[j]<<endl;
                        u[i]=1+u[j];// As u[j] and no. of count of it also more than u[i]. Updating u[i] to 1 more than u[j], as u[i] is included as part of inc. subseq.
                        count[i]=count[j];// The no. of occur. of u[j] becomes no. of occure. of u[i].
                    }
                else if(u[j]==u[i]-1)// If we find other inst. of same no. of subseq starting at some other u[j] we add no. of occu. to u[i], as both subseq. are possible starting at u[i].
                    count[i]+=count[j];
                }
            }
            len=max(len,u[i]);//Updating the len, as max. length sequence is what we need.
        }
        //cout<<" max length is: "<<len<<endl;
        for(int i=0;i<v.size();i++){
            if(u[i]==len)// There might be multiple subseq. starting at diff. indices having the longest inc. subseq., So adding all occure.
                sum+=count[i];
        }
        
        return sum;
    }
};
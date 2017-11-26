/*

//***********************************************************15. 3Sum.************************************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all 
unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]



//Time Complexity: O(n^2).
// Space Complexity: O(n).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> u;
        if(v.size()<3)
            return u;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-2;i++){
            if(i>0 && v[i]==v[i-1])//Prevents pushing duplicate first elem. into final result.
                continue;
            int a=v[i], req=-1*a, j=i+1, k=v.size()-1;
            while(j<k){
                //cout<<"curren values of array are: "<<v[j]<<" and: "<<v[k]<<endl;
                if(j>i+1 && v[j]==v[j-1] && k<v.size() && v[k]==v[k++]){
                    j++; k--;// Prevents pushing duplicates sec. and third elem. into 
                    continue;
                }
                    
                if(req==v[j]+v[k])// Whenever there is a match, moving ahead on two sides, as they both form a unique match. Moving on two-
                    u.push_back({a,v[j], v[k]});//- sides won't remove any unique matching cases.
                if(v[j]+v[k]==req){
                    j++; k--;
                }
                else if(v[j]+v[k]<=req)
                    j++;
                else if(v[j]+v[k]>=req)
                    k--;
            }
        }
        return u;
    }
};
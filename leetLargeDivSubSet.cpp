/*

//********************************************************368. Largest Divisible Subset**************************************************

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset 
satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]

Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.



//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
//DONE USING DYNAMIC PROGRAMMING.

//The logic is that all the numbers of the result sequence have to be multiples of the least number in it. To add a new number from the left,-
//- new number has to factor of left most number. As comparing a single no. for an entire sequence and building upon the results obtained till-
//- then, this comes under Dynamic Programming Algorithmic Paradigm.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(), v.end());
        int len=-1;
        vector<int> w;
        if(v.size()==0)
            return w;
        vector<vector<int>> u;// In it, sequences satisfying the above condition, at each index would be stored.
        for(const auto& num:v)
            u.push_back({num});// Initialzing each index itself(Base Case).
        for(int i=v.size()-2;i>=0;i--){//Building up the cases starting from the last of the indices.
            for(int j=i+1;j<v.size();j++){
                if(v[j]%v[i] ==0 && u[j].size()>(u[i].size()-1)){//If the initial begin of sequence is divisible by u[i], then with u[i]-
                    //cout<<"v[i] is: "<<v[i]<<" and v[j] is: "<<v[j]<<endl;//- new sequence can be formed.
                    u[i].clear();// Creating a New sequence at index "i".
                    u[i].push_back(v[i]);
                    for(const auto& num:u[j])//This forming for DP purpose, other cases might build on this result.
                        u[i].push_back(num);
                    //cout<<" v[i] is: "<<v[i]<<" and the size is: "<<u[i].size()<<" and len is: "<<len<<endl; 
                    int a=u[i].size();
                    if(a>len){// the right exp. gives data of type size_type. So, if the same is used in if condi. it fails.
                        w.assign(u[i].begin(), u[i].end());//This is for final answer.
                        len=u[i].size();//Updating the len, as max. length sequence is what we need.
                        //cout<<"new len is: "<<len<<endl;
                    }
                }
                    
            }
        }
        if(w.size()==0)
            return vector<int>(v.begin(), v.begin()+1);
        else
            return w;
    }
};
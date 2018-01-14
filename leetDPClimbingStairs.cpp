/*

//**********************************************************70. Climbing Stairs.*******************************************************

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step



//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************


class Solution {
public:
    int climbStairs(int n) {
        vector<int>v(n+1);
        v[1]=1;
        v[0]=1;
        for(int i=2;i<=n;i++){
            v[i]+=v[i-2];				//Adding the no. of ways to reach i-2th step, as we can take a 2 length jump to ith step.
            v[i]+=v[i-1];				//Adding the no. of ways to reach i-1th step, as we can take a 1 length jump to ith step.
        }								
        //for(auto num: v)
        //    cout<<"The vector elements are: "<<num<<endl;
        
        //cout<<"The result is: "<<v[n]<<endl;
        return v[n];
    }
};
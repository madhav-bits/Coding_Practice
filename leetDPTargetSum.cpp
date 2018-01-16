/*

//************************************************************494. Target Sum.*********************************************************

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you 
should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.



//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//The main concept is: pos-neg= target
//pos-neg+pos+neg=target+(pos+neg)or sum
//2*pos=target+sum, wo we need to find the subset whose sum is: (target+sum)/2
//Now this becomes same as 2 Partition Subset Sum Problem(Near Similar to Problem No. 416).



class Solution {
public:
    int findTargetSumWays(vector<int>& v, int target) {
        //cout<<"The target is: "<<target<<endl;
        int sum=0, len=v.size();
        for(auto num:v)
            sum+=num;
        //cout<<"The sum is: "<<sum<<endl;
        if(sum<target || (target+sum)%2!=0)             //We aim to get a subset whose sum is equal to pos. which is even.	
            return 0;									//If the sum of all elem. is less than target, then we can't achieve the target in anyway.
        auto pos=(target+sum)/2;
        //cout<<"The positive is: "<<pos<<endl;
        vector<int> u(pos+1,0);
        u[0]=1;
        for(int i=0;i<len;i++){							//Iterating through all the elements in the array.
            for(int j=pos;j>=0;j--){					//Calc. no. of possibilities to achieve a target(i) stored at index i.
                if(j-v[i]>=0 && u[j-v[i]]>=1)			//Making sure that "u[j-v[i]]" value is possible to attain.
                    u[j]+=u[j-v[i]];					//Passing/(To sum) on the no. of possibilities from the earlier subset.
            }
        }
        //cout<<"The answer is: "<<u[pos]<<endl;
        return u[pos];									//Returns no. of possibilities to acheive the target value of "pos".
    }
};
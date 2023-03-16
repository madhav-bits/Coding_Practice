/*
*
//******************************************************2554. Maximum Number of Integers to Choose From a Range I.***********************************************

https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,6,5]
5
6
[1,2,3,4,5,6,7]
8
1
[11]
7
50
[3,5,9,14,7,10,4]
20
100
[87,193,85,55,14,69,26,133,171,180,4,8,29,121,182,78,157,53,26,7,117,138,57,167,8,103,32,110,15,190,139,16,49,138,68,69,92,89,140,149,107,104,2,135,193,87,21,194,192,9,161,188,73,84,83,31,86,33,138,63,127,73,114,32,66,64,19,175,108,80,176,52,124,94,33,55,130,147,39,76,22,112,113,136,100,134,155,40,170,144,37,43,151,137,82,127,73]
1079
87
[1,4,5]
5
5



// Time Complexity: O(n+m).  																			// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+m).																			// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(1).	
// This algorithm is Greedy+Sorting based. The approach is to greedily pick the least possible nums so that we could get least possible total from max. number of nums. To track the banned nums
// and ensure they dont appear in picked nums, we sort them first. We iter. over the range of allowed nums, as banned nums are sorted, we also track the next greatest banned number from the curr. num
// and we wont pick curr. num if it's banned, we move the pointer to next greaest banned num. Thus we greedily pick nums so that the total would be minm. possible.








class Solution {
public:
    int maxCount(vector<int>& banned, int cap, int maxSum) {
        sort(banned.begin(), banned.end());
        int j=0, res=0;
        long long int currTotal=0;
        for(int i=1;i<=cap;i++) {
            if(j<banned.size() && banned[j]==i) {														// If the curr. num is banned, we skip it.
                while(j<banned.size() && banned[j]==i) j++;
                continue;
            }
            if(currTotal+i>maxSum) break;																// If currTotal+i>maxSum, any next number would also make the sum>maxSum, so we break the iter.
            currTotal+=i;																				// Inc. the total by curr. num.
            // cout<<"num: "<<i<<" and currTotal: "<<currTotal<<endl;
            res++;																						// Inc. picked nums count by one as curr. num is included.
        }
        return res;																						// Returning the total #picked nums.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).																				// n-#banned nums, m-range of allowed nums.
// Space Complexity: O(m).	
// The solution is Greedy based. The only diff. from above sln is that we track the banned nums in an array rather than sorting them.








class Solution {
public:
    int maxCount(vector<int>& banned, int cap, int maxSum) {
        vector<bool>ban(cap+1, false);
        for(int&num:banned) if(num<=cap) ban[num]=true;
        int j=0, res=0;
        long long int currTotal=0;
        for(int i=1;i<=cap;i++) {
            if(ban[i]) continue;
            if(currTotal+i>maxSum) break;
            currTotal+=i;
            // cout<<"num: "<<i<<" and currTotal: "<<currTotal<<endl;
            res++;
        }
        return res;
    }
};






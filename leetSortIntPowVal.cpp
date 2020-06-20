/*
*
//***********************************************1387. Sort Integers by The Power Value.***********************************************

https://leetcode.com/problems/sort-integers-by-the-power-value/description/


The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if 
two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is 
will fit in 32 bit signed integer.

 

Example 1:

Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
Example 2:

Input: lo = 1, hi = 1, k = 1
Output: 1
Example 3:

Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.
Example 4:

Input: lo = 10, hi = 20, k = 5
Output: 13
Example 5:

Input: lo = 1, hi = 1000, k = 777
Output: 570
 

Constraints:

1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


12
15
2

1
1
1

7
11
4

10
20
5

1
1000
777



// Time Complexity: O(nlogn+nx).											// x- Time needed to calc. power of a num.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+nx).											// x- Time needed to calc. power of a num.
// Space Complexity: O(n).	
// This algorithm is DFS+Map based. Here, we perform the power calculation process, if we encounter any num, which we had prev. calc.
// we use the power val directly. We push the power val and the index of the num as pair into new arr and sort it and return the k-1th
// index val.


// Here, strangely this algo. is lot of time because of accessing unordered_map.






class Solution {
public:
    
    void getPower(unordered_map<int, int>&dp, int num){						// Calc. power of a num.
        int steps=0, dig=num;
        while(num!=1){														// We perform steps until num is 1.
            if(dp.count(num)==1){											// If num. prev. encountered, add power.
                steps+=dp[num];
                num=1;
                break;
            }
            steps++;
            if(num%2==0) num/=2;
            else num=num*3+1;
        }
        dp[dig]=steps;														// Storing the power of the num.
        return ;
    }
    
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int>dp;											// Stores num. and their power.
        vector<pair<int,int>>res;											// Stores power and the num's index.
        dp[1]=0;
        dp[2]=1;
        for(int i=lo;i<=hi;i++){											// Iter. over arr and calc. power.
            // cout<<"curr. num: "<<i<<endl;
            getPower(dp, i);
            res.push_back({dp[i], i});
        }
        sort(res.begin(), res.end());										// Sorting based on power and index.
        return res[k-1].second;												// Return the kth integer in sorted array.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+nx).											// x- Time needed to calc. power of a num.
// Space Complexity: O(n).	
// This algorithm is Partial Sorting based. Here, we calc. power val and store power, index as pair in an arr. We then partially sort the
// arr for the (k-1)th index and return that index's val.







class Solution {
public:
    
    int getPower(int num){
        int steps=0;
        while(num!=1){
            steps++;
            if(num%2==0) num/=2;
            else num=num*3+1;
        }
        return steps;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>res;
        for(int i=lo;i<=hi;i++){
            // cout<<"curr. num: "<<i<<endl;
            res.push_back({getPower(i), i});
        }
        // sort(res.begin(), res.end());
        nth_element(res.begin(), res.begin()+k-1, res.end(),[](auto&lt, auto&rt){// Partially sorting for (k-1)th index.
            return (lt.first<rt.first) || (lt.first==rt.first && lt.second<rt.second);
        });
        return res[k-1].second;												// Return the kth integer in partially sorted array.
    }
};
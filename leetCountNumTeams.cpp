/*
*
//************************************************1395. Count Number of Teams.************************************************

https://leetcode.com/contest/weekly-contest-182/problems/count-number-of-teams/


There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[2,5,3,4,1]

[4,3,2,6,2,7,4,1,6]


// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we are forming triplets of inc/dec. order. We use less more arrays, less[i] stores #earlier
// indices with lesser value than value at index 'i'. In the iter., if we have 'j'>'i', and v[j]>v[i] then we can form triplets with
// all pairs of nums which are less then v[i], whose cnt is stored in less[i], so we add less[i] to final result. We do the same with 
// the more array.







class Solution {
public:
    int numTeams(vector<int>& v) {
        vector<int>less(v.size(),0), more(v.size(),0);						// Tracking #indices with lesser and greater val resp.
        int res=0;
        for(int j=1;j<v.size();j++){										// Iter. over array.
            for(int i=0;i<j;i++){											// Looking for smaller indices with lesser/greater value.
                if(v[i]<v[j]){												// If smaller value found.
                    res+=less[i];											// We add all indices with smaller val. than v[i].
                    less[j]++;												// Inc. the smaller vals count.
                } 
                
                if(v[i]>v[j]){												// If greater value found.
                    res+=more[i];
                    more[j]++;
                }
                
            }
        }
        // for(auto num: less) cout<<num<<" ";
        // cout<<endl;
        return res;															// Return the total cnt. of triplets.
    }
};


/*





*/
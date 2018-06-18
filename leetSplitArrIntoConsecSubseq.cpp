/*
*
//**************************************************659. Split Array into Consecutive Subsequences.*******************************************

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where 
each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,4,5]
[1,2,3,3,4,5]
[1,2,3,4,4,5,5,6,6]





// Time Complexity: O(n).  
// Space Complexity: O(n)

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array and stores the #occurances of nums. In the second iteration, we push a num into already formed seq. map
// if there exists a list(entry) with value=curr. value-1, then we can append the curr. num to already formed list. If not, we create a new 
// seq. list with curr. and next two values(if exists), if next values doesn't exists, return false.








class Solution {
public:
    bool isPossible(vector<int>& v) {
        bool res;
        map<int, int>m, fin;												// Stores count of nums, last num. of formed seq. of numbers.
        for(auto num:v)														// Taking count of all nums in vector.
            m[num]++;
        // for(auto it:m){
        //     cout<<"Key: "<<it.first<<" and value: "<<it.second<<endl;
        // }
        for(auto it=m.begin();it!=m.end();it++){							// Iterating through numbers.
            int count=it->second;
            int num=it->first;
            if(count<=0) continue;
            // cout<<"Curr. num: "<<num<<"with count: "<<count<<endl;
            for(int i=1;i<=count;i++){										// Iterating through the curr. num.
                if(fin[num-1]>=1){											// If a seq. list exists val.=curr-1, then append curr. num to it.
                    fin[num]++;
                    fin[num-1]--;
                    m[num]--;
                }
                else if(m[num+1]>0 && m[num+2]>0){							// Else, if next values exist, form a new list with them.
                    fin[num+2]++;
                    m[num]--; m[num+1]--; m[num+2]--;
                }
                else return false;									// If formed seq. list, new list can't be formed with curr. num, return false.
                
            }
            
        }
        return true;														// If no issue arises, then return true.
    }
};
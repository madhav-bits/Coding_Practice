/*
*
//******************************************************2780. Minimum Index of a Valid Split.******************************************************

https://leetcode.com/problems/minimum-index-of-a-valid-split/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,2,2]
[2,1,3,1,1,1,7,1,2,1]
[3,3,3,3,7,2,2]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Boyer-Moore Majority Voting Algorithm. We use this to determine to the dominant number, we iter. once again to find #occur of that number.
// We iterate once again and track #dominant number occur. we come across, we remove total-prefixCount to #dom. number in right part of split starting 'i+1'
// index. If the condition is satisfied in both parts, we return curr. index, if no such instance observed in the iter. we return -1.







class Solution {
public:
    int minimumIndex(vector<int>& arr) {
        // The original dominant would be the only candidate that can be dominant number in both portions of the array.
        int dom=arr[0], rep=1, totalCount=0, prefixCount=0;
        for(int i=1;i<arr.size();i++) {										// Finding the Dominant Number.
            if(arr[i]==dom) rep++;
            else if(--rep<0) {
                dom=arr[i];
                rep=1;
            }
        }
        for(int&num:arr) if(num==dom) totalCount++;							// Calc. #occur. of dominant number.
        // cout<<"dom: "<<dom<<" and occur: "<<totalCount<<endl;
        for(int i=0;i<arr.size()-1;i++) {
            if(arr[i]==dom) prefixCount++;									// Calc. #occur of dominant number until index 'i'.
            int remCount=totalCount-prefixCount;							// Calc. #occur of dominant number in rem. indices.
            if((2*prefixCount)>(i+1) && (2*remCount)>(arr.size()-1-i)) return i;// If dominant condition is satisfied in both parts, we return curr. index.
        }
        return -1;															// No split that satisfies the split conditions found.
    }
};


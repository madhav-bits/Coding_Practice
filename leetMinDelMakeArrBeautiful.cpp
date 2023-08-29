/*
*
//******************************************2216. Minimum Deletions to Make Array Beautiful.******************************************

https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,2,3,5]
[1,1,2,2,3,3]
[1,2,3,3,3,3,3,3,3,3,3,3,4,5,4,5,4,5,4,5,4,5,4,5,4]
[1,2,3,3,3,3,3,3,3,3,3,3,3,4,5,4,5,4,5,4,5,4,5,4,5,4]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. Here, at every step we ensure curr. index is even index, if it's adjacent index doesn't have same value, we form a pair
// and move to i+=2 index, else we delete the next index and try to match curr. index with the closest index with diff value. We could also have deleted the 
// curr. index too as it might have spoiled the later diff. valued pairs but greedily pairing the curr. index with them would only transfer the delete oper. to 
// next diff. valued pair if such pair exists, as a result there are no extra deletions overall and if there are diff. valued pairs in later indices we had 
// avoided deleting curr. index unneccessarily, thus we ensured to made least #deletions. If in the process we reached last index without adj. index, which
// means array becamed odd length, so we delete the last index then and return the total #deletions after the iter.







class Solution {
public:
    
    int minDeletion(vector<int>& v) {
        int i=0, res=0;
        while(i<v.size()) {													// Iter. over array while ensuring 'i' would be an even index in every iter.
            int j=i+1;														// Pairing curr. index with it's adj. index.
            while(j<v.size() && v[i]==v[j]) res++, j++;						// Deleting same valued adj. index.
            if(j==v.size()) return res+1;									// If arr became odd length(no pair for index-'i') we delete index-'i'.
            i=j+1;															// We paired i with j index and move to j+1 index in next iter.
        }
        return res;															// Returning min #deletions to make array beautiful.
    }
};


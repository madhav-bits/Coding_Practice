/*
*
//***************************************1849. Splitting a String Into Descending Consecutive Values.************************************

https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1234"
"050043"
"0090089"
"2463475749567457"
"4321"
"0000400000030200001"
"94650723337775781477"
"12345"




// Time Complexity: O(n^2).  												
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).												
// Space Complexity: O(n).	
// This algorithm is Brute Force+DFS based. Here, we try to form substrings with the given conditions where each index could be visited multiple times. We
// call the DFS function to form dec. numbers in the sequence from the main function as we need atleast two nums in the sequence. We apply some pruning con-
// - ditions to avoid forming nums unnecessarily which wouldn't meet the target number in that loop. As, pruning would improve run time but it won't improve
// the Time Complexity Asymptotically.



// Time Complexity Analysis: 
// If we are at 'i', how many DFS calls can we expect here, for every start length in [0, i], we reach dfs(i) only once as the dec. conditions meets only
// once in all the intermediatary DFS steps until dfs(i), so dfs(i) could be reached at max. 'i' times. In each call of dfs,we only give 1 child DFS call, 
// thus every index except zero index only gives 1 DFS call, where as zero index gives n DFs calls. Also, curr. DFS call won't touch indices which child DFS
// call touches, so all the DFS calls until last index touches/iter. 'n' indices. So, we have only n ways to reach the last index and we iter. 'n' indices
// in the process, thus making Time Complexity: O(n^2).
// Space Complexity Analysis:
// As we can have DFS call on each of the indices along the way, max. recursive stack size: O(n).



// This discussion forum link has a similar explanation for the Time Complexity Analysis:
// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/discuss/1186795/C%2B%2B-Backtracking-solution.-O(N-2)-and-time-complexity-analytics








class Solution {
public:
    
    bool formDecValues(string&s, int index, long long int target) {
        if(index==s.length()) return true;									// If we are able to form nums in seq. until last index.
        if(target<0) return false;											// We can't form target num<0.
        
        long long int curr=0;
        for(int i=index;i<s.length();i++) {									// Finding target num in the sequence.
            curr=curr*10ll+(s[i]-'0');
            if(curr>target) break;											// If curr. num>target, no use iter. further.
            if(curr==target && formDecValues(s, i+1, curr-1)) return true;	// If we reached end of string-> seq. of len>=2 found, so we return true.
        }
        return false;														// We didn't find dec. seq., so we return false.
    }
    
    bool splitString(string s) {
        long long int val=0;
        for(int i=0;i<s.length()-1;i++) {									// Forming 1 number here and calling DFS to form atleast 1 other num in seq.
            val=val*10+(s[i]-'0');
            if(i>10 && val>INT_MAX) break;									// For this num, we can't find second num=val-1, as total #digits>20.
            if(formDecValues(s, i+1, val-1)) return true;					// If seq. of length>1 found, we return true.
        }
        return false;														// If no dec. seq. found, we return false.
    }
};


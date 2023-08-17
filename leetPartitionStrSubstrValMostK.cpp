/*
*
//*************************************2522. Partition String Into Substrings With Values at Most K.***************************************

https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"165462"
60
"238182"
5
"9289386859849583"
27347
"939289582263548968262646524231341"
1000000000



// Time Complexity: O(n).  													// Solution 2 has best Time and Space Complexity.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Greedy+Recursion based. The approach is same as described in Solution 2, except that we used recursion to calc. #substrs rather than 
// iter. over string.







class Solution {
public:
    
    int formSubstr(string&s, int index, int cap) {
        if(index==s.length()) return 0;
        // cout<<"index: "<<index<<endl;
        long long int curr=0;
        int i=index;
        while(i<s.length() && curr*10+(s[i]-'0')<=cap) curr=curr*10+(s[i++]-'0');// Forming curr. substr with max. val possible.
        if(i==index) return -1;												// If we can't include curr. char in a substr, we can't form good partition.
        int res=formSubstr(s, i, cap);										// DFS to call form next substr.
        return (res==-1)?res:res+1;											// If not a good partition, return -1 else #substrs+1.
    }
    
    int minimumPartition(string s, int cap) {
        return formSubstr(s, 0, cap);										// Returning min. #substrs in a good partition.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We iter. over given string and we greedily try to form substr and extending it as much as possible while satisfying the 
// value limitation. If curr. substr val>cap, we stop iter., inc. res and move to next iter. and forming next substr. If our curr. substr has 0 val, that means
// curr. char can't be included in any subset and we can't form a good partition. We return #subsets formed once we reached end of string.
// As we are trying to get min. substrs greedily extending it to the max would ensure minm. #substrs are formed by the time we reach EOS. Any other combination
// with lesser length substr would lead to more total #substr or the same, so we can return the #substrs obtained after greedily forming substrs.




class Solution {
public:
    int minimumPartition(string s, int cap) {
        int res=0;
        for(int i=0;i<s.length();) {
            long long int curr=0;
            int index=i;
            while(index<s.length() && curr*10+(s[index]-'0')<=cap) curr=curr*10+(s[index++]-'0');// Forming curr. substr by extending it as much as possible.
            if(i==index) return -1;											// If we can't include curr. char in a substr, we can't form good partition.
            i=index;														// Moving to next iter.
            res++;															// Counting curr. substr.
        }
        return res;															// Returning min. #substrs in a good partition.
    }
};


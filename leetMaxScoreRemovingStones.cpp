/*
*
//**********************************************************1753. Maximum Score From Removing Stones.***************************************************

https://leetcode.com/problems/maximum-score-from-removing-stones/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


2
4
6
4
4
6
1
8
8



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Sorting and observation based. Here, since we want the maximum number of pairs/score. We remove the stones from minm, maxm pile
// until max pile equals second highest pile. If any stones from min pile are left, we remove rem/2 stones from both the greater piles, we maximize
// pairs to be added to res by keeping the height to possible maxm in two greater piles. Now, we form pairs with leftover greater piles and add it to res.







class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int>v({a,b,c});
        sort(v.begin(),v.end());
        c=v.back();
        b=v[1];a=v[0];
        int res=0;
        
        int diff=c-b;
        res=min(a,diff);													// Removing minm(small pile, excess stones in heighest pile).
        a-=res;
        c-=res;
        // cout<<"first step: "<<res<<" and a: "<<a<<endl;
        
        res+=2*(a/2);														// Form pairs with leftover smallest pile.
        b-=a/2;
        c-=a/2;
        // cout<<"second step: "<<res<<" and b: "<<b<<endl;
        
        res+=b;																// Leftover stones from Two greater piles form pairs.
        return res;															// Return the count of total #pairs.
    }
};


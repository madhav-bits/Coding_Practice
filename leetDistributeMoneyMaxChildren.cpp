/*
*
//******************************************************2591. Distribute Money to Maximum Children.******************************************************

https://leetcode.com/problems/distribute-money-to-maximum-children/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


20
3
16
2
40
6
44
6
33
8
1
2
8
2
5
6
17
2
23
2




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Going through diff. scenarios lead to below method.









class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        int res=0;
        money-=children;
        res+=min(money/7, children);
        money-=res*7;
        // cout<<"res: "<<res<<" and children: "<<children<<endl;
        if(money==3 && res+1==children) res--;
        else if(money!=0 && res==children) res--;
        return res;
    }
};


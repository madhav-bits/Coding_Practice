/*
*
//******************************************1663. Smallest String With A Given Numeric Value.********************************************

https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


3
27
5
73
6
156
8
9



// Time Complexity: O(n).													// n- length of the string.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).	
// This algorithm is iteration based. At every step, we calc. the maxm. value rem. chars would take, if that's more than 26* rem, we 
// push the extra value into curr. char. In this way we will be minm. value to curr. char.








class Solution {
public:
    string getSmallestString(int n, int k) {
        string res="";
        for(int i=0;i<n;i++){
            // cout<<"k: "<<k<<endl;
            int rem=n-i-1;
            if(k<=rem*26) res+='a';											// As rem*26>=k, 'a' in this place still forms valid str.
            else res+=(k-rem*26)-1+'a';										// Assigning extra value to curr. char.
            k-=(res.back()-'a'+1);
        }
        return res;															// Returning final string.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the string.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we assign 'a' to every char to the minm and substract them from total k. Now, we 
// iterate from last, at every step, we take the extra values to curr. char upto 'z', thus we are makinng sure that we form a str
// which is smallest.









class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k-=n;
        for(int i=n-1;i>=0;i--){	
            res[i]=min(k,25)+'a';											// Taking maxm. extra value to curr. char.
            k-=min(k,25);
        }
        return res;
    }
};

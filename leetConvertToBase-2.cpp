/*
*
//******************************************************1017. Convert to Base -2.******************************************************

https://leetcode.com/problems/convert-to-base-2/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


0
1
2
3
4
5
6
7
8
9
10
11
346355365
1000000000
496930696
975674464



// Time Complexity: O(logn).  
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(logn).	
// This algorithm is Math based. This is same as hwo we calculate base form for positive bases. Only exception is that we have to ensure that the remainder 
// be +ve while calculate rem. for each psn of base rep. If rem is neg. we will add +base to make it posi. and add +1 to num/=base so that total remains 
// constant. We repeat the process until num becomes zero. We reverse the remainders collected till now and return it. If res is empty we append '0' to it 
// and return res.




// This two links has better explanation for the approach:
// https://leetcode.com/problems/convert-to-base-2/discuss/265544/C%2B%2B-Geeks4Geeks
// https://www.geeksforgeeks.org/convert-number-negative-base-representation/
// Calculation part in https://en.wikipedia.org/wiki/Negative_base





class Solution {
public:
    string baseNeg2(int n) {
        // string res="";
        // while(n) {
        //     cout<<"num: "<<n<<" and binary rep: "<<bitset<32>(n)<<endl;
        //     res+=((n&1)!=0)?'1':'0';
        //     n=-(n>>1);
        // }
        // reverse(res.begin(), res.end());
        // if(res.empty()) res+='0';
        // return res;
        
        string res="";
        while(n!=0) {
            int rem=n%-2;													// Calc. rem for curr. psn.
            n/=-2;															// Calc. dividend which would be num rep for greater psns.
            if(rem<0) {														// If rem is <0, we make it +ve by adding base.
                rem+=2;
                n+=1;														// Adding +1 to dividend so that total remains constant.
            }
            res+=('0'+rem);													// Adding curr. rem to res.
        }
        reverse(res.begin(), res.end());									// Reverse the remainders collected.
        if(res.empty()) res+='0';											// If empty string, make it "0".
        return res;															// Returning the base rep. of given number.
    }
};


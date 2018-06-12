/*
*
//**********************************************************29. Divide Two Integers.***************************************************

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For 
the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1523213312
31231


-2147483648
-1	


1
-2147483648


7
3


27
3


25
3



33
3


43
3


81
3

1
3

0
3




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. So, as to find quotient of a division without using "/", "*" symbols, we can depend on the fact that
// any number can be written as a summation of power of 2's, here, we get to quotient in terms of power of 2. At each step, we extract one power
// of 2 of quotient. There are two loops, in the first loop, we get the maximum power of 2, that can be extracted from quotient, in the second
// loop, we extract all powers of 2, which fit into the quotient.



// This algo, is the same as Solution 2, but the Sln 2 is more simplified syntactically, it also compensates use of dictionary, it doesn't
// use any "/","*" values, instead Sln:2 uses bit manipulation techniques.




class Solution {
public:
    int divide(int64_t numer, int64_t denom) {
        if(denom==1) return numer;
        int sign=1;
        if(numer<0 ^ denom<0) sign=-1;
        int64_t res=1;
        unordered_map<int, int> m;
        numer=abs(numer);
        denom=abs(denom);
        // cout<<"Denom: "<<denom<<endl;
        if(numer<denom) return 0;
        m[denom]=1;
        int64_t temp=denom*2;
        while(temp<=numer){													// Getting to the maximum power of 2< quotient.
            res*=2;
            if(temp==denom) return res;
            m[temp]=res;
            temp*=2;
        }
        // cout<<"The res till now: "<<res<<endl;
        // cout<<"The temp is: "<<temp<<endl;
        int64_t up=temp/2;
        temp/=4;
        while(temp>0){
            // cout<<"up: "<<up<<" temp: "<<temp<<" and res: "<<res<<endl;
            if(up+temp<=numer){
                res+=m[temp];
                up+=temp;
            }
            temp/=2;
        }
        // cout<<"The result is; "<<res<<endl;
        // cout<<"The temp: "<<temp<<" and up: "<<up<<endl;
        if(res*sign>INT_MAX) return INT_MAX;
        return res*sign;
        
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. So, as to find quotient of a division without using "/", "*" symbols, we can depend on the fact that
// any number can be written as a summation of power of 2's, here, we get to quotient in terms of power of 2. At each step, we extract one power
// of 2 of quotient. There are two loops, in the first loop, we get the maximum power of 2, that can be extracted from quotient, in the second
// loop, we extract all powers of 2, which fit into the quotient.








class Solution {
public:
    int divide(int64_t numer, int64_t denom) {
        if(denom==1) return numer;
        int sign=1;
        if(numer<0 ^ denom<0) sign=-1;
        int64_t res=1;
        numer=abs(numer);
        denom=abs(denom);
        // cout<<"Denom: "<<denom<<endl;
        if(numer<denom) return 0;
        int64_t temp=denom<<1;
        int64_t num=2;
        while(temp<=numer){														// Getting to the maximum power of 2< quotient.
            if(temp==denom) return num;
            temp=temp<<1;														// Inc. the numer*quotient value.
            num=num<<1;															// INc. the power of 2 value.
        }
        // cout<<"The res till now: "<<res<<endl;
        // cout<<"The temp is: "<<temp<<endl;
        int64_t up=temp>>1;
        res=num>>1;																// Saving the maxm. power of 2<numer/denom into res.
        temp=temp>>2;
        num=num>>2;
        while(temp>0){															// To extract lesser powers of 2, which fit into number/denom.
            // cout<<"up: "<<up<<" temp: "<<temp<<" and res: "<<res<<endl;
            if(up+temp<=numer){													// Power of 2, which fits into number/denom.
                res+=num;
                up+=temp;
            }
            temp=temp>>1;														// Dec. the numer*quotient's value
            num=num>>1;															// Dec. the power of 2 value.
        }
        // cout<<"The result is; "<<res<<endl;
        // cout<<"The temp: "<<temp<<" and up: "<<up<<endl;
        if(res*sign>INT_MAX) return INT_MAX;									// If value overflown, return INT_MAX.
        return res*sign;														// Return the value.
        
    }
};
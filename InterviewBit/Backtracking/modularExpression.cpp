/*
*
//**************************************************************Modular Expression.*******************************************************


https://www.interviewbit.com/problems/modular-expression/



Implement pow(A, B) % C.

In other words, given A, B and C, 
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2
PROBLEM APPROACH :

Complete solution in the hint.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-21
1
20




71045970
41535484
64735492



3
5
14


-3
5
14


0
0
1


-1
0
1



// Time Complexity: O(logn).  
// Space Complexity: O(logn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(logn).	
// This algorithm is Binary Search based. Here, so as to calculate the power of a base, we divide the multiplications into two symmetrical halves.
// We calc. one of them, use if twice to get the result. Here, a special arises, when base is neg and power is odd, we get neg. results. For which 
// we have to return complement of obtained result wrto modulo value.









int findVal(int base, int exp, int modu){
    if(exp==1) return base%modu;											// If exp. is 1, return base%modu.
    int mid=exp/2;															// Calc. exp/2.
    long long int res1=findVal(base, exp/2,modu);							// Calc. result for the expo begin exp/2.
    long long int res=1;
    if(exp%2==1){															// If exp is odd.
        res=(base*res1)%modu;												// Mutliplying base with square of result of recursive call.
        res=(res*res1)%modu;
    }
    else{
        res=(res1*res1)%modu;												// Getting square of result.
    }
    return (int)res;														// Returning the result.
}

int Solution::Mod(int base, int expo, int modu) {
    if(base==0) return 0;													// Base cases.
    if(expo==0) return 1%modu;
    int res= findVal(abs(base),expo,modu);									// Call fn. to get result.
    // cout<<"res: "<<res<<endl;
    if(base<0 && expo%2==1){												// If result is supposed to neg. value, then complement wrto modulo val.
        res=modu-res;														// Compl. wrto modulo value.
    }
    return res;																// Returing the obtained result.
}


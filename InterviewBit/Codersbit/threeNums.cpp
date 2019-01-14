/*
*
//***************************************************************Three Numbers.*************************************************************

https://www.interviewbit.com/problems/three-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1613
18
2042
9977



650
20
2000
9800



15
3
20
160



2
5
10
40





// Time Complexity: O(n).  													// Depends of gcd calculation time.
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// Depends of gcd calculation time.
// Space Complexity: O(1).	
// This algorithm is observation based. Since, we need #unique multiples of all three nums. So, we calculate mumtiples of each num. then subtract
// common multiples of each pair from the total, in the process of deleting common multiples we might over delete them, so we add mutiples 
// common to all the three nums.







long long int gcd(long long a, long long b){ 								// Calc. gcd of two numbers.
    if(a==0) return b;
    return gcd(b%a,a);
} 

long long int lcm(long long int a, long long int b){  						// Calc. lcm to two nums.
    return (a*b)/gcd(a, b);  
 }  


int Solution::solve(int A, int B, int C, int D) {
    D--;																	// Since, we need ints less than D.
    long long int com;														// lcm of all three nums.
    long long int gcd1=lcm(A,B);											// lcm of first two nums.
    long long int gcd2=lcm(B,C);
    long long int gcd3=lcm(A,C);
    int res=0;																// Final result.
    res+=(D/A)+(D/B)+(D/C);													// Calc. multiples of all 3 nums.
    // cout<<"gcd1: "<<gcd1<<" gcd2: "<<gcd2<<" and gcd3: "<<gcd3<<endl;
    res-=(D/gcd1)+(D/gcd2)+(D/gcd3);										// Removing overlapping multiples.
    com=lcm(gcd1, (long long )C);											// Calc. lcm of 3 nums.
    // cout<<"Com1: "<<com<<endl;
    res+=D/com;																// Adding deleted multiples.
    return res;																// Returning #unique multiples less than D.
}
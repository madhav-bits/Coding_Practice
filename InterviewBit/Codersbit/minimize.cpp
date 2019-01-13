/*
*
//******************************************************************MinimiZe.***********************************************************

https://www.interviewbit.com/problems/minimize/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


900
700


950
700



23
30



15
15




// Time Complexity: O(n).  													
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is mathematical observation based. Here, if we split given numbers in terms of their gcd, both their divisors will be having 
// gcd of 1. Two numbers(m,n) with gcd of 1 can be added(a*m+n*y) to get a positive number of 1. So, here we will get gcd as the least posi. 
// number possible through addition.










int findPos(long long int num1, long long int num2){						// Here, we iterate till we reach the init state again.
    long long int diff=INT_MAX;
    int dx=num1, dy=num2;
    do{
        if(num1>num2){
            diff=min(diff, num1-num2);
            num2+=dy;
        }else if(num1<num2){
            diff=min(diff, num2-num1);
            num1+=dx;    
        } 
        else break;
    }while(num1!=dx || num2!=dy);											// Till init. state isn't reached.
    return diff;															// Returning min. diff. till now.
} 
 
 


int gcd(int a, int b){														// Returning gcd of two numbers.
    if(a==0) return b;
    return gcd(b%a, a);
}

int Solution::solve(int num1, int num2) {
    if(num1==num2) return num1;												// Base case.
    return gcd(num1,num2);													// Returning gcd of two numbers.
    return findPos((long long int )num1,(long long int )num2);				// Another way to solve the problem, but getting LTE for this method.
}

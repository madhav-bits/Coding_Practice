/*
*
//******************************************************************FizzBuzz.*************************************************************

https://www.interviewbit.com/problems/fizzbuzz/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5


3

15


6

1


23


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We start from 1, iter till num. If the given num is multiple of 3 and 5, multiple of 15, we push "FizzBuzz"
// into final result vector. If divided by 5, we push "Buzz", else if divisible by "3", we push "Fizz", else we directly push the num. into final 
// result vector.








vector<string> Solution::fizzBuzz(int num) {
    vector<string>res;														// Decl. final result vector.
    for(int i=1;i<=num;i++){												// Iter. over all numbers.
        if(i%15==0) res.push_back("FizzBuzz");								// If divisible by 3 and 5.
        else if(i%5==0) res.push_back("Buzz");								// If divisible by 5.
        else if(i%3==0) res.push_back("Fizz");								// If divisible by 3.
        else res.push_back(to_string(i));									// If not, push num into final result vector.
    }
    return res;																// Returning the final result vector.
}

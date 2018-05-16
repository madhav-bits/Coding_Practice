/*
*
//**************************************************************412. Fizz Buzz.*******************************************************

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which 
are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
20
33



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iteratest through the range of numbers asked in question. Check whether each number is divisible by 15(both 3 and 5), if yes
// push "FizzBuzz" into the final result, else check whether is divisible by 3, if true push"Fizz", else check for divisibility by "5", if true
// push"Buzz", else push the integer directly into the result vector.



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>res;
        for(int i=1;i<=n;i++){
            if(i%15==0) res.push_back("FizzBuzz");								// If div by both 3,5, then push "FizzBuzz".
            else if(i%3==0) res.push_back("Fizz");								// If div. by 3, then push "Fizz".
            else if(i%5==0) res.push_back("Buzz");								// If div. by 5, then push "Buzz".
            else res.push_back(to_string(i));									// Else push integer directly into final result vector.
        }
        return res;																// Return the final result vector.
    }
};
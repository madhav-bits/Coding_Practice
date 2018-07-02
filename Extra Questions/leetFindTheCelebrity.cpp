/*
*
//**********************************************************277. Find the Celebrity.***************************************************

Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is
 that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions 
like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by 
asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function 
should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If 
there is no celebrity, return -1.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


No test cases to work on.(Not allowed)


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, in the first iteration, we extract a person who might be celeb. In the second iteration, we go through
// the entire array once again, check for person who doesn't curr. prob. celeb./ persons whom this prob. celeb. doesn't know, if we didn't
// find any instances of such, then return prob. celebrity.


// I HAD MISSED SMALL POINT OF ELIMINATING CURR. PERSON IF HE KNOWS OTHER PERSON( I WAS FOCUSING ON OTHER PERSON BEING TAKEN AS CELEB., DESPITE THE
// FACT THAT, HE MIGHT BE KNOWN TO ANYONE ELSE. I DIDN'T RECOGNISE CURR. PERSON IS CERTAINLY NOT CELEB NOW.)





// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n<1) return n;													// If len<1, return that value(As it's the only value in array).
        int per=0;															// Tracks prob. celeb. person.
        for(int i=1;i<n;i++){
            if(knows(per,i))												// If the prob. celeb. doesn't know curr. person, then curr. person
                per=i;														// becomes new prob. celeb.
        }
        
        for(int i=0;i<n;i++){												// We iterate through whole array once again.
            if(i!=per &&(knows(per,i) || !knows(i,per))) return -1;			// If prob. celeb. knows any person/any person doesn't know him, return
        }																	// -1, else return the prob. celeb.
        
        return per;															// Returning the prob. celeb.
    }
};
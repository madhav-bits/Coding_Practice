/*
*
//**********************************************************686. Repeated String Match.***************************************************

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcd"
"cdabcdabe"

"abcd"
"cdabcdab"

"abcd"
"cdab"


"abcd"
"c"



// Time Complexity: O((m/n)+2).  
// Space Complexity: O((m/n)*n+2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((m/n)+2).
// Space Complexity: O((m/n)*n+2).	
// This algorithm is observation based. Partial overlap occurs at two instances, when temp's length>target length, even then we might need one
// more append to temp to get the proper overlap("abcd","cdba"). We check for both instances, if we didn't find any match, then return -1.






class Solution {
public:
    int repeatedStringMatch(string src, string target) {
        int rep=0;
        string temp="";
        while(temp.length()<target.length()){								// Iterate till temp length<target length.
            // cout<<"CUrr. temp: "<<temp<<endl;
            temp+=src;														// Inc. the temp  length.
            rep++;
        }
        if(temp.find(target)!=string::npos) return rep;						// If substr found return count.
        temp+=src;															// INc. temp length one more time.
        if(temp.find(target)!=string::npos) return rep+1;					// If substr found return count.
          
        return -1;
        
    }
};
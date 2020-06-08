/*
*
//******************************************************1405. Longest Happy String.***************************************************

https://leetcode.com/problems/longest-happy-string/description/


A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
1
7


2
2
1



7
1
0

12
10
1



// Time Complexity: O(nlogn).												// n- Sum of occur. of all chars, while repushing into PQ.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- Sum of occur. of all chars, while repushing into PQ.
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, we use PQ to get char with maxm. occurances, we take one of it's occur. and dec. the 
// occur. and push it back into PQ, whenever we get maxm. occurance. We check the prev. two chars, if they are same as curr. one, we 
// take next greatest occur. char, we add it and push the two chars into PQ. In this way we avoid three consec. same chars. If we
// don't have any second greatest char after two same chars, then we stop and return the string formed till then. We also don't push 
// the chars into PQ, if teir occurance is zero.








class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";														// Final result str.
        priority_queue<pair<int,char>>pq;									// PQ with chars and occur.
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        while(!pq.empty()){													// Until there are no chars.
            pair<int,char>curr=pq.top();									// Char with most occur.
            pq.pop();
            if(res.length()>=2 && res.back()==curr.second && res[res.length()-2]==curr.second){// If prev. two chars are same.
                if(pq.empty()) return res;									// If no second greatest #occur. char stop and return str.
                pair<int,char>temp=pq.top();								// Get second greatest #occur. char.
                pq.pop();
                res+=temp.second;											// Add it to str.
                temp.first--;												// Dec. cnt by one.
                if(temp.first!=0) pq.push(temp);							// If #occur. aren't zero push it to PQ.
                pq.push(curr);
            }else{
                res+=curr.second;											// Adding char. with greatest #occur. to final str.
                curr.first--;
                if(curr.first!=0) pq.push(curr);
            }
        }
        return res;															// Returning the final string.
    }
};


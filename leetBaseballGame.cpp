/*
*
//************************************************************682. Baseball Game.*****************************************************

You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["0","5","2","C","D","+"]

[]

["1","+","D","D","+","C","C","2"]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Stack keeps track of valid round' scores. At each round, we calc. curr. round's score based on prev. rounds/curr. 
// round given score. At the end, we sum the scores of all valid rounds and return. If we encounter, "+", add two prev. round scores and push 
// the curr. score into stack. If we encounter-"D", we double prev. round score and push curr. score into stack. If we encounter-"C", we dec. the
// previous round's score/remove the score from the stack. If we encounter a score, we push it into stack directly.








class Solution {
public:
    int calPoints(vector<string>& v) {
        stack<int>s;														// Tracks each round's valid score.
        int sum=0;
        for(int i=0;i<v.size();i++){										// Iterates through all rounds.
            // cout<<"Curr. index: "<<i<<endl;
            if(v[i]=="+"){													// If "+" encount.
                int num1=s.top();
                s.pop();
                int num2=s.top();
                s.push(num1);
                s.push(num1+num2);											// Add two prev. rounds and push into stack.
            }
            else if(v[i]=="D"){												// Double prev. round score and push into stack.
                s.push(2*s.top());
            }
            else if(v[i]=="C"){												// Remove prev. round's score.
                s.pop();
            }
            else{															// Push curr. score into stack directly.
                int num=stoi(v[i]);
                s.push(num);
            }
            // cout<<"The sum: "<<sum<<endl;
        }
        
        while(!s.empty()){													// Get sum of all scores.
            sum+=s.top();
            s.pop();
        }
        return sum;															// Return the total score.
    }
};
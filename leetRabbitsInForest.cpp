/*
*
//**********************************************************781. Rabbits in Forest.***************************************************

In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color 
as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
Note:

answers will have length at most 1000.
Each answers[i] will be an integer in the range [0, 999].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]
[1,5,1,2,3,2,6,6,7]
[1,0,0,3,1,0,0]
[1,2,3,4,5,6,7,7,7,7,7,7,7,8,8,8,9,10,1,7]
[1,2,3,4,5,6,7,7,7,7,7,7,7,8,8,8,9,10,1,7,2,2,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,1,1,1,1,1,0,0,0,0,0]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array and takes the count of all same answers, we divide the count with the answer value to seggregaet the answers
// into diff. set of answer #animals. We sum up all these sets and return the result.

// Here, the main concept is that animals whose answer is the same they belong to same set of animals, as we have to get min. #animals 
// if #same valued answers > answer value, then calc. #sets of same number of same colored animals.



class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int result=0;
        map<int, int>m;																	// Maps answer with #animals giving same answer .
        for(int i=0;i<ans.size();i++){													// Counting the animals with same answer.
            m[ans[i]]+=1;
        }
        for(auto it=m.begin();it!=m.end();it++){
                int quo= (it->second-1)/(1+it->first);									// Finding the #sets with same number of same colored anim.
                //cout<<"Quo is: "<<quo<<endl;
                result+=(1+quo)*(1+it->first);											// Counting animals from all those sets.
        }
        //cout<<"The result is: "<<result<<endl;
        return result;																	// Returning the total number of animals.
    }
};
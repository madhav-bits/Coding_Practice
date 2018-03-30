/*
*
//******************************************************386. Lexicographical Numbers.***********************************************

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1001
501
10
10000
999




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).				//Space to store all the digits.
// This algorithm is DFS Oriented. At each level, we travel recursively Depth First through the numbers, once we iterate through that level, we
// move back to previous level and iterate it.



class Solution {
public:
    void findLexical(vector<int>&res, int num, int target){
        //cout<<"Inside the findLexical with curr. value: "<<num<<endl;
        int temp=num*10;
        for(int i=0;i<10;i++){												// Iterating through the curr. level of numbers.
            if((temp+i)!=0 && temp+i<=target){								// Checking whether numbers are <Max. possible value.
                res.push_back(temp+i);
                if((temp+i)*10<=target) findLexical(res, temp+i, target);	// Calling the fn to iterate next level of numbers.
            }
        }    
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> v;														// Stores the numbers in Lexical Sequence.
        findLexical(v,0,n);													// Calling the fn to find Lexical sequence of numbers.
        return v;
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is DFS  oriented. Uses a trick to avoid recursive calling. This also inc. the value until the value becomes>target. On becoming
// values>target, it's decreased until it becomes not divisible by 10. Thus, the values are Lexicographical.






class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int curr=1;
        for(int i=0;i<n;i++){
            res[i]=curr;								// Updating the values in final. res vector.
            if(curr*10<=n)								// Inc. the value- moving to next level(Going Deep).
                curr*=10;
            else{
                
                if(curr>=n)								// Bringing the values to become<=max possible.
                    curr/=10;
                curr++;									// Moving in the curr. level(lateral drn).
                    
                while(curr%10==0) curr/=10;				// Traversing back to higher levels, to continue iteration.
            }
        }
        return res;										// Returning the vector with Lexicographical numbers.
    }
};
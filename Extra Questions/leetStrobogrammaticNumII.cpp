/*
*
//******************************************************247. Strobogrammatic Number II.***********************************************

https://leetcode.com/problems/strobogrammatic-number-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


2
1
3



// Time Complexity: O(5^(n/2)).  											// n- length of the string.
// Space Complexity: O(5^(n/2)).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(5^(n/2)).  											// n- length of the string.
// Space Complexity: O(n*5^(n/2)).	
// This algorithm is DFS based. Here, we first store the chars/nums which looks same upon rotating 180 degrees. We iter. over temp 
// string of length 'n', until 'n/2' length. At each step, we assign all these chars and their partner chars which looks like curr. 
// char upon rotating 180, we can use only 0,1,8 in mid index as they look like themselves upon rotating. As, we are only making 
// changes which are accepted into final result array, time complexity is optimized.








class Solution {
public:
    
    void formNumbers(string&temp, vector<pair<char, char>>&rev, int index, vector<string>&res){
        if(temp.length()%2==1 && index==temp.length()/2){					// Odd length string termination case.
            for(int i=0;i<3;i++){											// Mid index takes only 0,1,8 nums.
                temp[index]=rev[i].first;
                res.push_back(temp);
            }
            return ;
        }
        if(index==temp.length()/2){											// Even length string termination case.
            res.push_back(temp);
            return ;
        }
        
        for(int i=0;i<rev.size();i++){										// Assigning index and it's symmetric index partner nums.
            if(index==0 && i==0) continue;
            temp[index]=rev[i].first;
            temp[temp.length()-1-index]=rev[i].second;
            formNumbers(temp, rev, index+1, res);							// Call recur. fn. to change next indices.
        }
        return ;
    }
    
    vector<string> findStrobogrammatic(int n) {
        string temp(n,'*');
        vector<string>res;
        vector<pair<char,char>>rev;											// Storing num1 and num2 which looks like num1 on rotation.
        rev.push_back({'0','0'});
        rev.push_back({'1','1'});
        rev.push_back({'8','8'});
        rev.push_back({'6','9'});
        rev.push_back({'9','6'});
        formNumbers(temp, rev, 0, res);										// Recur. fn. to form strobogrammatic-numbers.
        return res;															// Returning all strobogrammatic-numbers of length n.
    }
};
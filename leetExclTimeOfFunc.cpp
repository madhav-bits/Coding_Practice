/*
*
//******************************************************636. Exclusive Time of Functions.***********************************************

Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very 
beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be 
considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example 1:
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.
Note:
Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

2
["0:start:0","1:start:2","0:start:4","0:end:55","1:end:66", "0:end:67"]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is based on stack, as a fn. gets active when the recursively called fn. is closed. So, stack would be the most approp. data struc.



class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& v) {
        vector<int> u(n,0);
        stack<int> st;
        int len, prev_val=-1;
        for(int i=0;i<v.size();i++){
            string s=v[i];
            len=s.length();
            int fn,val, j=0, start=0;
            while(s[j]!=':') j++;
            fn=stoi(s.substr(0,j));							// Extracitng the curr. fn. value.
            j++;
            if(s[j]=='s') start=1;							// Noting, whether the curr. fn state is start or end.
            while(s[j]!=':') j++;
            //cout<<"Before val."<<" and len is: "<<len<<" j is: "<<j<<" and length is: "<<len-j-1<<endl;
            val=stoi(s.substr(j+1, len-j-1));				// Curr. the current fn's time value.
            //cout<<"fn is: "<<fn<<" and val is: "<<val<<endl;
            if(st.empty()){									// If the stack is empty, then just push the curr. fn.
                st.push(fn);
                prev_val=val;
            }
            else if(start==1){								// If the curr. fn is start, then pushing it into the stack.
                u[st.top()]+=val-prev_val;					// Also, calc. the prev. fn's time.
                st.push(fn);
                prev_val=val;
            }
                
            else{											// Calc. the prev. fn's time.(Here the prev and curr fn is same).
                u[st.top()]+=val-prev_val+1;				// +1, as start from the beginning of start time and till end of close time.
                st.pop();									// Remove the fn from stack, as it it closed.
                prev_val=val+1;								// As, the fn. is executed till the end of curr time value.
            }												// Prev_val will be used to calc. the curr. fn's exec. time consid. next fn's time.
            
        }
        
        return u;											// Returning the vector containing the each fn's execution time.
    }
};
/*
*
//******************************************************957. Prison Cells After N Days.***********************************************

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,0,1,1,0,1,0]
900000000



[0,1,0,1,1,0,0,1]
127



// Time Complexity: O(k).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k).
// Space Complexity: O(k).	
// This algorithm is HashMap based. Here, we calculate states for every day based on prev. day until we find a loop or reach target day. If loop
// found, we calc. the #days to iterate in the final loop iteration and find the day with those rem. days value in the map and form the vector 
// with obtained state and return the vector.







class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& v, int N) {
        string s="";														// Used to track state.
        vector<int>res;														// Final result vector.
        for(auto num: v) s+=to_string(num);									// Init. state var.
        unordered_map<string,int>m;											// Used to find loop in the states.
        int step=0;
        // cout<<"first s: "<<s<<endl;
        while(step<N && m.count(s)==0){										// Until target day is reached/ loop is found.
            m[s]=step;														// Storing curr. state in the map.
            step++;
            char left=s[0];
            for(int i=1;i<s.length();i++){									// Iter. and calc. next state form curr. state.
                char res='0';
                if(left==s[i+1]) res='1';
                left=s[i];
                s[i]=res;
            }
            s[0]='0';														// Setting first and last chars.										
            s[s.length()-1]='0';
            // cout<<"new s: "<<s<<" and step: "<<step<<endl;
        }
        // cout<<"obtained s: "<<s<<"with step: "<<step<<endl;
        if(step!=N){														// If loop is found.
            int len=m[s];	
            int loop=step-len;
            // cout<<"loop len: "<<loop<<endl;
            int req=(N-len)%loop+len;										// Calc. last loop rem. days.
            // cout<<"req; "<<req<<endl;
            for(auto it=m.begin();it!=m.end();it++){						// Iter. and finding the day with rem. days value.
                if(it->second==req){
                    s=it->first;
                    break;
                }
            }
        }
        for(auto ch:s) res.push_back(ch-'0');								// Forming result vector.
        // cout<<"last s: "<<s<<"step: "<<step<<endl;
        return res;
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k).
// Space Complexity: O(k).	
// This algorithm is HashMap based. Here, we calculate states for every day based on prev. day until we find a loop or reach target day. If loop
// found, we calc. the #days to iterate in the final loop iteration and iterate those days to get final result state, we convert it to vector
// form and return it.



// This is slightly modified version of above solution. Here, instead of iterating over map and finding the last day, we update the step value
// such that we iterate step num. of days to get result state.




class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& v, int N) {
        string s="";
        vector<int>res;
        for(auto num: v) s+=to_string(num);
        unordered_map<string,int>m;
        int step=0;
        // cout<<"first s: "<<s<<endl;
        while(step<N ){
            m[s]=step++;
            char left=s[0];
            for(int i=1;i<s.length();i++){
                char res='0';
                if(left==s[i+1]) res='1';
                left=s[i];
                s[i]=res;
            }
            s[0]='0';
            s[s.length()-1]='0';
            if(m.count(s)==1){
                int loop=step-m[s];
                int rem=(N-step);
                rem=rem%(loop);
                step=N-rem;													// Updating steps to rem. num. of days to iterate in the last loop.
            }
            // cout<<"new s: "<<s<<" and step: "<<step<<endl;
        }
        // cout<<"obtained s: "<<s<<"with step: "<<step<<endl;
        for(auto ch:s) res.push_back(ch-'0');
        // cout<<"last s: "<<s<<"step: "<<step<<endl;
        return res;
    }
};










//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k).
// Space Complexity: O(k).	
// This algorithm is Observation based. It can observed from brute force that here, we have a loop of  length 14, starting from first day. So, we
// calculate the num. of days to iterate in the last cycle of iteration in the loop. Then, iterate that many times and return the result.









class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& v, int N) {
        string s="";														// Used to track temp. states of prisoners.
        int req=(N-1)%14+1;													// Num. of days to iterate in the last iteration of loop.
        // cout<<"req: "<<req<<endl;
        for(int i=0;i<v.size();i++) s+='0'+v[i];							// Init. string var.
        while(req>0){														// Iter. through all the days.
            string t(v.size(),'0');											// Init. temp. str.
            for(int i=1;i<v.size()-1;i++){									// Calc. state for next day using curr. day's states.
                if(s[i-1]==s[i+1]) t[i]='1';								// If adj. indices have same val. then set curr. index to '1' else '0'.
            }
            s=t;															// Assigning next state value to curr. state.
            req--;															// Dec. the days to iterate value.
        }
        vector<int>res;														// Variable to store final state value.
        for(auto ch: s) res.push_back(ch-'0');								// Setting the final state value.
        return res;															// Returning the final state value.
    }
};
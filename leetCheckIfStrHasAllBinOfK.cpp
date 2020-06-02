/*
*
//**************************************1461. Check If a String Contains All Binary Codes of Size K.*************************************

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an 
increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"00110110"
2

"00110"
2


"0110"
1


"0000000001011100"
1



// Time Complexity: O(n).													// n-length of the string.
// Space Complexity: O(2^m).												// m- Binary Code's size.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the string.
// Space Complexity: O(2^m).												// m- Binary Code's size.
// This algorithm is array and Sliding Window based. Here, we take a window of length 'k', we keep track of the value of the window
// substring, we set that index to true in the array, we also keep track of #indices set. So, if we have (1<<k) set indices, then 
// all Binary Codes of size k are covered.






class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // unordered_set<string>st;											// Tracks all encountered window's values.
        // deque<char>q;													// Used to maintain the window.
        // for(int i=0;i<s.length();i++){
        //     q.push_back(s[i]);
        //     if(i>=k-1){
        //         st.insert({q.begin(), q.end()});							// Converting deque into str and pushing into set.
        //         q.pop_front();
        //     } 
        // }
        // return (st.size()==(1<<k));
        
        int temp=0, cnt=0;													// Tracks the val. of window substring.
        bool visited[1<<k];													// Declaring array.
        memset(visited,false,sizeof(visited));								// Init. to 0.
        for(int i=0;i<s.length();i++){										// Iter. over array.
            temp<<=1;														// Left push the value gathered till now.
            temp+=(s[i]-'0');												// Adding curr. index to window.
            // cout<<"i: "<<i<<" and temp state: "<<temp<<endl;
            if(i>=k-1){														// If window size 'k' is formed.
                if(i>=k) temp=(temp&((1<<k)-1));							// If window size>k, remove first MSB.
                // cout<<"ready state: "<<temp<<endl;
                if(visited[temp]==false) cnt++;								// If window val index not set, inc. the cnt.
                visited[temp]=true;											// Setting the array values based on window's values.
            }
            // cout<<"i: "<<i<<" and temp: "<<temp<<endl;
        }
        return (cnt==(1<<k));												// If all indices are set, return true else false.
    }
};


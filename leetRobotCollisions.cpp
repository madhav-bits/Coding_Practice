/*
*
//******************************************************2751. Robot Collisions.******************************************************

https://leetcode.com/problems/robot-collisions/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,3,2,1]
[2,17,9,15,10]
"RRRRR"
[3,5,2,6]
[10,10,15,12]
"RLRL"
[1,2,5,6]
[10,10,11,11]
"RLRL"
[1,40]
[10,11]
"RL"



// Time Complexity: O(nlogn+n)=O(nlogn).
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+n)=O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Sorting+Stack based. As we are processing collisions, it would be easier to process if they are sorted, so we form psn, index pairs and sort them based
// on positions. Now, we can process this similar to Asteroid Collision problem, where we store robots which still moves after collisions in a stack, if the top of stack moves
// 'R' and the curr. robot moves 'L', then these would collide, so we decide on the result based on conditions specified in the question, in this way we process all the 
// robots on top of stack which we move towards 'R' when the curr. robot moves to 'L' else we also add the curr. robot to the top of stack as this would be the rightmost
// robot by position which is alive. We set the robot health to '0' which are popped out of stack or the ones which haven't been added to stack even, i.e., all dead robots 
// health is assigned to be zero. Thus, we will be left with live robots at the end of iter., as we needs the results to be in the order of orig. indices, we iter. over health
// array and add non-zero healths in the iter. to the res and return it at the end of iter.







class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>res;
        vector<pair<int,int>>v;
        for(int i=0;i<positions.size();i++) {
            v.push_back({positions[i], i});
        }
        sort(v.begin(), v.end());
        stack<int>st;
        for(int i=0;i<v.size();i++) {
            // cout<<"curr psn: "<<v[i].first<<endl;
            if(st.empty() || 
               directions[st.top()] == 'L'|| 
               directions[v[i].second] == 'R') st.push(v[i].second);		// For the cases of no collision, we add curr. robot to top of stack.
            else {
                while(!st.empty() && directions[st.top()]=='R' && healths[st.top()]<healths[v[i].second]) {// Right moving robots with lesser healths than curr. robot.
                    healths[st.top()]=0;
                    st.pop();
                    healths[v[i].second]--;
                };
                if(!st.empty() && directions[st.top()]=='R') {				// Processing the last collision b/w curr. and top of stack robot if it moves 'R'.
                    if(healths[st.top()]==healths[v[i].second]) {
                        healths[st.top()]=0;
                        st.pop();
                    } else healths[st.top()]--;
                    healths[v[i].second]=0;
                } else if(st.empty() || directions[st.top()]=='L') st.push(v[i].second);// In case of no collision we add curr. robot to top of stack.
            }
        }
       
        for(int health: healths) {
            if(health>0) res.push_back(health);								// Adding all non-zero health robots into res.
        }
        return res;															// Returning the remaining active robots in the orig. order of indices.
    }
};


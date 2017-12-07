/*

//******************************************************739. Daily Temperatures.**************************************************

GGiven a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would 
have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
   
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int> u;
        if(v.size()==0 )
            return u;
        stack<int> s,t;
        s.push(v[0]);// This stack stores the elements for whom elem. are not found till then.
        t.push(0);// Stores the indices of all temp values stored in stack "S".
        for(int i=0;i<v.size();i++)// Initializing all the vector's values to zero.
            u.push_back(0);
        for(int i=1;i<v.size();i++){
            while(!s.empty() && v[i]>s.top()){// Checking the current temp. with all vals in stack for curr. temp. might be a warmer day.
                //cout<<" Colder is: "<<s.top()<<"Warmer days is: "<<v[i]<<" push val is: "<<i-t.top()<<endl;
                u[t.top()]=i-t.top();// IF warmer day found, storing the distance b/w warmer and the actual day.
                s.pop(); t.pop();// Removing the value and corresponding index.
            }
            s.push(v[i]);
            t.push(i);
        }
		// All the points for whom warmer days can't be found, have to be zero. As the vector initialized to zero. So, no need.
        return u;
    }
};
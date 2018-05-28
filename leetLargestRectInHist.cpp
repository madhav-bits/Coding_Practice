/*
*
//******************************************************84. Largest Rectangle in Histogram.***********************************************

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in 
the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,5,4,3,2,2,2,3,2,1,0,4,3,5,6,7,8,9,2,1]
[2,1,2,3,1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is stack based. The main logic is that if a index "i" is popped from the stack, then all elem. from "i" to "curr-1" indices 
// are greater >= value at index "i". We push indices whose values are greater than curr. top of stock. If lesser value is found, we pop elem. from
// stack until we get a index containing value<= curr. index's value. While popping we calculate value of area these blocks from popped index to
// "curr. index-1" and try to update the max. area.







class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        if(v.size()==0) return 0;
        int res=0;
        v.push_back(0);										// Pushing a dup. elem. to consider ara contributed by each local min. height.
        stack<int>st;										// To store indices.
        for(int i=0;i<v.size();i++){
            //cout<<"begining on iteration wtih index: "<<i<<endl;
            if(st.empty() || v[i]>=v[st.top()]) st.push(i);	// If the curr. index's value > curr. stack top then push into stack.
            else{
                //cout<<"Inside the else: "<<endl;
                while(!st.empty() && v[st.top()]>v[i]){		// Else, pop until st gets empty/ A st.top() value<=curr. index's value occurs.
                    int index=st.top();						// Popping the curr. stack top index.
                    st.pop();
                    if(st.empty()){							// Calc. the area contributed by last popped index's height.
                        //cout<<"To be pushed area when empty stack is: : "<<v[index]*i<<endl;
                        res=max(res,v[index]*i);			// Updating the maxArea.
                    } 
                    else{									// Calc. the area contributed by last popped index's height.
                        //cout<<"To be pushed area: "<<v[index]*(i-st.top()-1)<<" at index: "<<i<<endl;
                        res=max(res,v[index]*(i-st.top()-1));// Updating the maxArea.
                    }
                        
                }
                st.push(i);									// Pushing the curr. index into stack.
            }
            
        }
        //cout<<"The result is: "<<res<<endl;
        return res;											// Returning the maxArea.
    }
};
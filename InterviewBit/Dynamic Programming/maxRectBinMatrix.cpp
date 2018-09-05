/*
*
//******************************************************Max Rectangle in Binary Matrix.***********************************************

https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.






// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Stack, Dynamic Programming based. We iter. over entire array, use DP array to track conse. ones from first row to curr. 
// row in the curr. coloumn. Then, for each row, we iter. over DP array. If the curr. index's val. is >= than stack top, then we push it 
// into stack.Else, we remove indices/heights which are smaller than curr. index's height as curr. height will negate all of them. We pop stack
// top, then this prev. stack top is min. in the [curr. stack top, curr. index under scanning], we calc. rect. area over this entire length
// area=prev. stack top*(j-st.top()-1), try to update the result area. If the stack is empty, then prev. stack top is min. over entire 
// length [0,j]. We try to update the result max. area.


// Almost solved the question, except for this stack pop intuition.





int Solution::maximalRectangle(vector<vector<int> > &v) {
    vector<int>dp(v[0].size()+1,0);											// Tracks Depth of Conse. ones in ith coloumn from top to curr. row.
    int res=0;																// Set the maxArea=0.
    
    for(int i=0;i<v.size();i++){											// Iter. over entire array.
        for(int j=0;j<v[0].size();j++){	
            if(v[i][j]==0) dp[j]=0;											// If curr. index has zero, then make conse. ones as 0.
            else dp[j]+=v[i][j];											// If curr. index has one, then inc. the ones count.
        }
        stack<int>st;														// Tracks index of min. conse. ones.
        for(int k=0;k<dp.size();k++){										// Iter. over DP array.
            if(st.empty() || dp[st.top()]<=dp[k]){							// If curr. val is greater than top than then push it into stack.
                st.push(k);
            }
            else{															
                while(!st.empty() && dp[st.top()]>=dp[k]){					// Pop until a smaller val. is obtained.
                    int curr=st.top();										// Store the stack top value/index.
                    st.pop();
                    if(!st.empty())											// If stack is !empty, then this curr. height is min. over top to k.
                    res=max(res,dp[curr]*(k-st.top()-1));
                    else res=max(res,dp[curr]*k);							// If stack is empty, then this curr. height is min. over all length.
                }
                st.push(k);													// Push curr. index to stack.
            }
        }
    }
    return res;																// Return the maxm. area calculated.
}

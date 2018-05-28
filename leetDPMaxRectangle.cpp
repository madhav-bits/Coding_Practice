/*
*
//**********************************************************85. Maximal Rectangle.***************************************************

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

[["0","0","0","1","0","0"],["0","0","1","1","0","1"],["0","0","1","1","1","0"],["0","1","1","1","1","0"],["0","0","1","1","1","1"]]



// Time Complexity: O(n).  
// Space Complexity: O(clmn).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(clmn).	
// This algorithm takes it's implementation from Max Rectangle Area in Histogram, we pass each row to max Rect in Hist fn. We iterate through the 
// rows, we add 1 to those clmns which have "1"s in the same clmn as the prev. one.  If we have "0", we replace that index with "0", thus we create
// a row which represents 1's in sequence of the rows iterated till now, and pass it to Max Rect in Hist fn.



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& v) {
        if(v.size()==0 || v[0].size()==0) return 0;
        vector<int>u(v[0].size()+1,0);											// As, the repr. row also have to indicate end of rows with "0".
        int maxm=0;
        stack<int> st;															// To store indices.
        for(int i=0;i<v.size();i++){
            //cout<<"Beginning of iteration: "<<i<<endl;
            for(int k=0;k<v[0].size();k++){										// Representative of 1's in seq. of rows iterated till now.
                //cout<<"Assigning index: "<<k<<endl;
                if(v[i][k]-'0'==0) u[k]=0;
                else u[k]+=1;
            }
            //u=v[i];
            //cout<<"Starting max. rect: "<<endl;
            while(!st.empty()) st.pop();										// Passing the rep. row to the Max. Rect in Hist Fn.
            for(int j=0;j<u.size();j++){
                //cout<<"Inside the max. rect with iteration: "<<j<<" with value: "<<u[j]<<" and stack size: "<<st.size()<<endl;
                if(st.empty() || u[j]>u[st.top()]){
                    //cout<<"Pushing index: "<<j<<endl;
                    st.push(j);  
                } 
                else{
                    while(!st.empty() && u[st.top()]>u[j]){
                        int temp=st.top();
                        st.pop();
                        if(st.empty()){
                            //cout<<"Empty stack with height: "<<u[temp]<<" and dist: "<<j<<endl;
                            maxm=max(maxm, u[temp]*j);  
                        } 
                        else{
                            maxm=max(maxm,u[temp]*(j-st.top()-1));
                        }
                    }
                    st.push(j);
                }
            }
            //st.clear();
        }
        //cout<<"The result is: "<<maxm<<endl;
        return maxm;
    }
};
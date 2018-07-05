/*
*
//**********************************************************360. Sort Transformed Array.***************************************************

Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each 
element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[-4,-2,2,4]
0
3
5



[-4,-2,2,4]
0
-1
5



[-99,-94,-90,-88,-84,-83,-79,-68,-58,-52,-52,-50,-47,-45,-35,-29,-5,-1,9,12,13,25,27,33,36,38,40,46,47,49,57,57,61,63,73,75,79,97,98]
-2
44
-56




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Merging Sorting Arrays based. If we have a==0, then the seq. of values depend on sign of "b", if b<0, then reverse result
// array else return the same which we attained by iterating start till end. If a>0, we get concave upwards graph, with ends being greater values
// we do a merging of sorting arrays from the end(Greater to smaller values), else we do a merging of sorting arrays from the start(smaller to 
//larger values).








class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& v, int a, int b, int c) {
        vector<int>res(v.size());											// Final result vector.
        if(a==0){
            for(int i=0;i<v.size();i++)										// Get the eqn. value.
                res[i]=(a*v[i]*v[i])+(b*v[i])+c;
            if(b<0) reverse(res.begin(), res.end());						// We need to reverse the array.
            return res;														// Return the result vector.
        }
        else{
            int i=0,j=v.size()-1;	
            int index,change;
            if(a<0){														// Setting index, index increment values based on sign of "a".
                change=1; index=0;											// Merging from lower to greater values.
            }
            else{															// Merging from greater to lower values.
                change=-1; index=v.size()-1;
            }
            while(i<=j){													
                int val1=(a*v[i]*v[i])+(b*v[i])+c;							// Calc. values.
                int val2=(a*v[j]*v[j])+(b*v[j])+c;
                if((a<0 && val1<=val2) || (a>0 && val1>=val2)){				// Choosing one of two values to be placed in result vector.
                    // cout<<"Currently pushing val: "<<val1<<endl;
                    res[index]=val1;										// Assigning values to final result vector.
                    index+=change;											// Incrementing the iterator values.
                    i++;
                }
                else{
                    // cout<<"Currently pushing val: "<<val2<<endl;
                    res[index]=val2;
                    index+=change;
                    j--;
                }
            }
        }
        return res;															// Returning the final result vector.
    }
};
/*
*
//**********************************************************904. Fruit Into Baskets.***************************************************

In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, 
then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 

Note:

1 <= tree.length <= 40000
0 <= tree[i] < tree.length




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,1,2,2]


[1,0,1,4,1,4,1,2,3]


[1,1,0,1,2,2,4,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we have to extract max. size of window with only 2 Uniq. elem. in it. We use ind1, ind2 vars to 
// keep track of last index, where we encount. any of two uniq. vars in this window. So, that next time, when we push new elem. into window,
// we delete the var whose last occurance is of least index of the value. As, we are trying to delete one var from the window to accomodate new 
// one. If the window size is curr. var is not in window, we push it into window. We try to update the vars in window's latest encount. index.
// For every iter. we try to obtain the max.length of window.







class Solution {
public:
    int totalFruit(vector<int>& v) {// This Code looks lot simpler, if we use HashMap directly to track values in Window.
        int count=0;														// Tracks the size of the window.
        if(v.size()<=1) return v.size();									// Base case.
        int start=0,end=0;													// Start, end of window.
        int ind1=0,ind2=-1;													// Latest occurance of curr. window's Uniq. vars.
        int maxm=1;															// Max. window size encoun. till now.
        count=1;															// Init. the window to first index(0).
        for(int i=1;i<v.size();i++){										// Iter. through entire array.
            // cout<<"index i: "<<i<<endl;
            end=i;															// Marking curr. index as window's last index.
            if(count==2 && v[ind1]!=v[i] && v[ind2]!=v[i]){					// If curr. val is diff. to two vals in Window.
                if(ind1<ind2){												// If ind1 is last encountered of the two vars.
                    start=ind1+1;											// Make that index(ind1)+1 has start of window.
                    ind1=i;													// Replace that vals index with curr. index.
                }
                else{
                    start=ind2+1;											// Make that index(ind2)+1 has start of window.
                    ind2=i;													// Replace that vals index with curr. index.
                }
            }
            else if(count==1 && v[i]!=v[ind1]){								// If window has only 1 value and curr. val is diff to it.
                ind2=i;														// Update the index var.
                count=2;													// Updating the num. of uniq. vals.
            }
            if(v[ind1]==v[i]) ind1=i;										// Updating the window's elem. latest index.
            if(ind2>=0 && v[ind2]==v[i]) ind2=i;							// Updating the window's elem. latest index.
            // cout<<"start: "<<start<<" and end; "<<end<<endl;
            maxm=max(maxm,end-start+1);										// Extracting the maxm. window size encountered.
        }
        return maxm;														// Return the max fruits(maxm. window size encountered).
    }
};
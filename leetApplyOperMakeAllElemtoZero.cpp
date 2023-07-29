/*
*
//******************************************2772. Apply Operations to Make All Array Elements Equal to Zero.**************************************

https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,1,1,0]
3
[1,1,2,1]
3
[2,4,5,5,5,0,0,2,2,3,1,1]
3
[2,4,5,3,1,0,0,2,2,3,1,1]
3
[4,5,6,4,3,4,6,6,4,6,4,3,2]
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window+Greedy based. Here, we greedily pick the value/#dec. oper. that we want to perform starrting 'i' based on the value in arr[i] as we iter. 
// from start to last, as curr. window would be the last window that covers 'i', we dec. whatever amount is left after. dec it by earlier started overlapping windows agg. dec.
// amount. At every index, we also take into consideration prev. windows closing index, if at curr. index-1 any window closes, we remove it's contribution from the amt we dec. 
// curr. index by. As we can't form windows in the last 'k-1' indices, there shouldn't be any value left after dec. amount bec. of prev. started windows.


// In the commented part, I had used an array to keep track of window's dec. amount and it's closing index, so that we can change the dec. amount accordingly.






class Solution {
public:
    bool checkArray(vector<int>& v, int k) {
        //*****************************************Check solution at 147 ms.********************************************
        int dec=0;
        // vector<int>window(v.size(),0);
        for(int i=0;i<v.size();i++) {
            if(i>=k) dec-=v[i-k];											// Prev. window closed at 'i-1', so we dec. window starting at 'i-k''s contribution.
            v[i]-=dec;														// Dec. curr. value by agg. dec. amount of all overlapping windows.
            if(v[i]<0 || (i>v.size()-k && v[i]!=0)) return false;			// If curr. value<0, or it's non-zero in the last 'k-1' indices, we return false.
            dec+=v[i];														// We create a new window where we dec. v[i] for the next 'k' indices.
            // if(i+k<v.size()) window[i+k]+=v[i];
        }
        // for(int i=v.size()-k+1;i<v.size();i++) {
        //     dec-=window[i];
        //     if(dec!=v[i]) return false;
        // }
        return true;														// If no issues found and all values became zero, we return true.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm is Sliding Window+Greedy based. We use the same approach as above, but rather than clearly specifying conditions, dec would take care of all the above
// mentioned conditions by itself when we check (dec==0), it checks whether we started any new windows in the last 'k-1' indices, which we were checking in a written condition.







class Solution {
public:
    bool checkArray(vector<int>& v, int k) {
        int dec=0;
        for(int i=0;i<v.size();i++) {
            if(dec>v[i]) return false;										// If prev. overlapping windows dec. curr. value to neg., we return false.
            v[i]-=dec;
            dec+=v[i];														// Starting new window from 'i' where we dec. v[i] in the next 'k' indices.
            if(i-k+1>=0) dec-=v[i-k+1];
        }
        return (dec==0);													// Confirming all values became zero and no windows were started in last 'k-1' indices.
    }
};



/*
*
//******************************************************2208. Minimum Operations to Halve Array Sum.******************************************************

https://leetcode.com/problems/minimum-operations-to-halve-array-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,19,8,1]
[3,8,20]
[6,58,10,84,35,8,22,64,1,78,86,71,77]
[18,22,62,61,1,88,17,98,38,32,51,57,7,29,40,61,62,13,89,41,73,85,88,60,59,76,71,76,76,41,29,43,19,9,79]
[4,4,4,4,4,4]


// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Greedy based. Here, at every step we greedily pick the greatest value in the array and dec. it by half, as greatest val is dec. by half,
// the dec. affect would be more, we push this dec. value into PQ once again, as this might be the highest value as we do more operations on other values. 
// We alsom keep track of total of all values, the moment total<=orig. total/2, we stop the process and return the #oper. done till then.


// In each oper. max. index's contribution dec. by half, in case it still remains the max. the next dec. can be assumed to that of dec. in next greater value,
// thus we can see that in each step every index would give away atleast half their value, thus it would take <=n oper., in an extreme case of all same values 
// in the array, #Oper. would be n.









class Solution {
public:
    int halveArray(vector<int>& v) {
        double total=0;
        priority_queue<double>pq;
        for(int num:v) {
            total+=num;
            pq.push(num);													// Calc. total of nums and adding nums to PQ.
        }
        double tempTotal=total;
        total/=2;
        int res=0;
        while(tempTotal>total) {
            double num=pq.top();
            pq.pop();
            num/=2;															// Extracting max. value an dec. it by halve for greater dec. affect on total.
            pq.push(num);													// Adding curr. value back into PQ after the oper.
            tempTotal-=num;													// Reduced total because of dec. curr. value.
            res++;															// Inc. the #oper. tracker.
        }
        return res;															// Returning min. #oper. needed to halve the total.
    }
};


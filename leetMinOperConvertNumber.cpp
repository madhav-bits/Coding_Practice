/*
*
//**********************************************2059. Minimum Operations to Convert Number.***********************************************

https://leetcode.com/problems/minimum-operations-to-convert-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,4,12]
2
12
[3,5,7]
0
-4
[2,8,16]
0
1
[5,4,7,6,435,68,34,523,44,8,67,2,45,7678,56,234,23,85]
20
345
[43,6,5673,363,756,86,344,8434,63,5887,448,8,9954,3468,32,4338,88,844,852,88394,789,5649,5699,647,656,779,799732,453,5645,5,77,45,53,4,47,34]
11
9584



// Time Complexity: O(n*m).													// n-length of the array, m-range of allowed nums in the path.
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n-length of the array, m-range of allowed nums in the path.
// Space Complexity: O(m).	
// This algorithm is Queue/BFS based. Here, even though we can use a num in the array as many times, we only use the next number if it's in [0,1000] range, so 
// essentially our search would be focused on this range and to find minSteps to reach each of the nums in the process. One exception being the target number
// if our next number is out of range we generally ignore it, but if it is target number we use this path in our shortest path/minSteps. As we are finding 
// shortest path we use BFS to get our path, we only use our next number if it's in the range and also use the target number even if it's out of range. We 
// mark the numbers which have been visited eariler in the BFS process and avoid using them again to avoid cycles. If next num after oper is in range we push it 
// in Queue for next oper if it's unvisited until now and mark it as visited, the moment we visit target, we return #steps in BFS until now as this is the 
// shortest path. If we are not able to reach target in BFS, that means there is no way to reach target with only nums in range [0,1000] being in the path.







class Solution {
public:
    int minimumOperations(vector<int>& v, int start, int goal) {
        if(start==goal) return 0;
        vector<bool>visited(1001, false);
        queue<int>q;
        q.push(start);
        visited[start]=true;
        int steps=0;
        
        while(!q.empty()) {
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++) {										// Visiting all nums at dist steps-1 from start.
                int curr=q.front();
                q.pop();
                for(int&num:v) {											// Apply oper. b/w all nums in the array and curr. number in queue.
                    if(curr+num==goal || curr-num==goal || (curr^num)==goal) return steps;// If next num after oper. = target, we return #steps in path till now.
                    int val=curr+num;
                    if(val>=0 && val<=1000 && visited[val]==false) {		// Applying (+,-,^) oper b/w curr. num in queue and nums in array.
                        q.push(val);
                        visited[val]=true;
                    }
                    val=curr-num;
                    if(val>=0 && val<=1000 && visited[val]==false) {		// If next num in unvisited, we add it to Queue and mark it visited.	
                        q.push(val);
                        visited[val]=true;
                    }
                    val=curr^num;
                    if(val>=0 && val<=1000 && visited[val]==false) {
                        q.push(val);
                        visited[val]=true;
                    }
                }
            }
        }
        return -1;															// Returning -1, if we can't reach target number.
    }
};


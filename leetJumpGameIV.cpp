/*
*
//***********************************************************1345. Jump Game IV.*****************************************************


https://leetcode.com/problems/jump-game-iv/



Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[100,-23,-23,404,100,23,23,23,3,404]
[6,1,9]
[11,22,7,7,7,7,7,7,7,22,13]
[3,6,8,3,9,6,12,6,3,5,9]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is BFS based. Here, we store the indices whose values are same in a map, to make it easier for iteration in BFS. Once the same values 
// are pushed into Queue, we erase the entry for that value from map, as we don't have to check all the similar valued indices, thus we visit each visit
// only once. The first instance when we reach the last index is the shortest path to it and we return the steps taken till then.











class Solution {
public:
    int minJumps(vector<int>& v) {
        if(v.size()==1) return 0;
        queue<int>q;
        unordered_map<int,vector<int>>m;									// Stores indices of similar value at a place.
        for(int i=0;i<v.size();i++){
            m[v[i]].push_back(i);
        }
        q.push(0);															// Start BFS from first index.
        vector<bool>visited(v.size(), false);								// Tracks the visited indices.
        visited[0]=true;
        int steps=0;									
        while(!q.empty()){
            steps++;
            int len=q.size();
            for(int i=0;i<len;i++){											// Iter. over indices at "K" dist. from origin.
                int currIndex=q.front();
                q.pop();
                if(currIndex+1<v.size() && visited[currIndex+1]==false){	// If prev. index is not visited push it into queue.
                    if((currIndex+1)==v.size()-1) return steps;
                    q.push(currIndex+1);
                    visited[currIndex+1]=true;
                }
                
                if(currIndex>0 && visited[currIndex-1]==false){				// If fol index is not visited push it into queue.
                    q.push(currIndex-1);
                    visited[currIndex-1]=true;
                }
                
                for(int nextIndex:m[v[currIndex]]){							// If similar valued indices are not visited, we push into queue. 
                    if(visited[nextIndex]) continue;
                    if(nextIndex==v.size()-1) return steps;
                    q.push(nextIndex);
                    visited[nextIndex]=true;
                }
                m.erase(v[currIndex]);										// Erase the entry for that value to avoid rechecking those indices.
            }
        }
        return -1;															
    }
};


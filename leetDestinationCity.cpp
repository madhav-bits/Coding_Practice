/*
*
//*************************************************1436. Destination City.***********************************************

https://leetcode.com/problems/destination-city/description/



You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: 
"London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[["B","C"],["D","B"],["C","A"]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map based. Here, since the graph formed is a straight line, we will have only destination city and one source city.
// These are the cities we encounter once in iteration, we differentiate them by assigning -1 for src city and +1 for dest. city. We 
// iter. over map, all the middle cities are found in src and dest. psns, so they will have val. 0 assigned to them. when we encounter 
// city val. with +1, we return the city.








class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        if(paths.size()==1) return paths[0][1];								// Base Case.
        unordered_map<string,int>m;											// Keeps track of src. and dest. cities.
        for(int i=0;i<paths.size();i++){									// Iter. over all paths.
            string node1=paths[i][0], node2=paths[i][1];
            m[node1]--;														// Src. is added -1.
            m[node2]++;														// Dest. is added +1.
        }
        for(auto it=m.begin();it!=m.end();it++)								// Iter. over map with cities stored in it.
            if(it->second==1) return it->first;								// If city with +1 found, that is dest. city.
        return "";															// Result for wrong test cases.
    }
};
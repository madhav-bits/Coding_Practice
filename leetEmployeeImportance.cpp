/*
*
//******************************************************690. Employee Importance.***********************************************

You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct 
subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 
5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note
 that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all 
his subordinates.

Example 1:
Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the 
total importance value of employee 1 is 5 + 3 + 3 = 11.
Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,[2]], [2,3,[]]]
2

[[1,2,[2]], [2,3,[3]],[3,5,[]]]
1





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map and BFS based. We convert the given data structure into map, which makes iteration and serach easier. We start 
// from the given employee, and store all of cur. empl's subordi. in the queue, and extract all the subemploye. valus and sum them, until
// you don't find any more subordinates.








/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> v, int id) {
        unordered_map<int,vector<int>>m;									// Stores curr. employee and his subordinates.
        unordered_map<int,int>values;										// Stores employee and his value.
        for(int i=0;i<v.size();i++){
            m[v[i]->id]=v[i]->subordinates;									// Converting given data structure into two other ones.
            values[v[i]->id]=v[i]->importance;
        }
        int sum=0;
        queue<int>q;														// Stores BFS nodes.
        q.push(id);
        while(!q.empty()){
            int curr=q.front();												// Extract the curr. node.
            sum+=values[curr];												// Add. the curr. employee's val. to overall sum.
            q.pop();
            // cout<<"CUrr.id: "<<curr<<" and imp: "<<values[curr]<<endl;
            vector<int>u;													// Stores curr. empl. subordinates.
            u=m[curr];
            for(int i=0;i<u.size();i++)										// We push into queue for BFS.
                q.push(u[i]);
        }
        // cout<<"The sum: "<<sum<<endl;
        return sum;															// Return the overall sum.
    }
};
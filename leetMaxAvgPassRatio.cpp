/*
*
//******************************************************1792. Maximum Average Pass Ratio.***********************************************

https://leetcode.com/problems/maximum-average-pass-ratio/


There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where 
classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students 
will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any 
class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio 
across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of 
the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[1,2],[3,5],[2,2]]
2
[[2,4],[3,9],[4,5],[2,10]]
4



// Time Complexity: O(mlogn).												// m-extraStudents, n-#classes or size of the array.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogn).												// m-extraStudents, n-#classes or size of the array.
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, for every student we add to classes each one's avg would increase differently, so we pick the class
// whose avg. would increase the more and assign the student to that class and recalculate how much it would increase for next added student and push
// it to queue. In this way for every extra student we assign him to classes whose avg. would increase the most and thus we are increasing avg. pass
// ratio of all classes by max. possible value.











class Solution {
public:
    
    struct comp{
        bool operator()(pair<double,int>&lt, pair<double,int>&rt){
            return (1.0-lt.first)/(1+lt.second)<=(1.0-rt.first)/(1+rt.second);	// Soring PQ such that class with max. inc would be on top.
        }    
    };
    
    double maxAverageRatio(vector<vector<int>>& v, int extraStudents) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,comp>pq;	// Declaring PQ with required condition.
        for(int i=0;i<v.size();i++)
            pq.push({(1.0*v[i][0])/v[i][1], v[i][1]});						// Pushing curr. avg and total students in each class.
        while(extraStudents){
            pair<double,int>pr=pq.top();									// Extracting avg. and total students of max. avg. increasing class.
            pq.pop();
            pq.push({(pr.first*pr.second+1)/(pr.second+1), pr.second+1});	// Pushing new avg and new total students of curr. class into PQ.
            extraStudents--;
        }
        double currAvg=0;													// Stores the total Avg. of all the classes.
        while(!pq.empty()){													// Extracting avg. of all the classes after adding extra students.
            currAvg+=pq.top().first;
            pq.pop();
        }
        return currAvg/v.size();											// Returning avg. pass ratio of all the classes.
    }
};


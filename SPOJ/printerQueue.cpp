/*

//*******************************************************PQUEUE - Printer Queue.*********************************************************
https://www.spoj.com/problems/PQUEUE/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(1).                                                   
// This is Priority Queu based solution. Here, push the priorities in the Priority Queue which helps in getting the highest priority 
// queue of all values from the queue. If the front it isn't the target or isn't the value with highest priority from the queue elem. 
// we pop the value from the front and push it to the back. If the front value is target, but it isn't top value, we put it back at the
// end of queue. If it is front is of priority queue but not target elem. we pop it, also we print the value(Which takes time). When we 
// get target value at front with it being the highest priority, we return time taken till now for printing+1.






#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    int jobs, target;
    for(int a=0;a<tests;a++){
        cin>>jobs>>target;
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int imp;
        for(int i=0;i<jobs;i++){
            cin>>imp;
            pq.push(imp);
            q.push({i,imp});
        }
        int time=0;
        while(q.front().first!=target || q.front().second!=pq.top()){
            // cout<<"top: "<<q.front().first<<endl;
            if(q.front().second==pq.top()){
                // cout<<"popping: "<<q.front().first<<endl;
                pq.pop();
                q.pop();
                time++;
                continue;
            }
            q.push(q.front());
            q.pop();
        }
        cout<<time+1<<endl;
    }
    

    return 0;
}
/*
*
//************************************************************853. Car Fleet.*****************************************************

https://leetcode.com/problems/car-fleet/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


12
[10,8,0,5,3]
[2,4,1,1,3]
10
[2]
[2]
200
[4,1,59,24,19,40,190,42,36,37,38,67,43,98]
[6,9,4,12,7,42,78,5,30,30,14,25,15,17]
13
[10,2,5,7,4,6,11]
[7,5,10,5,9,4,1]



// Time Complexity: O(nlogn).  												// Sorting the cars based on position and time to reach desti.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// Sorting the cars based on position and time to reach desti.
// Space Complexity: O(n).	
// This algorithm is Sorting based. Here, first we sort the cars based on their positions and time to reach destinations. Then, we iter. over cars
// and at each step, we remove all previous fleets which reach destination faster than curr. car as all these cars will form a single fleet with curr. car.
// In this way all fleets which won't meet would be in stack at any time. We return the stack size at the end of iter. as this would be the final fleets
// reaching destination.







class Solution {
public:
    
    
    float getTime(pair<int,int>&curr, int target){
        float dist=target-curr.second;
        return dist/curr.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // priority_queue<float, vector<float>, greater<float>>pq2;
//         vector<pair<int,int>>v;
//         for(int i=0;i<position.size();i++){
//             v.push_back({position[i], speed[i]});
//         }
//         sort(v.begin(), v.end());
//         for(int i=0;i<v.size();i++){
//             pair<int,int>temp={v[i].second, v[i].first};// Speed, position.
//             // cout<<"position: "<<v[i].first<<" and speed: "<<v[i].second<<endl;
//             float currTime=getTime(temp, target);
//             while(!pq2.empty() && pq2.top()<=currTime){
//                 pq2.pop();
//             }
//             pq2.push(currTime);
            
//         }
//         int res=pq2.size();
//         // cout<<"final groups: "<<endl;
//         // while(!pq2.empty()){
//         //     // cout<<"psn: "<<pq.top().second<<" and speed: "<<pq.top().first<<endl;
//         //     pq2.pop();
//         // }
//         return res;
        
		
		
		
		
		
        vector<pair<int,float>>v;
        for(int i=0;i<position.size();i++){
            float currTime=(float)(target-position[i])/speed[i];			// Calc. time to reach destination.
            v.push_back({position[i], currTime});							// Insert {position, time to Destination} entry into array.
        }
        sort(v.begin(), v.end());
        stack<float>st;
        for(int i=0;i<v.size();i++){
            // cout<<"Current psn: "<<v[i].first<<" required time: "<<v[i].second<<endl;
            while(!st.empty() && st.top()<=v[i].second){					// Removing all fleets behind curr. car which would join this car.
                // cout<<"faster: "<<st.top()<<endl;
                st.pop();
            }
            st.push(v[i].second);											// Inserting curr. car to represent the curr. fleet.
        }
        return (int)st.size();												// Returning the total #fleets at the destination.
    }
};

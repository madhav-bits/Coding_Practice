/*
*
//*******************************************2136. Earliest Possible Day of Full Bloom.********************************************

https://leetcode.com/problems/earliest-possible-day-of-full-bloom/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,3]
[2,3,1]
[1,2,3,2]
[2,1,2,1]
[1]
[1]
[3,4,5]
[1,2,3]
[5,4,3]
[3,4,5]
[4,6,7,4,3,6,8,9,9,6,4,3,5,8,7,3]
[4,6,3,7,6,4,5,2,6,8,9,4,2,8,9,4]



// Solution 2 has slightly faster Run time.
// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Greedy+ Priority Queue based. The observation is that here since the plant times can't collide, we must use total of all plant times and
// decreasing the bloom time(which can overalp with other flowers) is the only way to reduce overall bloom time. The approach is to use the flowers with 
// longer bloom time first so that it won't lead to longer overall bloom time, if we plant longer bloom times first, we will be left with smaller bloom times
// towards the end and they may produce smaller overlapping bloom time and lead to smallest total bloom time.	







class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int res=0, curr=0, totalPlantTime=accumulate(plantTime.begin(), plantTime.end(), 0);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<plantTime.size();i++) pq.push({growTime[i], plantTime[i]});// Adding {bloom time, plant time} pairs to PQ.
        while(!pq.empty()) {												// Pop all flowers.
            pair<int,int>pr=pq.top();
            pq.pop();
            if(curr+pr.first+pr.second>res) res=curr+pr.first+pr.second;	// Trying to get max. time where any of the flowers will bloom.
            curr+=pr.second;												// Increasing the plant time after curr. flower.
        }
        return res;															// Returning minTime where all flowers bloom.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Greedy+ Sorting based. This solution is same as the above one, except that it uses a sorted array to get flower with next longest bloom 
// time.









class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int res=0, curr=0, totalPlantTime=accumulate(plantTime.begin(), plantTime.end(), 0);
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++) v.push_back({growTime[i], plantTime[i]});
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for(int i=0;i<v.size();i++){
            if(curr+v[i].first+v[i].second>res) res=curr+v[i].first+v[i].second;
            curr+=v[i].second;
        }
        return res;
    }
};





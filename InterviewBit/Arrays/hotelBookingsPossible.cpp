/*
*
//***********************************************************Hotel Bookings Possible.**************************************************

https://www.interviewbit.com/problems/hotel-bookings-possible/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 3 1  5 
3 6 2  8 
3


6 1 2 3 4 5 7
6 10 8 9 11 6 12
5



3 1 2 3
3 2 3 4
1



26 41 10 12 30 0 17 38 36 45 2 33 36 39 25 22 5 41 24 12 33 19 30 25 12 36 8
26 47 20 15 65 35 51 38 36 94 30 50 38 67 64 67 24 62 38 18 59 20 74 33 43 56 32
12



2 40 18
2 40 43
1






// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. We sort the given arrays based on their start values. We push the bookings finish times into Priority 
// Queue and track the least value of finishing time. We iter. over starting times, if the curr. start time>least close time possible, we pop the
// least close time from the heap until the least close time>curr. start time. After every iter. we try to udpate the max. roomes required. If
// at the end, #rooms required>available rooms, we return false else return true.









struct compare{																// Sort vectors based on start values.
    bool operator()(const pair<int,int>& booking1,const pair<int,int>& booking2){
        return booking1.first<booking2.first;    
    }
};


bool Solution::hotel(vector<int> &arr, vector<int> &dep, int K) {
    if(arr.size()==0) return 1;												// If no bookings were made, then true.
    vector<pair<int,int>>bookings;											// Stores start,end times in same vector.
    for(int i=0;i<arr.size();i++) bookings.push_back({arr[i],dep[i]});		// Creating new vector.
    sort(bookings.begin(), bookings.end(), compare());						// Sort based on their start times.
    priority_queue<int,vector<int>,greater<int>>pq;							// Maintain min heap on finish times.
    int maxm=0;																// Tracks max. rooms needed.
    for(int i=0;i<bookings.size();i++){										// Iter. over all bookings.
        if(bookings[i].first==bookings[i].second) continue;					// If no time needed for booking ignore it.
        while(!pq.empty() && pq.top()<=bookings[i].first){					// Remove all bookings which are finished by curr. booking starts.
            pq.pop();
        }
        pq.push(bookings[i].second);										// Push the curr. finish time into PQ.
        maxm=max(maxm,(int)pq.size());										// Try to update the max. rooms needed.
    }
    // cout<<"maxm: "<<maxm<<endl;
    return (maxm<=K)?1:0;													// If maxm>available, return false else return true.
}

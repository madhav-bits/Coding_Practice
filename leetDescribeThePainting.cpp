/*
*
//******************************************************1943. Describe the Painting.******************************************************

https://leetcode.com/problems/describe-the-painting/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,4,5],[4,7,7],[1,7,9]]
[[1,7,9],[6,8,15],[8,10,7]]
[[1,4,5],[1,4,7],[4,7,1],[4,7,11]]
[[1,10,10],[1,5,6],[1,5,4],[5,10,7],[5,10,3]]
[[4,5,9],[8,12,5],[4,7,19],[14,15,1],[3,10,8],[17,20,18],[7,19,14],[8,16,6],[14,17,7],[11,13,3]]



// Time Complexity: O(n+m).													// n-length of the given array, m-range of interval psns.
// Space Complexity: O(m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-length of the given array, m-range of interval psns.
// Space Complexity: O(m).	
// This algorithm is Counting Sort based. Here, we sort the intervals based on starts which we acheive through dp array as the range of nums is small. We iter. over intervals
// and mark the indices with the color of the interval with pos. value at the start and -neg. color value at the end to mark interval closure. We track prefixSum of colors
// to track how much mix did we have at any point of time. Here, we add an possibly overlap interval color mix to res if the color mix isn't !=0, we add the color mix to res, 
// even we observe same color total value because we calc. color total at a psn indicates start/end of interval indicating that the composition of colors contributing to the 
// total changes, so we add prev. color mix to res and update color mix value to curr. total value. One exception is that we don't add color mix ==0 cause, this indicates that
// there is no interval that this color mix total value represents.



// We are lucky that none of the cases produced a scenario where neg. sum of interval colors equals INT_MIN, if equalled it would not have reflective color total and caused
// errors, one option to tackle this issue is to take a boolean array to mark which positions/indices had occurred in the given array, so using map would be a better option here.





class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& v) {
        vector<vector<long long int>>res;
        int maxm=0;
        for(int i=0;i<v.size();i++) if(v[i][1]>maxm) maxm=v[i][1];			// Tracking max. interval psn value.
        long long int dp[maxm+1];
        // memset(dp, -1, sizeof(dp));
        for(int i=0;i<=maxm;i++) dp[i]=INT_MIN;								// Setting default color mix value to INT_MIN.
        for(vector<int>&u:v) {
            dp[u[0]]=(dp[u[0]]==INT_MIN)?0ll+u[2]:dp[u[0]]+u[2];			// Storing interval colors in dp array.
            dp[u[1]]=(dp[u[1]]==INT_MIN)?0ll-u[2]:dp[u[1]]-u[2];
        }
        
        int prevPsn=-1;
        long long int prev=0, total=0;
        for(int i=0;i<=maxm;i++) {
            if(dp[i]==INT_MIN) continue;									// No interval start/close at this psn.
            total=total+dp[i];												// Tracking curr. color mix value.
            if(prev!=0) res.push_back({prevPsn, i, prev});					// If prev. color mix!=0(non-zero intrvals),we add the possible overlap to res.
            prevPsn=i;														// Updating the prevPsn, prev. color mix tracker.
            prev=total;
        }
        return res;															// Returning the non-overlap color mix intervals.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-length of the given array.
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here,we store the curr. overlapping intervals in PQ. When at an interval, we pop all intervals which ended <=curr. interval start. 
// We update the curr. color mix total tracker by removing ending intervals contribution and adding the overlap color mix to res. If non-zero intervals present, we also add
// the overlap from last close interval to curr. interval start psn. We place conditions to ensure we don't add overlap intervals ending at same psn multiple times. If there are
// multiple intervals starting at same psn, we have to add all their contribution to total mix tracker and also update last entry in res if it represents curr. overlap interval.








class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& v) {
        vector<vector<long long int>>res;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        sort(v.begin(), v.end());
        long long int prev=0, total=0;
        int prevPsn=-1;
        for(int i=0;i<v.size();i++) {
            while(!pq.empty() && pq.top().first<=v[i][0]) {
                total=total-pq.top().second;
                if(prev!=0 && prevPsn!=pq.top().first) res.push_back({prevPsn, pq.top().first, prev});// Avoiding zero-interval case and multi. intervals ending at same psn case.
                prev=total;
                prevPsn=pq.top().first;
                pq.pop();
            }
            if(prev!=0 && prevPsn!=v[i][0]) res.push_back({prevPsn, v[i][0], prev});	// Avoiding zero-interval case and multi. intervals starting at same psn case.
            prevPsn=v[i][0];												// Updating the prevPsn, prev. color mix tracker.
            total+=v[i][2];
            prev=total;	
            pq.push({v[i][1], v[i][2]});									// Adding curr. interval's end to PQ.
        }
        
        while(!pq.empty()) {												// Popping all overlapping intervals after adding all the intervals.
            total=total-pq.top().second;
            if(prev!=0 && prevPsn!=pq.top().first) res.push_back({prevPsn, pq.top().first, prev});
            prev=total;
            prevPsn=pq.top().first;
            // cout<<"prevPsn: "<<prevPsn<<endl;
            pq.pop();
        }
        return res;															// Returning the non-overlap color mix intervals.
    }
};


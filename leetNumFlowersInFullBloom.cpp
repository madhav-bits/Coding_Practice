/*
*
//************************************************2251. Number of Flowers in Full Bloom.************************************************

https://leetcode.com/problems/number-of-flowers-in-full-bloom/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,6],[3,7],[9,12],[4,13]]
[2,3,7,11]
[[1,10],[3,3]]
[3,3,2]


// Solution 2 has slightly faster runtime and better Space Complexity.
// Time Complexity: O(nlogn+mlogn).											// n-#flowers, m-#people.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogm+nlogn).									// Sorting both the arrays, PQ insertion/deletion.
// Space Complexity: O(m+n).												// n-#flowers, m-#people.	
// This algorithm is Sorting+PQ based. As flowers are sown in sequence, it's easier to process them in asc. order. We sort the flowers, people in asc. order.
// We pair {people psn, index} before sortnig them so that while iter. over people we also iter. over flowers and add ith flower to PQ if it ends>=curr.
// person and we also pop flowers from PQ which close<curr. psn and all the flowers currently in PQ are the ones which bloom currently in person's psn and 
// we use the index value attached to curr. psn and update that index in res.







class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>res(people.size(), 0);
        sort(flowers.begin(), flowers.end());
        vector<pair<int,int>>v;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<people.size();i++) v.push_back({people[i], i});		// Forming {psn,index} pair in new array.
        sort(v.begin(), v.end());											// Sorting {psn, index} array based on psns.
        int j=0;
        for(int i=0;i<v.size();i++) {
            // cout<<"curr person psn: "<<v[i].first<<endl;
			while(!pq.empty() && pq.top()<v[i].first) pq.pop();				// Pop all flowers which close before curr. psn.
            while(j<flowers.size() && flowers[j][0]<=v[i].first) {			// Add flowers in seq. which close >=curr. psn.
                if(flowers[j][1]>=v[i].first) pq.push(flowers[j][1]);
                j++;
            }
            res[v[i].second]=pq.size();										// Adding #flowers which are currently blooming.
        }
        return res;															// Returning array with #flowers blooming for each of the persons.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn+mlogn).											// n-#flowers, m-#people.
// Space Complexity: O(n).	
// This algorithm is Sorting+Binary Search based. Here, rather than using PQ to pop all flowers which closed<curr. person, we use two arrays start, close 
// which stores start, close psns of each of the flowers and we sort them based on psns. We now iter. over each person and use binary search to calc.
// #flowers which started<=curr. psn and #flowers which closed<curr. psn and we add open-close to res.









class Solution {
public:
    
    int findSmallerVals(vector<int>&v, int target) {
        if(v.back()<target) return v.size();								// If all array values<curr. psn, we return array size.
        int low=0, high=v.size()-1;
        while(low<high) {
            int mid=(low+high)/2;
            if(v[mid]<target) low=mid+1;									// If curr. psn<target, we search in upper half.
            else high=mid;													// If curr. psn>target, we maintain this index and search in lower half.
        }
        return low;															// Returning index with smallest psn>target, as it reflects #flowers psn<=target.
    }
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>res(people.size(), 0);
        vector<int>start(flowers.size(),0), close(flowers.size(), 0);
        for(int i=0;i<flowers.size();i++) {
            start[i]=flowers[i][0];
            close[i]=flowers[i][1];
        }
        sort(start.begin(), start.end());									// Sort Start, Close positions.
        sort(close.begin(), close.end());
        for(int i=0;i<people.size();i++) {
            int st=findSmallerVals(start, people[i]+1);						// Binary Search to get #flowers which started<=curr. psn.
            int cl=findSmallerVals(close, people[i]);						// Binary Search to get #flowers which close<curr. psn.
            res[i]=(st-cl);
        }
        return res;															// Returning array with #flowers blooming for each of the persons.
    }
};


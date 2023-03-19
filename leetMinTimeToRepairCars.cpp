/*
*
//******************************************************2594. Minimum Time to Repair Cars.******************************************************

https://leetcode.com/problems/minimum-time-to-repair-cars/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,3,1]
10
[5,1,8]
6
[5,3,2,8,6,7]
20



// Time Complexity: O(l*log(m*n*n)).																				// m- any rank value, n=#cars, l=#ranks
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(l*log(m*n*n)).																				// m- any rank value, n=#cars, l=#mechanics
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we chose arr[0]*cars*cars as the highest possible time, which is possible when a single mechanic works on all the cars. We do a binary search on the 
// times, for a selected time, we iter. over all the ranks and we calc. #cars each mechanic can work on in the selected time and we add all these cars. If the curr. #cars>=targetCars, this time is 
// a possible answer, so we look in the lower half. If #cars<targetCars, we need a bigger time to work on the given cars, so we look in the bigger time values and the low var at the end of binary
// search.


// This Leetcode Discussion post discusses these solutions in detail:
// https://leetcode.com/problems/minimum-time-to-repair-cars/discuss/3312003/JavaC%2B%2BPython-Binary-Search-and-Heap-Solution





class Solution {
public:
    long long repairCars(vector<int>& arr, int cars) {
        long long int low=1, high=1ll*arr[0]*cars*cars;													// arr[0]*cars*cars as upper limit, possible when 1 mechanic works on all cars.
        long long int res=0;
        while(low<high) {																				// Binary search over all the possible times.
            long long int mid=(low+high)/2;														
            long long int currCars=0;
            for(int&rank:arr) {																			// Calc. #cars that can be worked by all mechanics in the curr. time.
                currCars+=sqrt(mid/rank);
            }
            if(currCars>=cars) high=mid;																// If this time works, we look in the lower half.
            else low=mid+1;																				// If this time doesn't work, we look in the upper half.
        }
        
        return low;																						// Return the min. possible time.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n*logm).																			// n-#cars, m-#mechanics.
// Space Complexity: O(m).	
// This algorithm is Priority Queue based. At each step we pick those ranks which if picked to work on the next car, the time taken would increase by least amount. To avoid the TLE, we also
// grouped the #mechanics with same rank as one attribute of PQ entries. We remove PQ enties with least time at the top, we substract curr. entry #mechanics from the remCars, as we are assigning 1
// car to each of these mechanics in this turn. We inc. the #cars assigned to each mechanic by 1 and recalc. the time taken then and push it into PQ once again. If the remCars<=0, all our cars
// are serviced in the least possible time(which we tracked through res var), so exit the loop and return the least possible time needed.







class Solution {
public:
    long long repairCars(vector<int>& arr, int cars) {
        unordered_map<int,int>m;
        for(int&rank:arr) m[rank]++;
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>>pq;
        for(auto i:m) {
            pq.push({i.first, i.first, i.second, 1});// {rank*cars*cars, rank, count of ranks, number of cars}
        }
        
        long long int res=0;
        while(cars>0) {
            vector<long long int>curr=pq.top();
            pq.pop();
            
            res=curr[0];																				// Storing the time taken to work on cars assigned to curr. ranked mechanics.
            cars-=curr[2];																				// Removing the #mechanics from the remCars.
            curr[3]++;																					// Inc. the #cars assigned to curr. group of same ranked mechanics.
            curr[0]=curr[1]*curr[3]*curr[3];															// Recalc. the time taken after inc. the #cars assigned to each mechanic.
            pq.push(curr);
        }
        
        return res;																						// Returning the least possible time taken to work on all cars.
    }
};






//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n*logm).																				// n-#cars, m-#mechanics
// Space Complexity: O(m).	
// This algorithm is Priority Queue based.

// This solution doesn't satisfy Time Complexity requirements for 1 test case. The diff b/w Solution: 2 and this one is that this one didn't group same ranked mechanics and dealt each of them as 
// a result #entries in PQ increased a lot in few extreme cases, which made PQ insert/delete costly, which ultimately lead to TLE. I made few improvements like precalculate next car allocation for
// mechanic and allocate to him if it's lest costly by comparing to top of PQ, but this did not turn out to be that effective though.







class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto comp=[](pair<int,int>&lt, pair<int,int>&rt) {
            return (1ll*lt.first*lt.first*lt.second>1ll*rt.first*rt.first*rt.second);    
        };
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)>pq(comp);//**********{cars, rank}
        for(int&rank:ranks) {
            pq.push({1, rank});
        }
        long long int res=-1;
        
        while(cars) {
            pair<int,int>curr=pq.top();
            pq.pop();
            
            cars--;
            long long int tempProd=(1ll*pq.top().first*pq.top().first*pq.top().second)/(curr.second);				// Proactively trying to find if anymore cars can be assigned to same mechanic 
																													// while the time taken<next least time taken(top of PQ) to save some PQ push/pops.
            int numCars=sqrt(tempProd);																				// Calc. the proactively searched possibility to assign cars count.
            // cout<<"curr. cars: "<<curr.first<<" and tempProd: "<<tempProd<<" and cars: "<<numCars<<endl;
            int extra=min(cars, numCars-curr.first);
            // cout<<"extra: "<<extra<<endl;
            cars-=extra;
            curr.first+=extra;
            long long int tempTime=1ll*curr.first*curr.first*curr.second;
            if(tempTime>res) res=tempTime;
            pq.push({curr.first+1, curr.second});
            // cout<<"rank: "<<
            // cout<<"cars: "<<cars<<" and res: "<<res<<endl;
        }
        return res;
    }
};


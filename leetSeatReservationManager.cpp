/*
*
//******************************************************1845. Seat Reservation Manager.******************************************************

https://leetcode.com/problems/seat-reservation-manager/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["SeatManager","reserve","reserve","unreserve","reserve","reserve","reserve","reserve","unreserve"]
[[5],[],[],[2],[],[],[],[],[5]]



// Time Complexity: O(logn).																			// For each reserve/unreserve operation. n-#seats provided.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).																			// For each reserve/unreserve operation. n-#seats provided.
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, we store the unreserved(Seats which are reserved earlier and then released after usage) seats in a PQ. We return the least numbered seat in 
// them, if there are no unrserved seats, it means all the issued seats are currently in usage, so we check how many seats are relased till now, as all the issuing ensures least numbered seats are 
// issued first, we can certain that the 'x' issued seats are the first x seats, so we can issue 'x+1' seat now as there are no unreserved at this moment and increase the x value by 1, thus we ensure
// we release least numbered seat.








class SeatManager {
public:
    
    priority_queue<int,vector<int>, greater<int>>available;												// Stores the unreserved/released seats.
    int curr;																							// Tracks #seats had been relased till now.
    SeatManager(int n) {
        available=priority_queue<int, vector<int>, greater<int>>();
        curr=0;
    }
    
    int reserve() {
        if(!available.empty()) {																		// If unreserved seats are present.
            int res=available.top();																	// We issue the least numbered seat among them.
            available.pop();
            return res;
        }
        curr++;																							// Updating the relased seats count and return the seat number.
        return curr;
    }
    
    void unreserve(int seatNumber) {
        available.push(seatNumber);																		// Adding the unreserved seat to the PQ.
        return ;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn*32)-Reserving Seat. O(32) for unreserving seat.							// n-#seats provided.
// As updating BIT takes time proportional to number of bits in binary rep of the index.
// Space Complexity: O(n).	
// This algorithm is BIT based. Here, as we are issuing least numbered seats, I want to approach with prefixsum, so the first index where the prefixSum<curr. index is the least numbered seat which is 
// empty, this needs to be issued now. I used BIT to store the prefixSum, when searching for the least numbered free seat, I used Binary Search to find the index and update that index of BIT by 1.
// When  unreserved, we update that index in BIT by -1, making the total for that index as '0'(free).







 
class SeatManager {
public:
    
    void updateBITree(int index, int val) {																// Updating an BIT index with corresponding value when reserving/unreserving seats.
        while(index<bitArray.size()) {
            bitArray[index]+=val;
            // cout<<"Updating BIT index: "<<bitset<32>(index)<<endl;
            index+=(index&(-index));
        }    
        return ;
    }
    
    int getTotalFromBITree(int index) {																	// Calc. prefixSum for an index in BIT.
        int res=0;
        while(index>0) {
            res+=bitArray[index];
            index-=(index&(-index));
        }
        return res;
    }
    
    int getLowestIndex() {																				// Binary Search to find the least numbered free index.
        int low=1, high=cap;
        while(low<high) {
            int mid=(low+high)/2;
            if(getTotalFromBITree(mid)<mid) high=mid;													// If the prefixSum<curr. index, we searchin lower half.
            else low=mid+1;																				// Else we search in upper half as prefixSum=curr. index.
        }
        return low;
    }
                    
    vector<int>bitArray;
    int cap;
    SeatManager(int n) {
        bitArray=vector<int>(n+1, 0);
        cap=n;
    }
    
    int reserve() {
        // cout<<"reserving"<<endl;
        int leastIndex=getLowestIndex();																// Get Least numbered available seat.
        // cout<<"Assigning the lowest seat: "<<leastIndex<<endl;
        updateBITree(leastIndex, 1);																	// Updating least index in BIT with +1 to mark the seat as reserved.
        return leastIndex;																				// Returning the least numbered available seat.
    }
    
    void unreserve(int seatNumber) {
        // cout<<"unreserving"<<endl;
        updateBITree(seatNumber, -1);																	// Updating the unreserved index of BIT with -1 to make the total at that index '0'.
        // cout<<"After removing index: "<<seatNumber<<" least available index: "<<getLowestIndex()<<endl;
        return ;
    }
};


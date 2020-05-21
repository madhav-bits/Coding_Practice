/*
*
//******************************************************1429. First Unique Number.*************************************************

https://leetcode.com/problems/first-unique-number/description/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]


["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[],[6],[]]


["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]


["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]


["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[3],[],[5],[],[2],[],[6],[]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map and queue based. Here, since we want the uniq. elem. in the queue. We track the count of nums in a map, we
// keep on removing nums from the front of the queue, whose count is >1. Thus, we always have uniq. value at the front.







class FirstUnique {
public:
    unordered_map<int,int>m;							
    queue<int>uniq;															// Tracks the order of the nums.
    FirstUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(auto num:nums) m[num]++;										// Tracking #occurrences of each num.
        for(auto num:nums)													// Iter. over nums.
            if(m[num]==1) uniq.push(num);									// Storing only uniq. nums into queue.
    }
    
    int showFirstUnique() {
        if(uniq.empty()) return -1;											// If there are no uniq. nums.
        return uniq.front();												// Returning front uniq. num.
    }
    
    void add(int value) {
        m[value]++;															// Inc. count of curr. added num.
        if(m[value]==1) uniq.push(value);									// If #occurrence is 1, add to queue as it is uniq.
        else 																// Then it's cnt is >1, remove nums with cnt >1 from front.
            while(!uniq.empty() && m[uniq.front()]>1) uniq.pop();
        return ;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 

 */
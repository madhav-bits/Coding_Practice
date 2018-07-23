/*
*
//**********************************************************480. Sliding Window Median.***************************************************

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean 
of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see 
the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window 
in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note: 
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,-1,-3,2,3,6,7]
3


[1,3,-1,-3,2,3,1,7]
4


[-1,3,-1,-3,2,3,1,7]
4



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. We maintain Minheap, MaxHeap and get the median by calc. avgs of their tops. We keep track of #valid 
// elem. in heaps using two count vars.When deleting the first elem. of window, we check in which heap, they are and dec. their count. We 
// maintain the valid elem. in both heaps to satisfy the max. dist of one rule. While calc. the median, if we encounter, a value not in window
// we simply ignore them. 






class Solution {
public:
    
    struct compMin{                                        					// Min Heap implementor.
        bool operator()(const auto&lt, const auto&rt){
            return lt.first>rt.first;
        }  
    };
    
    struct compMax{                                         				// Max Heap implementor.
        bool operator()(const auto&lt, const auto&rt){
            return lt.first<rt.first;
        }  
    };
    
    unordered_map<int,int>left,right;
    void balanceHeap(priority_queue<pair<int,int>,vector<pair<int,int>>, compMax>&maxHeap, priority_queue<pair<int,int>,vector<pair<int,int>>, compMin>&minHeap, int &maxCount,int &minCount, int index, int len){
        while(minHeap.size()>0 && minHeap.top().second<=index-len) minHeap.pop();// Ignoring values out of window.
        while(maxHeap.size()>0 && maxHeap.top().second<=index-len) maxHeap.pop();
        while(minCount>1+maxCount){											// Setting max Dist of one rule, moving elem. from one heap to other.
            // cout<<"Pushed minHeap top into maxHeap: "<<minHeap.top().first<<" and index; "<< minHeap.top().second<<endl;
            right.erase(minHeap.top().second);								// Remove from minHeap, it's tracking map.
            left[minHeap.top().second]=1;									// Insert into maxHeap, insert num into it's tracking map.
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minCount--;														// Changing the count in both heaps accordingly.
            maxCount++;
        }
        
        while(maxCount>minCount){
            
            // cout<<"Pushed maxHeap top into minHeap: "<<maxHeap.top().first<<" and index; "<< maxHeap.top().second<<endl;
            left.erase(maxHeap.top().second);
            right[maxHeap.top().second]=1;
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            minCount++;
            maxCount--;
        }
        while(minHeap.size()>0 && minHeap.top().second<=index-len) minHeap.pop();// Removing any invalid nums at the top of heaps.
        while(maxHeap.size()>0 && maxHeap.top().second<=index-len) maxHeap.pop();
        return ;
    } 
    
    double findMedian(priority_queue<pair<int,int>,vector<pair<int,int>>, compMax> &maxHeap,priority_queue<pair<int,int>,vector<pair<int,int>>, compMin> &minHeap,int k){
        // cout<<"In find maxHeap top: "<<maxHeap.top().first<<" minHeap top: "<<minHeap.top().first<<endl;
        if(k%2==0) return(((double)maxHeap.top().first+minHeap.top().first)/2);// Calc. the median using heaps.
        else return minHeap.top().first;
        
    }
    
    vector<double> medianSlidingWindow(vector<int>& v, int k) {
        vector<double>res;
        if(v.size()==0) return res;
        priority_queue<pair<int,int>,vector<pair<int,int>>, compMax>maxHeap;// Setting Max Heap.
        priority_queue<pair<int,int>,vector<pair<int,int>>, compMin>minHeap;// Setting Min Heap.
        int minCount=0,maxCount=0;											// Tracks # valid elem. in both the heaps.
        for(int i=0;i<k;i++){												// Push first "k" elem. into heaps.
            if(minHeap.size()==0 || v[i]>=minHeap.top().first){
                minHeap.push({v[i],i});
                minCount++;
                right[i]=1;
            } 
            else{
                maxHeap.push({v[i],i});
                left[i]=1;
                maxCount++;
            } 
        }
        
        balanceHeap(maxHeap,minHeap,maxCount,minCount,0,1);					// Balance heaps to max size one condition.
        res.push_back(findMedian(maxHeap,minHeap,k));						// Calc. median and push into final result vector.
        for(int i=k;i<v.size();i++){										
            // cout<<"Curr. index: "<<i<<endl;
            if(v[i]>=minHeap.top().first){									// If curr. elem. >=minHeap's top, then push into minHeap.
                // cout<<"Pushed into minHeap."<<endl;
                minHeap.push({v[i],i});
                right[i]=1;													// Noting it's presence in minHeap.
                minCount++;
            } 
            else{
                // cout<<"Pushed into maxHeap."<<endl;
                maxHeap.push({v[i],i});
                left[i]=1;
                maxCount++;
            } 
            if(right.count(i-k)==1) minCount--;								// Deleting the first elem. from window.
            else maxCount--;
            // cout<<"maxHeap count: "<<maxCount<<" minHeap count: "<<minCount<<endl;
            balanceHeap(maxHeap,minHeap, maxCount,minCount,i,k);			// Call fn. to balance heaps.
            res.push_back(findMedian(maxHeap,minHeap,k));					// Calc. median and push into final result vector.
            
        }
        return res;															// Returning the final result vector.
    }
};














//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is multi set based. We insert the given length of subarray into multiset, extract the middle elem., and push it to result vector.
// If the length of window is even, we calc. avg. of middle elem. If it's odd, we return the middle elem. When deleting an elem. from window,
// if it's less than median we inc. the median to next greater value. If the newly added is less than median, we dec. the median to next smallest 
// val. In that way, we won't calculate median each and every time.







class Solution {
public:
    
    vector<double> medianSlidingWindow(vector<int>& v, int k) {
        vector<double>res;
        multiset<int>mul(v.begin(),v.begin()+k);							// Insert first k elem. into multiset.
        auto mid=next(mul.begin(),k/2);										// Extract the ptr to mid index.
        res.push_back(((double)*(mid)+*next(mid,-1+k%2))/2);				// Calc. avg. and push into result vector.
        for(int i=k;i<v.size();i++){										
            // cout<<"Curr. index: "<<i<<endl;
            mul.insert(v[i]);												// Insert the curr. val. into multiset.
            if(v[i]<*mid) mid--;											// If new value<mid value, then dec. the mid value.
            if(v[i-k]<=*mid) mid++;											// If the del. valueis <= mid value, then inc. the mid value.
            mul.erase(mul.lower_bound(v[i-k]));								// Dec. the first value from window.
            res.push_back(((double)*(mid)+*next(mid,-1+k%2))/2);			// Push the new median into result vector.
        }
        return res;															// Return the result vector.
    }
};
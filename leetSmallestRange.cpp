/*
*
//**************************************************************632. Smallest Range.*******************************************************

You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see 
this point.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]





// Time Complexity: O(nlogk).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).
// Space Complexity: O(1).	
// This algo. is Merging Sorted Arrays,Sliding Window, Priority Queue based.
// This algorithm is similar to that of Merging K Sorted Arrays. We maitain Min Heap to get sorted values. We keep track of max values in the heap.
// As we need a sequence with minRange, which contains nums from all lists  they would be in Priority Queue at the same time in an instance.So,
// we keep track of minRanges of all instances when pq size's is equal to array's size.








class Solution {
public:
    
    struct Data{															// New Data structure.
      int first;															// Num value.
      int second;															// Num's row number.
      int third;															// Num's row's clmn number.
      Data(int x,int y,int z): first(x),second(y),third(z){}
    };
    
    struct comparator{														// Min Heap constructor.
        bool operator()(const Data* lt, const Data* rt){
            return lt->first>rt->first;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // cout<<"lists: "<<nums.size()<<endl;
        vector<int>res(2,0);												// Final result vector.
        int curr=INT_MIN, occur=0, minm=INT_MAX, maxm=INT_MIN, minRange=INT_MAX;
        int ans0,ans1;														// Tracks overall min Range's start and end values.
        vector<int>index(nums.size(),0);
        int start=0,end=0;
        priority_queue<Data*, vector<Data*>,comparator>pq;
        for(int i=0;i<nums.size();i++){										// PUshing all first index values from all rows into PQ.
            pq.push(new Data(nums[i][0],i,0));
            minm=min(minm,nums[i][0]);
            maxm=max(maxm,nums[i][0]);
        } 
        while(pq.size()==nums.size()){										// We want instances when all elem. all rows are there in PQ.
            Data*curr=pq.top();
            minm=pq.top()->first;											// Get min. value from the PQ.
            if((maxm-minm<minRange)||(maxm-minm==minRange&& minm<ans0)){	// Try to update the miRange value.
                ans0=minm; ans1=maxm;
                minRange=maxm-minm;
            }
            pq.pop();														// Remove the min. value.
            if(curr->third<nums[curr->second].size()-1){					// Insert next elem. in row if possible.
                // cout<<"New elem's row: "<<curr->second<<" and index: "<<curr->third+1<<" "<<endl;
                int val=nums[curr->second][curr->third+1];
                maxm=max(maxm,val);											// Update the maxm var.
                pq.push(new Data(val,curr->second,curr->third+1));    
            }
        }
        
        res[0]=ans0; res[1]=ans1;											// Updating the final result vector.
        return res;															// Returning the final result vector.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).
// Space Complexity: O(1).	
// This algo. is Merging Sorted Arrays,Sliding Window, PriorityQueue, HashMap based.
// This algorithm is similar to that of Merging K Sorted Arrays. We maitain Min Heap to get sorted values.
// Here, I push values from PQ into a queue, where I look for instances/sequences/window where values from all rows are present in the queue, we
// extract the first and last values from the queue and try to update the overall minRange value. We also remove vals. from the start, if nums
// from that row present in the queue, thus we are reducing the minValue of the range.

// This algo. is entirely correct, it has passed 49/64 test cases. Failed at some large test case. I can't debug based on that. Gone through code 
// various times, couldn't find any mistake, need to follow this up.


class Solution {
public:
    
    struct Data{
      int first;
      int second;
      int third;
      Data(int x,int y,int z): first(x),second(y),third(z){}
    };
    
    struct comparator{
        bool operator()(const Data* lt, const Data* rt){
            return lt->first>rt->first;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // cout<<"lists: "<<nums.size()<<endl;
        queue<pair<int,int>>q;												// Stores sorted values.
        vector<int>res(2,0);
        int curr=INT_MIN, occur=0, minL=INT_MIN, minR=INT_MAX, minRange;
        vector<int>index(nums.size(),0);
        // unordered_map<int,int>count;
        int start=0,end=0;
        priority_queue<Data*, vector<Data*>,comparator>pq;
        for(int i=0;i<nums.size();i++) pq.push(new Data(nums[i][0],i,0));
        for(int i=0;i<nums.size() * nums[0].size();i++){					// Iterates till end of one of row is reached.					
            // cout<<"Curr. index: "<<i<<endl;
            Data*curr=pq.top();
            q.push(make_pair(curr->first,curr->second));
            if(count.count(curr->second)==0) occur++;
            count[curr->second]++;
            while(count[q.front().second]>1){								// If some elem's from that row exist in queue.
                count[q.front().second]--;
                q.pop();
            }
            if(((curr->first-q.front().first<minRange) || (curr->first-q.front().first==minRange && q.front().first<minL))){
                cout<<"len attained and minLen changed to: "<<curr->first-q.front().first<<endl;//occur==nums.size() && 
                minL=q.front().first;//res[0]=q.front().first;
                minR=curr->first;//res[1]=curr->first;
                minRange=curr->first-q.front().first;
                
            }
            pq.pop();
            if(curr->third<nums[curr->second].size()-1){					// If next value exists in the row.
                cout<<"New elem's row: "<<curr->second<<" and index: "<<curr->third+1<<" ";
                pq.push(new Data(nums[curr->second][curr->third+1],curr->second,curr->third+1));    
            }
                
            else break;
            cout<<"The queue size: "<<q.size()<<" and minRange: "<<occur<<endl;
        }
        res[0]=minL; res[1]=minR;
        return res;
    }
};
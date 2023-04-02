/*
*
//******************************************************2064. Minimized Maximum of Products Distributed to Any Store.******************************************************

https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6
[11,6]
7
[15,10,10]
1
[100000]
8
[15,20,3,4]
9
[15,20,1,2]
17
[15,20,1,2]



// Time Complexity: O(nlogm).																			// n-#product types provided, m-#range of products count.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogm).																			// n-#product types provided, m-#range of products count.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we observe a monotonic nature of max product count per store and it's feasibilty to be catered to all stores. If the maxProduct count is less, that results in greater capability
// to serve more stores, which wont work for us as we want to use all the products available and any store can only take one type of product, this decreases as we inc. the maxProduct count per stores, we will reach a point 
// which will result in ability to #stores to cater<requirement, this works as the remaining stores can be left with 0 products, this ability to serve #stores will also dec. if we keep on inc. the product per store, we use this
// monotonic nature of feasibilty and do Binary Search to find the smallest product count per store which works for us.



// This approach was explained in the below discussion post.
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/discuss/1563739/JavaC%2B%2BPython-Binary-Search




class Solution {
public:
    
    int getNumberOfParts(vector<int>&v, int len) {														// Get number of retail stores could we serve, if the max. product per shop is 'len'.
        int res=0;
        for(int&num:v) {																				// Calc. the #stores each type of product can be distributed to.
            res+=(num+len-1)/len;
        }
        return res;																						// Returning the total #stores that can be distributed to.
    }
    
    int minimizedMaximum(int n, vector<int>& v) {
        long long int total=accumulate(v.begin(), v.end(), 0ll);
        if(total<=n) return 1;																			// Base case.
        int low=1, high=*max_element(v.begin(), v.end());												// Setting the range for #products each store can be assigned.
        while(low<high) {
            int mid=(low+high)/2;
            int parts=getNumberOfParts(v, mid);															// Calc. #stores that can be served if the max. #product to each store is 'mid'.
            // cout<<"mid: "<<mid<<" and parts: "<<parts<<endl;
            if(parts<=n) high=mid;																		// If #stores<= requirement, that means rest stores can have 0 products, so we look for smaller cap in lower half.
            else low=mid+1;																				// If #stores>requirement, products would go waste,this wont work, so we search in upper half(bigger cap) to dec. #stores.
        }
        return low;																						// Returning the min. cap that would cater to all the stores.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+mlogn).																			// n-#product types, m-#stores to cater.
// Space Complexity: O(n).	
// This algorithm is Greedily+Priority Queue based. Here, we push all the product types count into PQ. At every step we greedily pick the product type(which might be catered to multiple stores) that gives the max. products to a 
// store, we distribute that to #stores curr. distributed to +1 and push back the udpated metrics into PQ.In case, multiple entries having same biggest product count to a stop, we pick the one that would lead to smallest max 
// product after the current split, update the metrics and push back into PQ. After m(#stores) steps, we return the max. product per store value.









class Solution {
public:
    int minimizedMaximum(int n, vector<int>& v) {
        long long int total=accumulate(v.begin(), v.end(), 0ll);
        if(total<=n) return 1;
        auto comp=[](vector<int>&lt, vector<int>&rt) {													// PQ condition.
            if(lt[0]!=rt[0]) return lt[0]<rt[0];														// To pick the product that gives max product count per store.
            int newL=(lt[1]/(lt[2]+1))+((lt[1]%(lt[2]+1))!=0);											// In case of same max product count, we pick it based on max product count per store after curr. split.
            int newR=(rt[1]/(rt[2]+1))+((rt[1]%(rt[2]+1))!=0);
            return newL<newR;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>pq(comp);						// PQ with {max product per store, curr. product count, curr. #stores to cater} entries.
        int res=-1;
        for(int i=0;i<v.size();i++) {																	// Pushing all products into PQ.
            pq.push({v[i], v[i], 1});
        }
        n-=v.size();
        while(n) {																						// Splitting m(#stores) times to cater to all the stores.
            vector<int>u=pq.top();
            // cout<<"curr. max: "<<u[0]<<" total: "<<u[1]<<" and splits: "<<u[2]<<endl;
            pq.pop();
            n--;
            u[2]++;
            pq.push({u[1]/u[2]+((u[1]%u[2])!=0), u[1],u[2]});											// Pushing updated metrics back into PQ.
        }
        return pq.top()[0];																				// Returning max. product count per store among all the stores.
    }
};


/*
*
//******************************************************1865. Finding Pairs With a Certain Sum.******************************************************

https://leetcode.com/problems/finding-pairs-with-a-certain-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["FindSumPairs","count","add","count","count","add","add","count"]
[[[1,1,2,2,2,3],[1,4,5,2,5,4]],[7],[3,2],[8],[4],[0,1],[1,1],[7]]



// Time Complexity: O(m+n).													// Add-O(1), Count-O(m)
// Space Complexity: O(m+n).												// m,n-lengths of two num arrays.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).													// Add-O(1), Count-O(m)
// Space Complexity: O(m+n).												// m,n-lengths of two num arrays.
// This algorithm is is Map based. Here, since the range of nums in consideration is large, we use map instead of array to track #occur. of each number. We 
// iter. each array and store their occur. in two maps. For add oper. we modify the map accordingly. The length of the second arr. 10^5> first array 10^3
// which allows more unique nums to be present, so iter. over map corres. to second array would consume lot of extra time when compared to first array's map 
// whose #unique elems' <=1000. So, we iter. over first map and find it's complement in second map and multiply their occur. to get #pairs whose sum 
// is =target and add it to res.







class FindSumPairs {
public:
    
    unordered_map<int,int>m,n;												// Stores #occur. of each num in two arr.
    vector<int>occur, arr;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int&num:nums1) m[num]++;										// Updating the occur. in each array in corres. maps.
        arr=nums2;
        for(int&num:nums2) n[num]++;
    }
    
    void add(int index, int val) {
        n[arr[index]]--;													// Updating the occur. in corres. map.
        if(n[arr[index]]==0) n.erase(arr[index]);
        arr[index]+=val;
        n[arr[index]]++;
        return ;
    }
    
    int count(int total) {
        int res=0;
        for(auto& [key, rep]:m) {											// Iter. over first map and find complement value in second map.
            if(n.count(total-key)==1) res+=(rep* n[total-key]);				// Adding possible pairs count to res.
        }
        return res;															// Returing the total #pairs whose sum is total.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).													// Add-O(1), Count-O(m)
// Space Complexity: O(m+n).												// m,n-lengths of two num arrays.
// This solution is same as the above one except that it uses map rather than unordered_map and we only iter. until map's key<total which prevents iter. unnecc.
// This pruning even though it increase time taken to update initially as a whole it increases the total time taken.











class FindSumPairs {
public:
    
    map<int,int>m;
    unordered_map<int,int>n;
    vector<int>occur, arr;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int&num:nums1) m[num]++;
        arr=nums2;
        for(int&num:nums2) n[num]++;
    }
    
    void add(int index, int val) {
        n[arr[index]]--;
        if(n[arr[index]]==0) n.erase(arr[index]);
        arr[index]+=val;
        n[arr[index]]++;
        return ;
    }
    
    int count(int total) {
        int res=0;
        for(auto& [key, rep]:m) {
            if(key>=total) break;											// Pruning condition which prevents extra iterations.
            if(n.count(total-key)==1) res+=(rep* n[total-key]);
        }
        return res;
    }
};


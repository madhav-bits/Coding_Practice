/*
*
//******************************1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers.**************************

https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[7,4]
[5,2,8,9]
[1,1]
[1,1,1]
[7,7,8,3]
[1,2,9,7]
[43024,99908]
[1864]
[2,2,2,2,2,2,2]
[2,2,2,2,2,2]




// Time Complexity: O(n*m).													// Solution 2 has faster runtime and better space complexity.
// Space Complexity: O(n).													// n-max size of two arrays.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(mlogm+nlogn+n*m).
// Space Complexity: O(n+m).	
// This algorithm is Map+Two pointers based. We insert two arrays in two maps. For every num in first array we use two ptrs to iterate over in second array to 
// find all pairs whose product is sq. of curr. num in first array. If product=target, we calc. total #triplets of curr. combination and add it to res and we 
// move both the ptrs. We repeat the same process for all nums in first array, we also call the fn. with the maps reversed to find #triplets of other type, 
// we collect total #triplets and return it.






class Solution {
public:
    
    int getPairs(map<int,int>&m, map<int,int>&n) {
        int res=0;
        for(auto it=m.begin();it!=m.end();it++) {							// Iter. over first array's map.
            auto it2=n.begin();												// Use two ptrs to calc. pairs for curr. num.
            auto it3=n.rbegin();
            long long int target=1ll*it->first*it->first;					// Calc. target value.
            while(it2!=n.end() && it3!=n.rend() && it2->first<=it3->first) {// Iter. over second array's map using tw ptrs
                // cout<<"it2: "<<it2->first<<" and it3: "<<it3->first<<endl;
                long long int total=1ll*it2->first*it3->first;				// Calc. product of pair.
                if(total==target) {											// If product of pair =target.
                    if(it2->first==it3->first) res+=(it->second*(((it2->second-1)*(it2->second))/2));// If curr. num and pair have same val, use nc2 to calc. pairs.
                    else res+=(it->second*it2->second*it3->second);			// Calc. total #triplets
                    it2++;													// Move left, right ptr.
                    it3++;
                    // cout<<"res: "<<res<<endl;
                } else if(total<target) it2++;								// If product is smaller, move left ptr.
                else it3++;													// If product is higher, move right ptr.
            }
        }
        return res;															// Returning total #triplets.
    }
    
    int numTriplets(vector<int>& u, vector<int>& v) {
        int res=0;
        map<int,int>m,n;
        for(int&num:u) m[num]++;
        for(int&num:v) n[num]++;
        res+=getPairs(m,n);													// Call fn. to get #triplets where two nums in v  product is sq. of nums in u.
        res+=getPairs(n,m);													// Call fn. to get #triplets where two nums in u product is sq. of nums in v.
        return res;															// Returning total #triplets where pair's product is sq. of num in other array.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n).													// n-max size of two arrays.
// This algorithm is Map based. As for each val in first array, we iter. over second arr's map entirely as part of Two ptr method, we also get same time compl.
// if we calculate second number of the pair directly in the map in every step of iter. we can cover all pairs, we can do this using "unordered_map", which 
// improves run time not asymptotically though.






class Solution {
public:
    
    int getPairs(vector<int>&v, vector<int>&u) {
        unordered_map<int,int>m;
        for(int&num:u) m[num]++;											// Inserting second array nums in map.
        int res=0;
        for(int&num:v) {													// Iter. over first array.
            long long int target=1ll*num*num;								// Calc. target value.
            for(auto it=m.begin();it!=m.end();it++) {						// Iter. over map to easily search the other pair for curr. num in iter.
                if(target%it->first!=0 || m.count(target/it->first)==0) continue;// If curr. num can't form pair, we skip it.
                if(target/it->first==it->first) res+=it->second*(it->second-1);// If curr. num and it's pair have same val, we use nc2 to form pairs.
                else res+=it->second*m[target/it->first];					// We multiply #occur. of curr. num and #occur of it's pair num to get total #pairs.
            }
        }
        return res/2;														// As we counted each pair twice in the process, we divide by 2.
    }
    
    int numTriplets(vector<int>& u, vector<int>& v) {
        int res=0;
        res+=getPairs(u,v);													// Call fn. to get #triplets where two nums in v  product is sq. of nums in u.
        res+=getPairs(v,u);													// Call fn. to get #triplets where two nums in u product is sq. of nums in v.
        return res;															// Returning total #triplets where pair's product is sq. of num in other array.
    }
};



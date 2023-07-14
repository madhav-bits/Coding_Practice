/*
*
//******************************************************2333. Minimum Sum of Squared Difference.******************************************************

https://leetcode.com/problems/minimum-sum-of-squared-difference/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4]
[2,10,20,19]
0
0
[1,4,10,12]
[5,8,6,9]
1
1
[2,2,2,2,2,2,2,2,2]
[4,4,4,5,5,5,5,6,6]
22
5


// These Time, Space complexities are of Solution: 4.
// Time Complexity: O(n+m).													// n-#elem. in the nums array, m-max. abs. diff. value.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
//***********************************************I feel Solution: 4 this is the best solution.:**************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+nlogn).												// n-#elem. in the nums array.
// Space Complexity: O(n).	
// This algorithm is Greedy+Priority Queue based. Here, we greedily pick the higher nums as they contribute most to the total and dec. their value by 1 would 
// have greater dec. as we square and add them. We push {num, #occur} in PQ, we pop nums from PQ and dec. their value to next smallest value as long as #dec.
// is still possible and we add the decreased value to the PQ top as it's the next greatest value, we face edge case when we are trying to dec. num for the 
// last time as the req. dec. steps<available #dec. steps, we dec. them until available dec. steps gets depleted and return the res.







class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<int,int>m;
        long long res=0;
        for(int i=0;i<nums1.size();i++) {
            int val=abs(nums1[i]-nums2[i]);
            m[val]++;
            res+=(1ll*val*val);
        }
        priority_queue<vector<int>>pq;
        for(auto it=m.begin();it!=m.end();it++) {
            pq.push({it->first, it->second});								// Adding {num, #occur} into PQ.
        }
        // cout<<"initial res: "<<res<<endl;
        int total=k1+k2;
        while(total && !pq.empty()) {
            vector<int>v=pq.top();											// Highest valued num and it's occur.
            pq.pop();
            int next=(pq.empty())?0:pq.top()[0];							// Next highest valued num.
            int diff=v[0]-next;
            // cout<<"curr: "<<v[0]<<" rep: "<<v[1]<<" and next: "<<next<<" and diff: "<<diff<<endl;
            int div=total/v[1];
            if(total<diff*v[1]) {											// Last dec. step as available dec. step<req. dec. step.
                int rem=total%v[1];											// 6,6,6,6->next(2,2,2,2) with 10 available steps becomes (3,3,4,4)
                int temp=v[0]-div-1;										// Calc. extra dec. steps final value.(Above Ex: 3,3 values contribution.)
                res+=1ll*(0ll-(1ll*v[0]*v[0])+1ll*temp*temp)*rem;			// Adding the resulting sq. value after dec. value.
                // cout<<"subtraction took place1: "<<(-(v[0]*v[0])+temp*temp)*rem<<" temp: "<<temp<<endl;
                
                v[1]-=rem;													// #Dec. values occur.
                temp=v[0]-div;												// Calc. dec. steps final value(Above Ex: 4,4 values.)
                res+=1ll*(0ll-(1ll*v[0]*v[0])+1ll*temp*temp)*v[1];			// Adding the resulting sq. value after dec. value.
                // cout<<"subtraction took place2: "<<(-(v[0]*v[0])+temp*temp)*v[1]<<endl;
                total=0;
            } else{
                res+=1ll*(0ll-(1ll*v[0]*v[0])+1ll*next*next)*v[1];			// Adding the resulting sq. value after dec. value.
                // cout<<"subtraction took place3: "<<(-(v[0]*v[0])+next*next)*v[1]<<endl;
                if(!pq.empty()) {											// If next value exists, we add curr. value's #occur. to next highest value.
                    vector<int>temp=pq.top();
                    pq.pop();
                    temp[1]+=v[1];											// Adding curr. value's #occur. to next highest value.
                    pq.push(temp);
                }
                total-=diff*v[1];											// Dec. #dec. steps used.
            }
            // cout<<"new total: "<<res<<endl;
        }
        return res;															// Returning the final sum of squared diffs.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*logm).												// n-#elem. in the nums array, m-max. value in the nums array.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, as we observe a monotonic nature in dec. values and it's feasibility. We do bin. search from 1 to max. value in
// array and check if dec. to such value is possible. We know that we have to use up all dec. steps to get the least squared total. If we dont have enough steps
// to dec. all greater values to a num, we also won't be dec. all greater values to curr. val's lesser values, so we focus on upper half else we track rem.
// steps in another var and search in lower half for even smaller we can convert all greater nums to, thus we can reach highest possible number we can dec. to.













class Solution {
public:
    long long minSumSquareDiff(vector<int>& u, vector<int>& v, int k1, int k2) {
        for(int i=0;i<u.size();i++) {
            u[i]=abs(u[i]-v[i]);
        }
        int maxm=*max_element(u.begin(), u.end());
        int low=0, high=maxm, rem=0, totalSteps=k1+k2;
        long long res=0;
        while(low<=high) {
            long long int steps=0;
            int mid=(low+high)/2;
            for(int i=0;i<u.size();i++) {
                if(u[i]>mid) steps+=(u[i]-mid);								// Calc. total #dec. steps needed to dec. all higher values to 'mid' value.
            }
            // cout<<"mid: "<<mid<<" and steps: "<<steps<<endl;
            if(steps>totalSteps) low=mid+1;									// If provided dec. steps doesn't help us reach here, we search in upper half.
            else {															// If provided dec. steps help us reach here, we search in lower half.
                rem=totalSteps-steps;										// Calc. rem steps and we dec. few of the curr. vals' occur. to curr. val-1 to use
                high=mid-1;													// all provided dec. steps.
            }
        }
        // cout<<"low: "<<low<<" and rem: "<<rem<<endl;
        for(int i=0;i<u.size();i++) {										// Higher values are converted to least possible dec. value's final value.
            res+=(u[i]<low)?1ll*u[i]*u[i]:(--rem>=0 && low>0)?1ll*(low-1)*(low-1):1ll*low*low;
        }
        return res;															// Returning the final sum of squared diffs.
    }
};












//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n-#elem. in the nums array.
// Space Complexity: O(1).	
// This algorithm is similar to Soution 1. except that we use reverse sorted to provide as the functionality as PQ, i.e., providing curr. highest number. 
// During iteration if we are at 'i' index that means we have converted all higher values to curr. index's value. As we are dec. curr. value to next smallest 
// number/next index, we calc. #moves needed=gap b/w adj. nums*(#nums till here which is:i+1), based on availability we dec. as many values as possible and
// add dec. valued contribution to res and return it at the end of iter.







class Solution {
public:
    long long minSumSquareDiff(vector<int>& u, vector<int>& v, int k1, int k2) {
        long long int res=0, totalMoves=k1+k2;
        for(int i=0;i<u.size();i++) {
            u[i]=abs(u[i]-v[i]);											// Calc. abs diff and also sq. value and add it to res.
            res+=1ll*u[i]*u[i];
        }
        // cout<<"initial res: "<<res<<endl;
        sort(u.rbegin(), u.rend());											// Reverse sort abs. diff values.
        u.push_back(0);
        for(int i=0;i+1<u.size() && totalMoves>0;i++) {
            int moves=(u[i]-u[i+1])*(i+1);									// Calc. #moves needed in curr. step.
            if(moves<=totalMoves) {											// If needed moves<=available moves, we simply dec. all values to next high num.
                totalMoves-=moves;
                res-=1ll*u[i]*u[i]*(i+1);									// Removing contribution from orig. number.
                res+=1ll*u[i+1]*u[i+1]*(i+1);								// Adding contribution from new/dec. number.
            }else {															// If needed moves>available moves.
                res-=1ll*u[i]*u[i]*(i+1);									// Removing contribution from orig. number.
                
                int dec=totalMoves/(i+1), extra=totalMoves%(i+1) ;			// Calc. standard dec. steps per num, extra steps left out.
                u[i]-=dec;													// Dec. the number by standard dec. steps.
                res+=1ll*u[i]*u[i]*(i+1-extra);								// Adding contribution of (nums till now-extrasteps)s number's dec. value's contrib.
                if(extra) u[i]--;											// If extrasteps present, we further dec. value by 1.
                res+=1ll*u[i]*u[i]*extra;									// Adding contribution of further dec. values's square to res.
                totalMoves=0;												// Making rem. moves to 0.
            }
            // cout<<"new res: "<<res<<" and remMoves: "<<totalMoves<<endl;
        }
        
        return res;															// Returning the final sum of squared diffs.
    }
};







//***********************************************I feel this is the best solution.:**************************************************
//************************************************************Solution 4:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-#elem. in the nums array, m-max. abs. diff. value.
// Space Complexity: O(m).	
// This algorithm is Map based. Here, since the abs. diff value is smaller, we create an array of max. abs. diff and we track #occur. of each diff. and we 
// greedily dec. the abs. diff values from highest to lowest, when we dec. a value 'x''s 'y' occur, we add these occur. to 'x-1': occur[x-1]+=y. We stop this 
// process when we convert all diffs to zero/available dec. steps have exhausted. We iter. over array once again and calc. squared values of all diffs and 
// add to res and return it.








class Solution {
public:
    long long minSumSquareDiff(vector<int>& u, vector<int>& v, int k1, int k2) {
        long long int res=0;
        int totalMoves=k1+k2;
        for(int i=0;i<u.size();i++) {
            u[i]=abs(u[i]-v[i]);											// Calc. abs. diffs of nums.
        }
        int maxm=*max_element(u.begin(), u.end());							// Calc. max. abs diff.
        vector<int>occur(maxm+1, 0);										// Creating array of max. abs diff size.
        for(int&num:u) occur[num]++;										// Tracking #occur. of each abs. diff.
        while(totalMoves>0 && maxm>0) {										// We keep on dec. diffs as long as non-zero diff exist and available dec. present.
            int rem=min(occur[maxm], totalMoves);							// Calc. #occur. we can dec. to (curr.value-1).
            totalMoves-=rem;												// Dec. available moves/dec. accordingly.
            occur[maxm--]-=rem;												// Dec. curr. diff's occur.
            occur[maxm]+=rem;												// Inc. (curr.diff-1)'s occur.
        }
        for(int i=1;i<occur.size();i++) {
            res+=1ll*occur[i]*i*i;											// Calc. squared values for all abs. diffs and adding them to res.
        }	
        return res;															// Returning the final sum of squared diffs.
    }
};


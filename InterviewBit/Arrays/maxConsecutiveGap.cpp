/*
*
//**********************************************************Maximum Consecutive Gap.**************************************************

https://www.interviewbit.com/problems/maximum-consecutive-gap/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


12 22 45 12 8 10 6 72 81 33 18 50 14


6 1 1 2 2 3 4




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Bucket Sorting based. Here, we sort the given nums into 10 buckets, based on minm, maxm values of the given set of values.
// We place them into all these buckets. Sort the individual buckets using any of sotring algos. Now, we can collect nums from these buckets
// to get the sorted values. Instead we directly, iterate over buckets, compare curr. and prev. value and obtain the maxm. of those differences.








int Solution::maximumGap(const vector<int> &v) {
    if(v.size()<=1) return 0;												// If pairs can't be formed, return 0.
    int maxm=INT_MIN, minm=INT_MAX;
    for(auto num:v){														// Calc. maxm, minm of given values.
        maxm=max(maxm,num);
        minm=min(minm,num);
    }
    vector<vector<int>>buckets(10);											// Init. 10 buckets.
    int divider=ceil(maxm-minm+1);											// Form the divider, to divide nums into buckets.
    // cout<<"maxm: "<<maxm<<" and minm: "<<minm<<" and divider: "<<divider<<endl;
    for(int i=0;i<v.size();i++){											// Iter. over given values.
        double ind=((double)v[i]-minm)/divider;								// Calc. bucket number for curr. num.
        int index=ind*10;
        // if(index>=10) cout<<"ind: "<<ind<<" and index: "<<index<<"index error at; "<<v[i]<<endl;
        buckets[index].push_back(v[i]);										// Push curr. num into it's respective bucket.
    }
    // cout<<"Buckets set"<<endl;
    for(int i=0;i<10;i++){													// Now, sort indi. buckets using any sorting methods.
        sort(buckets[i].begin(), buckets[i].end());
    }
    // cout<<"Done sorting."<<endl;
    int res=-1, prev=INT_MIN;												// Init. the final result, prev. encount. sorted value.
    for(int i=0;i<buckets.size();i++){										// Iter. over all buckets.
        // cout<<"buckets size; "<<buckets[i].size()<<endl;
        for(int j=0;j<buckets[i].size();j++){								// Iter. over curr. bucket'e elem.
            if(prev!=INT_MIN) res=max(res,buckets[i][j]-prev);				// Obtain the maxm. of diff b/w consec. sorted values.
            prev=buckets[i][j];												// Update the prev. visited sorted value.
        } 
        
    }
    return res;																// Return the maxm. diff b/w conse. sorted values.
}











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Bucket Sorting based. This algo. is same as the first one, except the number of buckets we chose to work on. Here, we chose
// vectors size #buckets, and classify nums based on it's distance from minm. value in terms of(divide by) avg. dist b/w nums. It gives the 
// buckets curr. num goes into, if we have more than 1 elem. in a bucket, then those nums are close by <avg. dist/gap, so we need not even 
// consider those diffs. As, we will be needing pair of (minm/maxm value)nums from conse. valid buckets, we maintain minm, and maxm. value in each
// bucket. In the second iter. we iter. over buckets to get the maxm. conse sorted values diff.







int Solution::maximumGap(const vector<int> &v) {
    if(v.size()<2) return 0;
    int res=0;
    int maxm=INT_MIN, minm=INT_MAX;
    for(auto num:v){
        maxm=max(maxm,num);
        minm=min(minm,num);
    }
    if(maxm==minm) return 0;
    vector<vector<int>>buckets(v.size(),vector<int>(2,-1));					// Init. buckets to store sorted values.
    float divider=(((float)maxm-minm)/(v.size()-1));						// Avg. gap b/w sorted values.
    // cout<<"maxm: "<<maxm<<" and minm: "<<minm<<" and divider: "<<divider<<endl;
    for(int i=0;i<v.size();i++){
        int ind=(int)((float)v[i]-minm)/divider;							// Calc. bucket num for curr. num.
        // cout<<"index: "<<ind<<endl;
        // if(index>=10) cout<<"ind: "<<ind<<" and index: "<<index<<"index error at; "<<v[i]<<endl;
        if(buckets[ind][0]==-1){											// If the bucket isn't init./no nums in it.
            buckets[ind][0]=v[i];											// Set curr. num as minm/maxm value.
            buckets[ind][1]=v[i];
        }
        else{																// Else, update the minm, maxm values of that bucket.
            buckets[ind][0]=min(buckets[ind][0], v[i]);
            buckets[ind][1]=max(buckets[ind][1], v[i]);
        }
    }
    // cout<<"Buckets set"<<endl;
    int ind=0;																// Track prev. encountered sorted value.
    for(int i=0;i<buckets.size();i++){
        if(buckets[i][0]!=-1){												// If curr. buckets has values in it.
            res=max(res,buckets[i][0]-buckets[ind][1]);						// Update the maxm. conse. values diff.
            ind=i;															// Update prev. visited val's index.
        }
    }
    return res;																// Return the maxm. diff b/w conse. sorted values.
}

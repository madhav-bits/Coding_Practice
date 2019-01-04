/*
*
//**************************************************************Seats.**************************************************************

https://www.interviewbit.com/problems/seats/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


x...x..xx...x..



....x..xx...x.




x





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Greedy based. Here, we have to try to push all people close to median as possible to get them consecutive to each other with
// minm. steps. Here, we first accumulate persons psns, find the mid index of them, we calculate the dist. of each person to mid index, people to
// left of mid index, if it is second person to left of mid, then it has to try to reach person[mid]-mid+i psn. People to right, which is ith 
// person to the right, will have to try to reach person[mid]-mid+i psn. We add all this distances, if the #persons are even, then we have to 
// calc. sum of steps to mid/2-1 index's psn from all person's initial psns, we have return the minm. dist of the two. If we have odd #persons, 
// then directly return the #steps to mid index's psn.








int Solution::seats(string s) {
    int mod=10000003;														// mod value.
    vector<long int>persons;												// Stores all persons indices.
    for(int i=0;i<s.length();i++){
        if(s[i]=='x') persons.push_back(i);
    }
    int psn=persons.size()/2;												// Median of all person's indices.
    long long int dist=0;													// Tracks sum of dist. all person's has to travel to gather.
    for(int i=0;i<persons.size();i++){										// Iter. over all person's indices.
        dist=(dist+abs(persons[i]-(persons[psn]-psn+i)%mod))%mod;			// Adding dist. travelled by each person.
        // cout<<"persons: "<<persons[i]<<" dist: "<<dist<<endl;
    }
    psn=persons.size()/2-1;													// Median-1 for even #persons, if present.
    // cout<<"second psn: "<<psn<<endl;
    long long int dist2=0;													// Tracks sum of dist. all persons has to travel.
    for(int i=0;i<persons.size();i++){										// Iter. over all person's indices.
        dist2=(dist2+abs(persons[i]-(persons[psn]-psn+i)%mod))%mod;			// Adding each person's distance travelled.
    }
    // cout<<"dist1: "<<dist<<endl;
    // cout<<"dist2: "<<dist2<<endl;
    return min(dist, dist2);												// Returning the minm. of the two distances.
}

/*
*
//******************************************************Smallest sequence with given Primes.***********************************************

https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



23
34
12
23

18
31
18
5





// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is BFS based. We start by pushing given three primes into Priority Queue and also into Set to avoid duplicate elements into
// Priority Queue. We extract min. elem. from the Priority Queue and add it to final result vector and pop it. We add next multiples of 
// curr. num with three given prime numbers into PQ without duplicates. Once, we get target numbers of vlaues, we return them.








vector<int> Solution::solve(int l, int m, int h, int D) {
    priority_queue<int,vector<int>, greater<int>>pq;						// To extract min. of the multiples of given prime numbers.
    int count=0;															// Num. of elem. collected.
    set<int>s;																// To avoid duplicates into PQ.
    s.insert(l);pq.push(l);													// Push into PQ, Set.
    if(s.count(m)==0){														// If not already pushed, push into PQ, Set.
        s.insert(m);
        pq.push(m);
    }
    if(s.count(h)==0){
        s.insert(h);
        pq.push(h);
    }
    vector<int>res(D,-1);													// Final result vector.
    while(!pq.empty()){														// While all mutiples are checked.
        int curr=pq.top();													// Curr. min multiple of primes.
        // cout<<"CUrr: "<<curr<<endl;
        pq.pop();											
        if(s.count(curr*l)==0){												// Calc. multiples of curr. num and push into PQ.
            pq.push(curr*l);												// If multiple already not pushed.
            s.insert(curr*l);
        }
        if(s.count(curr*m)==0){
            pq.push(curr*m);
            s.insert(curr*m);
        }
        if(s.count(curr*h)==0){
            pq.push(curr*h);
            s.insert(curr*h);
        }
        
        res[count++]=curr;													// Push curr. into final result vector.
        if(count==D) return res;											// If target #multiples collected, return the final result vector.
    }
    
}

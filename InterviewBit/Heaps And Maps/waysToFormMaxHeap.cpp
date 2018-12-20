/*
*
//*************************************************************Ways to form Max Heap.*****************************************************

https://www.interviewbit.com/problems/ways-to-form-max-heap/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



80

100

20


23

1


7


8





// Time Complexity: O((l^2*k)+logn base l*k).								// k=#internal nodes in heap.
// Space Complexity: O((l^2*k)+logn base l*k).								// l=mod value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((l^2*k)+logn base l*k).								// k=#internal nodes in heap.
// Space Complexity: O((l^2*k)+logn base l*k).								// l=mod value.
// This algorithm is recursion based. To form a Complete Bin. Tree Max. heap of certain size, the structure would be the same, it's just the values
// filling the nodes would be different. Here, we calcualate #nodes in left child and right child, and find #combinations of digits each child
// would contribute recursively and also get #ways to choose values into both childs and multiply these 3 values to get overall #combinations and
// return the result.


// Here, the main issue would arise with overflowing of int values while calcualating factorial values. For that we employ Lucas Theorem, which 
// defines method to calculate factorial with mod value.
// The theory is form this post. 
// https://www.geeksforgeeks.org/compute-ncr-p-set-2-lucas-theorem/






int nCrModpDP(int n, int r, int p) 											// Calculates fact. value for each digit in base p/mod representation.
{ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}



int nCrModpLucas(int n, int r, int p) 										// Gets base p/mod repre. of two digits and pass them to calc. fn.
{ 
   if (r==0) 
      return 1; 
   int ni = n%p, ri = r%p; 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 



long long int comb(int num, int den){										// Fn. to calcualate factorial values.
    long long int res=1;
    long long int mod=1000000007;
    res=nCrModpLucas(num, den, mod);
    // cout<<"Inside combi with num: "<<num<<" and den: "<<den<<" val: "<<res<<endl;
    return res;
}

long long int formTree(int num){
    if(num<=1) return 1;
    long int mod=1000000007; 
    int lt, rt;
    int ht=ceil(log2(num+1));												// Height of the tree.
    long long int lastRow=pow(2,ht-1);										// Max. possible nodes in last row.
    long long int lr=num-lastRow+1;											// #nodes in last row of this Tree.
    // cout<<"ht: "<<ht<<" lastRow: "<<lastRow<<" lr: "<<lr<<endl;
    lt=min(lastRow/2,lr)+(lastRow-2)/2;										// #nodes in left child.
    rt=num-1-lt;															// #nodes in right child.
    long long int combi=comb(num-1,lt);
    // cout<<"num: "<<num<<" and combi: "<<combi<<endl;
    long long int res=1;
    // cout<<"num: "<<num<<" and lt: "<<lt<<" and rt: "<<rt<<endl;
    res=(res*combi)%mod;													// Multiply #ways to choose nums. into child.
    long long int ltRes=formTree(lt);										// #Ways to form Max. Heap with given #elem. in it.
    long long int rtRes=formTree(rt);
    res=(res*ltRes)%mod;													// Multiply #ways obtained from both child.
    res=(res*rtRes)%mod;
    // cout<<"num: "<<num<<" combi: "<<combi<<" and ltRes: "<<ltRes<<" and rtRes: "<<rtRes<<endl;
    // cout<<"Num: "<<num<<" and res: "<<res<<endl;
    return res;																// Returning #ways to form Max. heap with given #elem in it.
}

int Solution::solve(int num) {
    int res=0;
    res=formTree(num);														// Call fn. to get #ways to form Max. Heap.
    return res;																// Return the #Ways to form Max. Heap.
    
}

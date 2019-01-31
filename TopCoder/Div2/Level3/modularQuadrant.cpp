

/*
//*********************************************************************Three Part Split.*************************************************************
https://community.topcoder.com/stat?c=problem_statement&pm=15235



	
We are looking at the first quadrant of an infinite square grid. Its rows and columns are numbered starting from zero. Each cell (r,c) contains the number (max(r,c) mod 3).

Compute and return the sum of all cells (r,c) such that r1 <= r <= r2 and c1 <= c <= c2.

 
Definition
    	
Class:	ModularQuadrant
Method:	sum
Parameters:	int, int, int, int
Returns:	long
Method signature:	long sum(int r1, int r2, int c1, int c2)
(be sure your method is public)
    
 
Constraints
-	0 <= r1 <= r2 <= 10^9.
-	0 <= c1 <= c2 <= 10^9.
 
Examples
0)	
    	
0
2
1
4
Returns: 13
We want rows 0 through 2 and columns 1 through 4. The corresponding part of the grid looks as follows:
2201
1201
1201
1)	
    	
2
2
0
7
Returns: 10
Now we are computing the sum of a single row that looks as follows:
22201201
2)	
    	
4
8
0
5
Returns: 37
222222
111111
000000
222222
111112
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for: 
       TCO19 Single Round Match 744 Round 1 - Division I, Level One 
       TCO19 Single Round Match 744 Round 1 - Division II, Level Three




// Time Complexity: O(n)
// Space Complexity: O(1)



*/


//*********************************************************************Solution-1.*****************************************************************
// Time Complexity: O(n^2)
// Space Complexity: O(1)





#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

class ModularQuadrant{
	
public:
	long sum(int r1, int r2, int c1, int c2){								// Iter. through all indices and adding them into final count.
		long int res=0;
		for(int i=r1;i<=r2;i++){
			for(int j=c1;j<=c2;j++){
				res+=max(i,j)%3;
			}
		}
		return res;
	}	
};









//*********************************************************************Solution-2.*****************************************************************
// Time Complexity: O(n)
// Space Complexity: O(1)





long extract(int low, int high){										// Gives contribution of clmns fom (low, high] to final count.
  long res=0;
  res+=((high)/3)*3;
  if(high%3==1) res+=1;
  if(high%3==2) res+=3;
  res-=((low)/3)*3;
  if(low%3==1) res-=1;
  if(low%3==2) res-=3;
  return res;
}

long sum2(int r1, int r2, int c1, int c2){
  long int res=0;
  for(int i=r1;i<=r2;i++){
    // cout<<"i: "<<i<<endl;
    int temp=0;
    if(i>c1){																// If row is gretaer, calc. conntribution of clmns, where they would be smaller than that of row.
      int maxm=min(i,c2);
      // cout<<"maxm: "<<maxm<<endl;
      int elem=maxm-i;
      temp+=(i%3)*(maxm-c1+1);
      if(maxm<c2)															// Clmn from where clmn num. would be > row num. 
        temp+=extract(maxm,c2);
    }else{																	// If clmn is> row num. then add all clmns to final contri.
      temp+=extract(max(0,c1-1), c2);
    }
    res+=temp;
    // cout<<"temp: "<<temp<<endl;
  }
  return res;
}	
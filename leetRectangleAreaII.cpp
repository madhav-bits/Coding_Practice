/*
*
//**********************************************************850. Rectangle Area II.***************************************************

We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left 
corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
Example 2:

Input: [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.
Note:

1 <= rectangles.length <= 200
rectanges[i].length = 4
0 <= rectangles[i][j] <= 10^9
The total area covered by all rectangles will never exceed 2^63 - 1 and thus will fit in a 64-bit signed integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[0,0,1000000000,1000000000]]


[[0,0,2,2],[1,0,2,3],[1,0,3,1]]



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3logn).
// Space Complexity: O(n^2).	
// This algorithm is Normalization based. We, first normalize the diag. into just the vertices along x and y drns. Next, we iterate over the 
// rectangles. At each rec. we iterate through the corners indices which might belong to other rectangles, we calc. the area and mark it as 
// visited. When, we scan other rec., this covered part would have been already marked, that way we avoid duplicates.








class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int res=0;
          set<int> sx, sy;
          for (auto v : rectangles) sx.insert(v[0]), sy.insert(v[1]), sx.insert(v[2]), sy.insert(v[3]);// Sotres X, y cordi.
          vector<int> x(begin(sx), end(sx)), y(begin(sy), end(sy));			// Store them vector for iterator manip.
          vector<vector<int>> m(x.size(), vector<int>(y.size(), 0));		// Create a marking array to track visited areas.

          for (auto v : rectangles) {										// Scan through rectangles.
            for (auto i = lower_bound(begin(x), end(x), v[0]); *i != v[2]; ++i)//	Scan through this rect.'s length.
              for (auto j = lower_bound(begin(y), end(y), v[1]); *j != v[3]; ++j)// Scan through breadth.
                if (m[i - begin(x)][j - begin(y)]++ == 0) 					// If a part is unvisited, then count and mark as visited.
                  res = (res + ((long long)*next(i) - *i) * (*next(j) - *j)) % 1000000007;//Add to final area.
          }
          return res;														// Return the total area.
    }
};















//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Sweeping based. Here, we sweep along y axis. At each step, we count all active x cordi. which we store in map. and push 
// them into vector for random access. We iterate through the curr. rect. and make changes accordingly(rect. is starting or end at that input).
// We calc. area from prev. y height to curr. y height with all active x cordi's active in between them.





class Solution {
public:
    int rectangleArea(vector<vector<int>>& v) {
        int res=0;
        set<int>s;															// Extracts uniq. values of x.
        for(int i=0;i<v.size();i++){
            s.insert(v[i][0]);
            s.insert(v[i][2]);
        }
        unordered_map<int,int>m,rev;
        int index=0;
        for(auto num:s){													// LInks x cordi. values to indices.
            // cout<<"val: "<<num<<" with index; "<<index<<endl;
            m[num]=index++;
        }
        for(auto it:m){														// Reverse maps indices to x cordi.
            // cout<<"val: "<<it.second<<" with index; "<<it.first<<endl;
            rev[it.second]=it.first;
        }
        
        vector<int>count(m.size(),0);										// Tracks active x cordi.
        vector<vector<int>>cordi;
        for(auto r:v){														// Brings useful data for sweeping(y cordi. and x cordi)
            cordi.push_back({r[1],r[0],r[2],1});							// This indicates starting of rect.
            cordi.push_back({r[3],r[0],r[2],-1});							// This indicates end of rect.
        }
        sort(cordi.begin(), cordi.end());									// Sort it acc.to y cordi.
        long long currY=0,currX=0;											// Prev. y cordi, curr active x cordi. length.
        for(auto rec:cordi){												// Iterating through records.
            long long y=rec[0], x1=rec[1],x2=rec[2],x3=rec[3];				
            // cout<<"Y: "<<y<<" and x1: "<<x1<<" and x2: "<<x2<<endl;
            // cout<<"CurrX: "<<currX<<endl;
            res=(res+(y-currY)*currX)%1000000007;							// Extr. the area.
            currY=y;														// Updating the currY var.
            currX=0;														// Setting currX to base value.
            for(int i=m[x1];i<m[x2];i++)									// Iter. over curr. x cordi.
                count[i]+=x3;
            for(int i=0;i<m.size();i++){									// Iter. over all x cordi. and get active x cordi. over curr. to next y.
                if(count[i]>0)												// If active x cordi.
                    currX+=rev[i+1]-rev[i];									// Extract the active length.
            }
        }
        return res;															// Returning the total area.
    }
};









//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Sweeping based. Here, we sweep along y axis. At each step, we count all active x cordi. which we store in map. and push 
// them into vector for random access. We iterate through the curr. rect. and make changes accordingly(rect. is starting or end at that input).
// We calc. area from prev. y height to curr. y height with all active x cordi's active in between them.


// This algo. is same as the above one, except that it uses unique functionality in vector to get rid of dup. elem. rather than using sets to 
// maintain unique x cordi. values and uses vector to maintain index to cordi rln.




class Solution {
public:
    int rectangleArea(vector<vector<int>>& v) {
        int res=0;
        set<int>s;
        vector<int>val;
        for(int i=0;i<v.size();i++){
            // s.insert(v[i][0]);
            // s.insert(v[i][2]);
            val.push_back(v[i][0]);
            val.push_back(v[i][2]);
        }
        unordered_map<int,int>m,rev;
        int index=0;
        // for(auto num:s){
        //     // cout<<"val: "<<num<<" with index; "<<index<<endl;
        //     m[num]=index++;
        // }
        // for(auto it:m){
        //     // cout<<"val: "<<it.second<<" with index; "<<it.first<<endl;
        //     rev[it.second]=it.first;
        // }
        sort(val.begin(), val.end());
        vector<int>::iterator end_unique = unique(val.begin(), val.end());
        val.erase(end_unique, val.end());
        for(int i=0;i<val.size();i++){
            m[val[i]]=index++;
        }
        vector<int>count(m.size(),0);
        vector<vector<int>>cordi;
        for(auto r:v){
            cordi.push_back({r[1],r[0],r[2],1});
            cordi.push_back({r[3],r[0],r[2],-1});
        }
        sort(cordi.begin(), cordi.end());
        long long currY=0,currX=0;
        for(auto rec:cordi){
            long long y=rec[0], x1=rec[1],x2=rec[2],x3=rec[3];
            // cout<<"Y: "<<y<<" and x1: "<<x1<<" and x2: "<<x2<<endl;
            // cout<<"CurrX: "<<currX<<endl;
            res=(res+(y-currY)*currX)%1000000007;
            currY=y;
            currX=0;
            for(int i=m[x1];i<m[x2];i++)
                count[i]+=x3;
            for(int i=0;i<m.size();i++){
                if(count[i]>0)
                    currX+=val[i+1]-val[i];//currX+=rev[i+1]-rev[i];
            }
        }
        return res;
    }
};
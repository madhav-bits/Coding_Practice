/*
*
//**********************************************************218. The Skyline Problem.***************************************************

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose 
you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline 
formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of 
the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, 
and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a 
skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is 
merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should 
be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 
is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,9,10],[3,7,15],[5,12,12],[10,11,14],[12,14,10],[15,20,10],[19,24,8]]


[[2,9,10],[3,7,15],[5,12,12],[12,14,10],[15,20,10],[19,24,8]]

[[2,9,10],[3,7,15],[5,12,12],[10,12,11],[12,14,10],[15,20,10],[19,24,8]]


[[2,9,10],[3,7,15],[5,12,12],[10,12,11],[12,14,10],[15,20,10],[19,24,8],[25,29,5],[27,34,3],[32,37,4]]

[]


[[2,3,1]]

[[0,2,3],[2,5,3]]


[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]

[[1,2,1],[1,2,2],[1,2,3]]

[[0,5,7],[5,10,7],[5,10,12],[10,15,7],[15,20,7],[15,20,12],[20,25,7]]


// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is iterative based. We maintain two min heaps to store start and end indices of buildings. So, that we will be working on 
// edges only instead of working on all coordinates. We maintain a Max heap of heights to give out the max. height of buildings till now. 
// We exhaustively check for all edge cases and remove the unnecc. max heights and return the answer.





class Solution {
public:
    
    struct comparator{                                                  // Implements Max heap.
        bool operator()(const auto& lhs, const auto& rhs){
            return lhs.first<rhs.first;
        }
    };
    
    struct comparator2{                                                 // Implements Min Heap.
        bool operator()(const auto& lhs, const auto& rhs){
            return lhs.first>rhs.first;
        }
    };
    
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& v) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> hei;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator2> st,en;			// Min Heap of start and end indices.
        vector<int> edges;														// Edge vector containing the start, edge coordinates.
        for(int i=0;i<v.size();i++){
            st.push(make_pair(v[i][0],i));										// Min Heap of start indices.
            en.push(make_pair(v[i][1],i));										
            edges.push_back(v[i][0]);											
            edges.push_back(v[i][1]);
        }
        sort(edges.begin(), edges.end());										// sorting edges.
        int prev=INT_MIN;
        for(int i=0;i<edges.size();i++){										// Working only on edges.
            //cout<<"inside cdn. with i: "<<i<< " val: "<<edges[i]<<endl;
            if(edges[i]==st.top().first){										// If start encountered.
                //cout<<"Edge is of start: "<<v[st.top().second][2]<<endl;    	//|| v[hei.top().second][1] == v[temp.second][0] 
                if(edges[i]==en.top().first) en.pop();							// If end also has same coordi, then delete it.
                pair<int,int> temp=st.top();
                while( !hei.empty() && v[hei.top().second][1]<=edges[i])		// Rem. all nodes with coordi.<=curr. coordi.
                    hei.pop();
                
                if( hei.empty() || v[temp.second][2]>hei.top().first){			// If no curr. maxHeight or curr. height>curr. max.
                    if( !hei.empty() && (v[hei.top().second][0] == v[temp.second][0] )) // If prev. maxHeight has start index as curr., remove it.
                        res.pop_back();											
                    
                    if(prev!=v[temp.second][2]){								// If curr. value is diff from prev. value then only push in res.
                        res.push_back(make_pair(st.top().first, v[temp.second][2]));
                        prev=v[temp.second][2];									// Keeps track of prev. pushed value into final result.
                    }
                }
                hei.push(make_pair(v[temp.second][2],temp.second));           	// Pushing Height and end.
                //cout<<"Pushing height: "<<v[temp.second][2]<<" and close is: "<<v[temp.second][1]<<endl;
                st.pop();														// Removing curr. start from start Maxheap.
                //cout<<"The max. height is: "<<hei.top().first<<" and close is: "<<v[hei.top().second][1]<<endl;
            }
            else if(edges[i]==en.top().first){                           		// If End coordi. encountered.
                //cout<<"Edge is of end: "<<" and max. height is: "<<hei.top().first<<endl;
                while( !hei.empty() && v[hei.top().second][1]<=edges[i]){		// Removing prev. heights with close<curr. index.
                    hei.pop();
                }
                if(!hei.empty() && prev!=hei.top().first){						// If Prev. and curr. are diff.
                    pair<int, int> toPush=make_pair(en.top().first, hei.top().first);	// To be pushed into res.
                    res.push_back(toPush);										// Pushing into final res.
                    prev=hei.top().first;										// Updating prev. var.
                }
                else if(hei.empty()){											// If no. curr maxHeight.
                    if(res.back()==make_pair(edges[i],0)) break;		// If prev. has same value as curr. then remove it.
                    res.push_back(make_pair(edges[i],0));						// We push a new maxHeight.
                    prev=0;														// Updating the prev. var
                }	
                en.pop();														// Removing the curr. start value.
                //cout<<"The max. height is: "<<hei.top().first<<endl;
            }
            
        }
        
        return res;																// Returning the final result.
    }
};
/*
*
//**************************************************497. Random Point in Non-overlapping Rectangles.*******************************************

Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the 
space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer 
coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]
Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick 
has no arguments. Arguments are always wrapped with a list, even if there aren't any.

 




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Solution", "pick", "pick", "pick"]
[[[[1, 1, 5, 5]]], [], [], []]


["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]






// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Binary Search/Random number based. Here, first we extract #points in each rectangle provided. Since, we need predictions
// proportionate to #points in rectangle. We add #points in all rectangles. We obtain a random point in [0,totalPoints-1] and iterate through rect.
// and stop at whose points is>remaining randomPoint. In this rectangle, we obtain random x,y coordinate, which we return.
 
 
// Time complexity can be improved to (logn) using upper_bound instead of linearly searching for rectangle.
 
 
 
 
 
class Solution {
public:
    vector<vector<int>>v;													// Global var to store given rect. dimensions.
    long long area=0;														// Stores sum of all pts in rectangles.
    vector<int>u;															// Stores #points in all rectangles.
    Solution(vector<vector<int>> rects) {
        v=rects;															// Storing given rect. array.
        for(int i=0;i<v.size();i++){
            int temp=((v[i][2]-v[i][0]+1)*(v[i][3]-v[i][1]+1));
            area+=temp;														// Counting #points in all rect.
            u.push_back(temp);												// Pushing #points in all rect. in a vector.
        }
        // cout<<"xDist: "<<xDist<<" and yDist: "<<yDist<<endl;
    }
    
    vector<int> pick() {
        // for(auto ar: u)
        //     cout<<"area: "<<ar<<endl;
        int sum=area;
        // cout<<"sum: "<<sum<<endl;
        int randArea=rand()%area;											//Generating Random Point.
        // cout<<"randArea: "<<randArea<<endl;
        int xRes,yRes,ind;													// Decl result x,y coordinates, random rectangle obtained.
        for(int i=0;i<v.size();i++){										// Iter. till rectangle with random point obtained.
            int areaTemp=((v[i][2]-v[i][0]+1)*(v[i][3]-v[i][1]+1));			// Calc. #points in curr. rect.
            if(randArea-areaTemp<0){										// If random rect. obtained.
                ind=i;														// Store it's index.
                break;
            }
            else randArea-=areaTemp;										// Dec. curr. rect's #points from randomPoint.
        }
        // cout<<"ind: "<<ind<<endl;
        // int temp1=((double)rand()/RAND_MAX)*(v[ind][2]-v[ind][0]+1);		// Two ways to generate random X,Y coordinate.
        // int temp2=((double)rand()/RAND_MAX)*(v[ind][3]-v[ind][1]+1);
        int temp1= rand()%(v[ind][2]-v[ind][0]+1);							
        int temp2=rand()%(v[ind][3]-v[ind][1]+1);
        // cout<<"temp1: "<<temp1<<" and temp2: "<<temp2<<endl;
        xRes=v[ind][0]+temp1;												// Obtain Random X coordinate.
        yRes=v[ind][1]+temp2;												// Obtain Random Y coordinate.
        return vector<int>({xRes,yRes});									// Returning the random point.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
 
 
 
 
 
 
 
 
 
 
//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Binary Search/Random number based. Here, first we extract #points in each rectangle provided. Since, we need predictions
// proportionate to #points in rectangle. We add #points in all rectangles. We obtain a random area in [0,totalArea-1] and iterate through rect.
// and stop at whose area is>remaining randomArea. In this rectangle, we obtain random x,y coordinate, which we return.

// This is same as prev. one, except that the vector to store rect. at each index is removed, also slightly optimized while obtaining random
// X,Y coordinates.
 
// Time complexity can be improved to (logn) using upper_bound instead of linearly searching for rectangle.




 
 
class Solution {
public:
    vector<vector<int>>v;
    long long area=0;														// Stores sum of #points in all rect.
    Solution(vector<vector<int>> rects) {
        v=rects;
        for(int i=0;i<v.size();i++)
            area+=((v[i][2]-v[i][0]+1)*(v[i][3]-v[i][1]+1));				// Calc. sum of all points.
    }
    
    vector<int> pick() {
        int sum=area;														// Temp. storing in another var(Not req. actually).
        // cout<<"sum: "<<sum<<endl;
        int randArea=rand()%area;											// Gen. random point.
        // cout<<"randArea: "<<randArea<<endl;
        int xRes,yRes,ind;
        for(int i=0;i<v.size();i++){
            int areaTemp=((v[i][2]-v[i][0]+1)*(v[i][3]-v[i][1]+1));			// Calc. #points of curr. index.
            if(randArea-areaTemp<0){										// If random point is from this rect.
                ind=i;
                break;
            }
            else randArea-=areaTemp;
        }
        // cout<<"ind: "<<ind<<endl;
        xRes=v[ind][0]+rand()%(v[ind][2]-v[ind][0]+1);						// Gen. random X coordinate.
        yRes=v[ind][1]+rand()%(v[ind][3]-v[ind][1]+1);						// Gen. random Y coordinate.
        return vector<int>({xRes,yRes});									// Returning random point.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
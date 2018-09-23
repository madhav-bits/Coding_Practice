/*
*
//**********************************************************Points on the Straight Line.***************************************************


https://www.interviewbit.com/problems/points-on-the-straight-line/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2 1 1 2 2


1 -20 -13



5 1 1 1 1 1 1 1 1 1 1



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Hashing based. Here, as we have vertical and horizontal lines, where the lines have hori slopes and can be attained by all
// the points(Not Unique), we work on each point at a time, extract all the lines passing through it and other points. We separate out 
// duplicate, points on vertical line passing through it and sum up else slopes. After every iteration, we iter. through the map/slopes accumulated
// duplicate, vertical line's points, and try to update the maxm variable. At the end of iter. we return the maxm points on a line.








int Solution::maxPoints(vector<int> &u, vector<int> &v) {
    if(v.size()<=1) return v.size();										// Base cases.
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxm=0;																// Tracks max. points on a line.
    for(int i=1;i<v.size();i++){											// We iter. through pivot points.
        // cout<<"i: "<<i<<"x: "<<u[i]<<" y: "<<v[i]<<endl;
        unordered_map<double,int>slope;										// Tracks slope of lines passing through this point.
        int dup=1, vert=0, hori=0;											// Tracks duplicate points, points on verti. line through this point.
        for(int j=0;j<i;j++){
            // cout<<"j: "<<j<<"x: "<<u[j]<<" y: "<<v[j]<<endl;
            if(v[j]==v[i] && u[j]==u[i]){           						// Dup points.
                dup++;
                continue;
            }
            // else if(v[j]==v[i] && u[j]!=u[i]){      						//hori.
            //     hori++;
            //     continue;
            // }
            else if(v[j]!=v[i] && u[j]==u[i]){      						// Points on Vertical line(INFINITE slope).
                vert++;
                continue;
            }else{															// Else, slopes.
                double diffY=(double)v[j]-v[i];
                double diffX=(double)u[j]-u[i];
                double m=diffY/diffX;										// Calc. slope for this pair of points.
                if(slope.count(m)==1) slope[m]++;							// Update the #points on the line count.
                else slope[m]=1;											// Init. the line/slope.
            }       
        }
        maxm=max(maxm, dup+vert);											// #Points on Vertical line.
        // maxm=max(maxm, dup+hori);										
        for(auto it=slope.begin();it!=slope.end();it++){					// Iter. through else slopes.
            maxm=max(maxm, dup+it->second);									// Adding Dup. points, as they will be on all slopes.
        }
        slope.clear();														// Clearing the map to count lines through next iter./point.
    }
    
    return maxm;															// Returning maxm. points on a straight line.
}

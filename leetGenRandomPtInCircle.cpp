/*
*
//********************************************************883. Generate Random Point in a Circle.*************************************************

Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

Note:

input and output values are in floating-point.
radius and x-y position of the center of the circle is passed into the class constructor.
a point on the circumference of the circle is considered to be in the circle.
randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.
Example 1:

Input: 
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
Example 2:

Input: 
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the 
center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't 
any.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


// Not significant enough.


// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Polar based. We extract rand value for radians, which we convert into degrees. We also extract the double val, which is 
// dist from center.Now, we calculate random x,y cordinates using xNew = xCenter+randNum*cos(b), and sin(b) for yNew.


//********************************************************************************************************************************************
//********************************************************************************************************************************************
// Here, the main logic is that if we simply use predicted dist., we would get large number of values with coordinates closer to center.
//********************************************************************************************************************************************
//********************************************************************************************************************************************

// Mult. with 2*PI makes predicted degree b/w 0 to 360.



class Solution {
public:
    double rad,x,y;															// Global vars to store x,y, radius values.
    Solution(double radius, double x_center, double y_center) {
        rad=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double deg=(2*3.141592653589793238463)*((double)rand()/RAND_MAX);	// Generates rand value b/w 0 to 1, which conv. to deg.
        double dis=sqrt(((double)rand()/RAND_MAX))*rad;						// Gen. random dist. from center with radous as max. limit.
        vector<double>res(2);												// Init. vector of size 2.
        res[0]=x+dis*cos(deg);												// Calc. random x value.
        res[1]=y+dis*sin(deg);												// Calc. random y value.
        return res;															// Returning the random values.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
 
 
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Area/(4*x*y)).
// Space Complexity: O(1).	
// This algorithm is Reverse Sampling(Rejection based), we predict nums from ranging min to max x cordinates, and also along y cordinates b/w
// min. and max. If the curr. random coordinates are with in circle(it's dist from center has to <=radius), then return the coordinate else 
// recursively call the curr. fn.
 
 
 
 
 
 
 
 class Solution {
public:
    double rad,x,y;															// Global vars to store center-> x,y coordinates and radius.
    Solution(double radius, double x_center, double y_center) {
        rad=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double dx=((double) rand()/RAND_MAX);								// Gen. rand value from o to 1.
        dx=(x-rad)+dx*(2*rad);												// Convert it into num from x-rad to x+rad;
        double dy=((double) rand()/RAND_MAX);     							// Gen. rand value from o to 1.
        dy=(y-rad)+dy*(2*rad);												// Convert it into num from y-rad to y+rad;
        // cout<<"dx: "<<dx<<" and dy: "<<dy<<endl;
        double dist=sqrt(pow((dx-x),2)+pow((dy-y),2));						// Calc. dist. from center.
        if(dist<=rad) return vector<double>({dx,dy});						// If <=radiues, then pts belong to circle.
        else return randPoint();											// Else, recursively call fn.
             
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
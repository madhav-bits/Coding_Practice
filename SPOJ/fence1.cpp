/*

//******************************************************FENCE1 - Build a Fence.********************************************************
https://www.spoj.com/problems/FENCE1/




Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(1).                                                   
// This is Logic based problem. Here, semi-circle forms the maxm. area, so we calc. the radius of semicircle for given perimeter and
// calc. the area of it.






#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    float len;
    cin>>len;
    while(len!=0){
                                                    // Radius fo semi-circle: r=(l/pi)
        float area=(len*len/(2*3.14159));           // Area of semi circle:((l*l)/(2*pi));
        printf("%.2f \n", area);
        cin>>len;
    }

    return 0;
}
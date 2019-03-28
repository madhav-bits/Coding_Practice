/*

//**************************************************BSHEEP - Build the Fence.********************************************************
https://www.spoj.com/problems/BSHEEP/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Monotone Chain's algo. It's fails when submitted, but works fine for all test cases in SPOJ toolkit, looks entirely 
// similar to some referred code in git. Don't know why?






// This is the link for this algo.
// https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/


// This is the link to the code, that I referred/cross checked my code with:
// https://github.com/asimali246/Spoj-solutions/blob/master/BSHEEP.cpp#L91











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
#include<set>
#include<iomanip>



using namespace std;





struct Point{
    int x;
    int y;
    int ind;

    Point(int x1,int y1,int ind1){
        x=x1;
        y=y1;
        ind=ind1;
    }

    // bool operator<(Point&rt){
    //     return (x<rt.x ||(x==rt.x && y<rt.y));
    // }

};


// int crossProduct(Point first, Point second, Point third){
//     return (second.x-first.x)*(third.y-first.y)-(third.x-first.x)*(second.y-first.y);
// }



struct comp{
    bool operator()(Point&lt,Point&rt){
        return (lt.y<rt.y ||(lt.y==rt.y && lt.x<rt.x));
    }
};

int crossProduct(Point a, Point b, Point c){                            // Cross Product.
    int y1=a.y-b.y;                                                     // Gives >0 for ACW, <0 for CW, ==0 for collinear.
    int y2=a.y-c.y;
    int x1=a.x-b.x;
    int x2=a.x-c.x;
    return (y2*x1-y1*x2);
}


double calcDist(Point lt, Point rt){
    double res=0;
    res=((lt.x-rt.x)*(lt.x-rt.x))+((lt.y-rt.y)*(lt.y-rt.y));
    res=sqrt(res);
    return res;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, points;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>points;
        set<pair<int,int>>st;
        vector<Point>temp, v;
        int index=1, x,y;
        for(int i=1;i<=points;i++){
            cin>>x>>y;
            if(st.count({x,y})==1) continue;
            // cout<<"x: "<<x<<" and y: "<<y<<" and ind: "<<i<<endl;
            temp.push_back(Point(x,y,i));
            st.insert({x,y});
        }
        sort(temp.begin(), temp.end(), comp());
        
        v=temp;
        // for(auto num: v) cout<<"x: "<<num.x<<" and y: "<<num.y<<endl;
        vector<Point>res;
        for(int i=0;i<v.size();i++){
            while(res.size()>=2 && crossProduct(res[res.size()-2], res.back(), v[i])<=0) res.pop_back();
            res.push_back(v[i]);
        }
        // cout<<"lower hull"<<endl;
        // for(auto pts:res) 
        //     cout<<"index: "<<pts.ind<<endl;
        // cout<<"end of lower hull"<<endl;


        int len=res.size();
        if(res.size()!=v.size()){
            for(int i=v.size()-2;i>=0;i--){
                // cout<<"i: "<<i<<endl;
            while( res.size()>=len+1 && crossProduct(res[res.size()-2], res.back(), v[i])<=0) res.pop_back();
                res.push_back(v[i]);// res[res.size()-2].ind!=v[i].ind &&
            }// 
            res.pop_back();
        }
        
        double val=0;
        for(int k=0;k<res.size();k++){
            val+=calcDist(res[k], res[(k+1)%res.size()]);
        }
        printf("%.2lf\n", val );
        for(auto pts:res) 
            cout<<pts.ind<<" ";
 
        cout<<endl<<endl;
    }

    return 0;
}

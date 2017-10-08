/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

//***************** THIS IS NOT A COMPLETE CODE. STILL NEED TO WORK ON CASES WHEN FIG 2 SIDE COMPLETELY 
OVERLAPS ONLY ONE SIDE OF FIG 1.
*/

class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
          int area;
          int l1; int l2; int l3; int l4;
          l1=c-a; l2=d-b; l3=g-e; l4=h-f;
          if((a<=e && e<=c && b<=f&& f<=d && a<=g&& g<=c && b<=h&& h<=d)){
              cout<<"In if condition."<<endl;
              return abs(c-a) * abs(d-b);
          }
          else if((e<=a && a<=g && f<= b && b<=h && e<=c&& c<=g && f<= d&& d<=h)){
              cout<<"In else if 1 condiiton."<<endl;
              return abs(g-e) * abs(h-f);
          }
          else if((!(a<e && e<c) && !(b<f && f<d) && !(a<g && g<c) && !(b<h  && h<d))){
              cout<<"In else if 2 condition."<<endl;
              return (l1* l2)+ (l3* l4);
          }
          else if(h>b && h<d && e>a && e<c){
              cout<<"In else condition."<<endl;
              cout<<"l1 and l2 is: "<<abs(l1*l2)<<endl;
              cout<<"l3 and l4 is: "<<abs(l3*l4)<<endl;
              cout<<"combined value is: "<<abs(l3-l1) * abs(l4-l2)<<endl;
              return (l1* l2)+ (l3* l4)-abs(e-c)* abs(h-b);
          }
          else if(h>b && h<d && g>a && g<c){
              cout<<"If 6 "<<endl;
              return (l1* l2)+ (l3* l4)-abs(a-g)* abs(h-b);
          }
          else if(f>b && f<d && e>a && e<c){
              cout<<"If 6 "<<endl;
              return (l1* l2)+ (l3* l4)-abs(e-c)* abs(f-d);
          }
          else if(f>b && f<d && g>a && g<c){
              cout<<"If 6 "<<endl;
              return (l1* l2)+ (l3* l4)-abs(a-d)* abs(d-f);
          }
    }
};
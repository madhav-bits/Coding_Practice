/*

//*****************************************************RMID - Running Median.*********************************************************
https://www.spoj.com/problems/RMID/




Time Complexity:O(1).                                                       // O(n) for deleting median. O(1) for pushing new element.                                                                                                                                                       
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                    // O(n) for deleting median. O(1) for pushing new element.                                                  
// Space Complexity:O(n).                                                   
// This is Vector based solution. Here, since we need the median where values given to us are already sorted, we just need to return
// the value at mid index and erase that index, as a result right half of vector will be pushed a step to the left.







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

    
    vector<int>v;
    int nums=0, num;
    while(scanf("%d", &num)!=EOF){                  // Use cin>>num for testing.
        if(num==0){
            nums=0;
            v.clear();
            // cout<<endl;
            printf("\n");
        }else{
            if(num==-1){
                int mid;
                if(nums%2==0) mid=nums/2-1;
                else mid=nums/2;
                // cout<<"nums: "<<nums<<" and mid: "<<mid<<endl;
                // cout<<v[mid]<<endl;
                printf("%d\n", v[mid]);
                v.erase(v.begin()+mid);
                nums--;
            }else{
                v.push_back(num);
                nums++;
            }
        }
    }

    return 0;
}




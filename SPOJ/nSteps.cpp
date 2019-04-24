/*

//****************************************************NSTEPS - Number Steps.********************************************************
https://www.spoj.com/problems/NSTEPS/




Time Complexity:O(1).                                                       // For each query.                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                    // For each query.    
// Space Complexity:O(1).                                                   
// This is Observation based solution. The values assigned to each index follows a pattern. We return values based on that pattern.







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

    int tests, row, col;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>row>>col;
        if(row==col || row==col+2){
            if(row%2==1) cout<<row+col-1<<endl;
            else cout<<row+col<<endl;
        }else cout<<"No Number"<<endl;
    }

    return 0;
}

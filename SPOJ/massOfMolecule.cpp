/*

//***************************************************MMASS - Mass of Molecule.*******************************************************
https://www.spoj.com/problems/MMASS/



Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, since we have different layers/groups of molecules. Where inner layers effect the outer layers
// molecules count. We stack the count of molecules of inner layer on top of outer layer. Once, inner layer is completed, we add those
// molecules count to outer layer. As, entire eqn is might/might not be part of layer, we just create a global layer covering all 
// molecules. We extract #molecuels of each type in global layer and calculate their weights and return the total weight.









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



struct Node{
    long long int carb;
    long long int hyd;
    long long int oxy;

    Node(int x, int y, int z){
        carb=x;
        hyd=y;
        oxy=z;
    }
};



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    string s="";
    cin>>s;
    stack<int>st;
    stack<Node>vals;
    int temp=1;
    long long int finC=0, finH=0, finO=0;
    st.push(1);
    vals.push(Node(0,0,0));
    int i=s.length()-1;

    while(i>=0){
        // cout<<"curr. char; "<<s[i]<<endl;
        if(s[i]>='2' && s[i]<='9'){                                         // Storing #molecules of a type.
            temp=(s[i]-'0');
            // cout<<"temp val: "<<temp<<endl;    
        } 
        else if(s[i]=='C'){
            // cout<<"Temp Carb: "<<temp<<endl;
            vals.top().carb+=temp;
            temp=1;
        }else if(s[i]=='O'){
            // cout<<"Temp oxy: "<<temp<<endl;
            vals.top().oxy+=temp;
            temp=1;
        }else if(s[i]=='H'){
            // cout<<"Temp Hyd: "<<temp<<endl;
            vals.top().hyd+=temp;
            temp=1;
        }else if(s[i]==')'){
            st.push(temp);
            temp=1;
            vals.push(Node(0,0,0));
        }else if(s[i]=='('){                                                // Adding inner layer count to outer layer.
            long long int h=st.top()*vals.top().hyd;
            long long int c=st.top()*vals.top().carb;
            long long int o=st.top()*vals.top().oxy;
            // cout<<"Group Carb: "<<vals.top().carb<<endl;
            // cout<<"Group Hyd: "<<vals.top().hyd<<endl;
            // cout<<"Group Oxy: "<<vals.top().oxy<<endl;
            st.pop();
            vals.pop();

            vals.top().carb+=c;
            vals.top().hyd+=h;
            vals.top().oxy+=o;
            // st.pop();
            // vals.pop();
        }
        i--;
    }

    finH+=st.top()*vals.top().hyd;
    finC+=st.top()*vals.top().carb;
    finO+=st.top()*vals.top().oxy;
    st.pop();
    vals.pop();
    // cout<<"finH: "<<finH<<endl;
    // cout<<"finC: "<<finC<<endl;
    // cout<<"finO: "<<finO<<endl;
    cout<<(finH*1)+(finC*12)+(finO*16)<<endl;
    return 0;
}

/*
*
//**************************************************************Integer To Roman.*******************************************************


https://www.interviewbit.com/problems/integer-to-roman/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



900


1400

3999


3599


3601


1290


1101


990

98




// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. from greatest to lowest denom. in sequence. We subtract curr. denom. from num as long it is greater
// than that denom. then we move to next smaller denom. this way we iterate over denom. until the num is decreased to 0. At each step, we append
// the Roman literal to the final result str. At the end of iter. we return the Roman Literal of given num.








string Solution::intToRoman(int num) {
    string res="";															// Stores final result(Roman literal).
    vector<int>denom;														// Stores all denoms.
    denom.push_back(1);
    denom.push_back(4);
    denom.push_back(5);
    denom.push_back(9);
    denom.push_back(10);
    denom.push_back(40);
    denom.push_back(50);
    denom.push_back(90);
    denom.push_back(100);
    denom.push_back(400);
    denom.push_back(500);
    denom.push_back(900);
    denom.push_back(1000);	
    int index=denom.size()-1;												// Stores curr. denom to work on.
    unordered_map<int,string>m;												// Links Roman literals to vals.
    m[1000]="M";m[900]="CM";m[500]="D";m[400]="CD";m[100]="C";m[90]="XC";m[50]="L";
    m[40]="XL";m[10]="X";m[9]="IX";m[5]="V";m[4]="IV";m[1]="I";
    while(num){																// Iter. until val is consumed.
        if(num>=denom[index]){												// Append. curr. Roman literal  to the final result string.
            res+=m[denom[index]];
            num-=denom[index];												// Subtract curr. denom. from given number.
        }
        else index--;														// If num>curr. denom, we move to next smallest denom.
        
    }
    return res;																// Return the final result(Roman Literal).
}

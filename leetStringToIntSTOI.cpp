/*

//****************************************************8. String to Integer (atoi)*************************************************

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what 
are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather 
all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts 
a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

*****************************************************Requirements for atoi:****************************************************
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as 
possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect 
on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because 
either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable 
values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.




//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)
            return 0;
        int i=0;
        while(s.compare(i,1, " ")== 0)// Avoiding all initial white spaces.
            i++;
        int64_t result=0;//************************To avoid printing out values > INT_MAX. This data type stores > than INT_MAX.
        if(s.compare(i,1, "-")==0){// Getting to know whether it's negative integer or not.
            i++;
            while(isdigit(s[i])){// Taking into consideration(result), only integers.
                int temp=stoi(s.substr(i, 1));
                result=result*10+temp;
                if(result>INT_MAX)// Whenever the result is > INT_MAX, return INT_MIN as - sign is observed.
                    return INT_MIN;
                i++;
            }
                return (-1*result);// If result not exceeded INT_MAX, then returning only the calculated (-1*result) value.
            
        } 
        else if(isdigit(s[i]) || s.compare(i,1, "+")==0 ){// Getting to know whether it's positive integer or not.
            //cout<<"inside else condition."<<endl;// For a posi. int. + sign may/ may not present at the beginning. So, OR is used.
            if(s.compare(i,1, "+")==0)
                i++;
            while(isdigit(s[i])){// Taking into consideration(result), only integers.
                int temp=stoi(s.substr(i, 1));
                result=result*10+temp;
                if(result>INT_MAX)// Whenever the result is > INT_MAX, return INT_MAX as + sign is observed.
                    return INT_MAX;
                i++;
            }
            return result;// If result not exceeded INT_MAX, then returning only the calculated result value.
        }
        else//If it's non integer following white space, then it's considered to be zero. 
            return 0;
    }
};
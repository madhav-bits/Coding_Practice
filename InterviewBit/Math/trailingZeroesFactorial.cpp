/*
*
//**********************************************************Trailing Zeros in Factorial.***************************************************

https://www.interviewbit.com/problems/trailing-zeros-in-factorial/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


20



105



99




40



76



75



10





// Time Complexity: O(logn/log5).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we focus on trailing zeroes, which can be achieved by multiplying 5 with any even number. Since, we
// have every alternate number as even number, so need to count how many multiples of 5 we can get to multiply with even numbers. So, for every 
// num, we try to get as many 5s as divisors as possible and add it to total res and those many even numbers would be any way present.








int pow5(int num){															// Extracting 5 as divisors of curr. num.
    int res=0;																// Tracks #5s, we have as divisors.
    while(num%5==0){														// Till we have 5 as divisor.
        res++;																// Adding to 5 divisors count.
        num/=5;																// Reducing the number.
    }
    return res;																// Returning the #5s as divisors for curr. num.
}

int Solution::trailingZeroes(int n) {
    int res=0;																// Tracks #trailing zeroes.
    for(int i=1;i<=n;i++) res+=pow5(i);										// Calc. total #trailing zeroes.
    return res;
}







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log5).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we focus on trailing zeroes, which can be achieved by multiplying 5 with any even number. Since, we
// have every alternate number as even number, so need to count how many multiples of 5 we can get to multiply with even numbers. So, we iterate
// over powers of 5, and calculate #ints in the given range, which are divisible by powers of 5 and add them to final result. Ex: 125, contributes
// to 3 zeroes, so this num. will get counted 3 times, (div. by 5, div. by 25, div. by 125).





int Solution::trailingZeroes(int n) {
    int div=5;																// Init. div as 5.
    int temp=n/div;															// Get #ints which are divisible by curr. div value.
    int ans=0;																// Tracks #trailing zeroes.
    while(temp>0){															// Till #divisors aren't zero.
        ans+=temp;															// Adding curr. #ints to final result.
        div*=5;																// Inc. the divisor by 5.
        temp=n/div;															// Getting #ints divisible by new divisor.
    }
    return ans;																// Returning total #trailing zeroes.
}

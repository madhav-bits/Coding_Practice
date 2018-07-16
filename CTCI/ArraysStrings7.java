package CTCI;


/*
 * 
 * 1-7) Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
 * 
 * 
 * 
 * //Time Complexity: O(n^2).
   //Space Complexity: O(1).
 *
 */
 


//Time Complexity: O(n^2).
//Space Complexity: O(1).


// We mark whether a row/clmn as 0s by setting the start of rows and clmns of that index to 0. So, we need to deal the first row and first 
// clmn separately, by storing the occurance of 0s in them in two other vars. In the second iteration, we first iterate array except first row 
// and first clmn, if any of top of clmn/start of row of an index is 0, then set the curr. index to 0. Then,we work on first row and first clmn 
// based on values of two other vars.



import java.util.Arrays;

public class ArraysStrings6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int len=5;
		int[][]arr= new int[5][5];											// Init. an array.
		int firstRow=-1, firstClmn=-1;										// Marks whether firstRow/firstClmn has 0 or not?
		for(int []row:arr)
			java.util.Arrays.fill(row,1);									// Filling the array with 1's.
		arr[2][3]=0;
		arr[1][1]=0;
		arr[0][4]=0;
		arr[0][0]=0;
		//System.out.println("The array: "+Arrays.deepToString(arr));
		for(int[]row: arr) 
			System.out.println(Arrays.toString(row));
		System.out.println();
		
		
		for(int i=0;i<len;i++) {
			for(int j=0;j<len;j++) {
				if(arr[i][j]==0) {
					if(i==0) firstRow=0;									// If firstRow has 0, then set firstRow=0.
					else arr[i][0]=0;										// Else, mark start of row as 0.
					
					if(j==0) firstClmn=0;									// If firstClmn has 0, then set firstClmn=0.
					else arr[0][j]=0;										// Else, mark top of clmn as 0.
					
				}
			}
		}
		
		for(int i=1;i<len;i++) {											// Iterate through entire array except first row and first clmn.
			for(int j=1;j<len;j++) {
				if(arr[0][j]==0 || arr[i][0]==0) arr[i][j]=0;				// If either of them is 0, then set curr. index to 0.
			}
		}
		
		if(firstRow==0) java.util.Arrays.fill(arr[0], 0);					// Working on the first row.
		if(firstClmn==0) {													// Working on first clmn.
			for(int i=0;i<len;i++) arr[i][0]=0;
		}
		
		for(int[]row: arr) 													// Prints the array.
			System.out.println(Arrays.toString(row));
		
		
	}

}

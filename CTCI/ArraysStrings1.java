package CTCI;

public class ArraysStrings1 {
	static boolean findDup(StringBuffer str){
	    boolean[] arr= new boolean[256];
	    for(int i=0;i<str.length();i++){
	      if(arr[str.charAt(i)]==true) return false;
	      arr[str.charAt(i)]=true;
	    }
	    return true;
	  }
	
	static boolean findDup2(StringBuffer str) {
		int num=0;
		for(int i=0;i<str.length();i++) {
			if((num & (1<<str.charAt(i)-'a'))==1) return false;
			num|=(1<<str.charAt(i)-'a');
		}
		return true;
	}
	  public static void main(String[] args) {
	    boolean res;
	    StringBuffer str= new StringBuffer("abca");
	    res=findDup(str);
	    System.out.println("The result is: "+res);
	    res=findDup2(str);
	    System.out.println("The new result is: "+res);
	    System.out.println("Hello world!");
	  }
	  
}

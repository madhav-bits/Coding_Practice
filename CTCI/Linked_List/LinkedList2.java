package CTCI.Linked_List;



/*
 * 
 * 2-2) Implement an algorithm to find the nth to last element of a singly linked list.
 * 
 * 
 * 
 * //Time Complexity: O(n).												
   //Space Complexity: O(1).
 *
 */
 


//Time Complexity: O(n).													
//Space Complexity: O(1).


// We first iterate and take n steps forward, and start second iterator until second iterator reaches till end, now delete the next node of the 
// curr. first iterator.

// We assume, we will be asked to remove a node, that's in list(No out of bounds distance nodes).



class ListNode{
	int val;
	ListNode next;
	ListNode(int x) {val=x;}
}

public class LinkedList2 {
	
	static ListNode removeNthNode(ListNode node, int len) {
		ListNode temp=node, root=node;
		int count=0;
		while(count!=(len+1)) {													// Taking n steps forward.
			temp=temp.next;
			count++;
		}
		if(temp==null) {													// If it reached, null, then remove first node.
//			System.out.println("We are in temp==null");
			System.out.println("The nth to last node value: "+node.next.val);
			node=node.next;
			return node;
		}
		while(temp.next!=null) {											// Iterating until secod node reaches end.
			node=node.next;													
			temp=temp.next;
		}
		System.out.println("The nth to last node value: "+node.next.val);
		node.next=node.next.next;											// Removing next of curr. first node. 
		return root;														// Removing root of LinkedList.
	}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode root= new ListNode(1);
		System.out.println("The node val: "+root.next);
		root.next= new ListNode(2);
		root.next.next=new ListNode(3);
		root.next.next.next=new ListNode(4);
		root.next.next.next.next=new ListNode(5);
		root=removeNthNode(root,2);											// Removing 2nd elem. away from last node.
		while(root!=null) {													// Printing the Linked List.
			System.out.println("The node value: "+root.val);
			root=root.next;
		}
	}

}

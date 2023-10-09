import java.lang.Math;

class TestClass {
	public static void main(String[] args) {
		DNode node = new DNode("13", null, null);
		DoubleLinkedLists list = new DoubleLinkedLists();
		list.append("1");
		System.out.println("\n <list after: append(1)> " + list.tostr());
		list.append("2");		
		System.out.println("\n <list after: append(2)> " + list.tostr());
		list.append("3");
		System.out.println("\n <list after: append(3)> " + list.tostr());
		list.append("4");
		System.out.println("\n <list after: append(4)> " + list.tostr());		
	}
}

class DNode {
	String value;
	DNode prev;
	DNode next;

	DNode(String newValue, DNode previous, DNode next) {
		this.prev = previous;
		this.next = next;
		this.value = newValue;
	}

	/**
	 * @brief disconnects node from it's prev and next nodes
	 * @return this, disconnected node
	*/
	DNode disconnect() {
		if (this.prev != null) {
			this.prev.next=null;
		}
		if (this.next != null) {
			this.next.prev=null;
		}
		this.prev=null;
		this.next=null;
		return this;
	}

	DNode connect(DNode prev, DNode next) {
		this.prev=prev;
		if (prev != null) {
			prev.setNext(this);
		}
		this.next=next;
		if (next != null) {
			next.setPrev(this);
		}
		return this;
	}	

	DNode setPrev(DNode prev) { this.prev = prev; return this; }
	DNode setNext(DNode next) { this.next = next; return this; }
}


// TODO: rename 
class DoubleLinkedLists {
	DNode root;
	DoubleLinkedLists() {
		this.root = null;
	}

	DNode append(String value){
		if (isEmpty()) {// TODO: make isEmpty method
			this.root = new DNode(value, null, null);
		} else {
			// TODO: can be one line of code 
			moveToLast();
			//new DNode(value, null, null).connect(this.root, null);
			DNode newNode = new DNode(value, this.root, null);
			this.root.next = newNode; 
		}
		return this.root;

	}
	// TODO: implement
	//DNode prepend(){}	

	DNode moveToLast (){
		while(this.root != null && this.root.next != null) {
			this.root = this.root.next;
		}
		return this.root;
	}

	DNode moveToFirst(){
		while(this.root != null && this.root.prev != null) {
			this.root = this.root.prev;
		}
		return this.root;
	}

	DNode moveToValue(String value) {
		this.moveToFirst();
		while (this.root != null && this.root.next != null) {
			this.root = this.root.next;
			if (this.root.value == value) { break; }
		}
		return this.root;
	}	

	DNode moveToIndex(int index){
		// TODO: should throw error
		if (Math.abs(index) > lenght()) { 
			return null; 
		}
		moveToFirst();
		int steps = (index >= 0) ? index+lenght() : index;  
		while (this.root != null && this.root.next != null && steps >= 0) {
			this.root = this.root.next;
			steps--;
		}
		return this.root;
	}

	// TODO: (update whenn adding / deleting nodes) and make getter  
	int lenght() {
		moveToFirst();
		int counter = 0;
		while (this.root != null && this.root.next != null) {
			this.root = this.root.next;
			counter++;
		}	
		return counter;
	}

	boolean isEmpty() {
		return this.root == null;
	}
	
	String tostr() {
		moveToFirst();
		String output = "DoublyLinkedList(";
		while (this.root != null) {
			output += ("'" + this.root.value + "', ");
			this.root = this.root.next;
		}
		return output + ") ";
	}


	void print() {
		System.out.println("print call");
		moveToFirst();
		while (this.root != null && this.root.next != null) {
			System.out.println("print: " + this.root.value);
			//output += ("'" + this.root.value + "', ");
		}
	}

}


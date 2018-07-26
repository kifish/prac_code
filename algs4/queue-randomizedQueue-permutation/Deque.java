/******************************************************************************
 *  Compilation:  javac Deques.java
 *  Execution:    java Deques < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/13stacks/tobe.txt
 *
 *  A generic deque, implemented using a list. Each deque
 *  element is of type Item.
 *
 *  % more tobe.txt
 *  to be or not to - be - - that - - - is
 *
 *  % java LinkedStack < tobe.txt
 *  to be not that or be (2 left on stack)
 *
 ******************************************************************************/


import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;

import java.util.Iterator;
import java.util.NoSuchElementException;


/**
 *  The {@code Deque} class represents a queue and a stack of
 *  generic items.
 */
public class Deque<Item> implements Iterable<Item> {
    private int n;          // size of the deque
    private Node first;     // the front of the deque
    private Node last;      // the end of the deque

    // helper linked list class
    private class Node {
        private Item item;
        private Node next;
        private Node pre;
    }

    /**
     * Initializes an empty deque.
     */
    public Deque() { //constructor
        first = null;
        last = null;
        n = 0;
        assert check();
    }

    /**
     * Is this deque empty?
     * @return true if this deque is empty; false otherwise
     */
    public boolean isEmpty() {
        return n == 0;
    }

    /**
     * Returns the number of items in the deque.
     * @return the number of items in the deque
     */
    public int size() {
        return n;
    }

    /**
     * Adds the item to the front of the deque.
     * @param item the item to add
     */
    public void addFirst(Item item) {
        if(item == null) throw new IllegalArgumentException("Null item");
    		Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        first.pre = null;
        if(oldfirst != null) //if 0 items -> 1 items,bug:null.pre
        		oldfirst.pre = first;
        if(n==0) last = first;
        n++;
        assert check();
    }
    /*

    - sequence of operations was:
         Deque<Integer> deque = new Deque<Integer>()
         deque.addFirst(0)
         deque.removeLast()      ==> 0
         deque.isEmpty()         ==> false
         所以没有哨兵节点的情况下,用first==null判断会出问题.
    */

     /**
     * Adds the item to the end of the deque.
     * @param item the item to add
     */
    public void addLast(Item item){
        if(item == null) throw new IllegalArgumentException("Null item");
    		Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        last.pre = oldlast;
        if(oldlast != null)
        		oldlast.next = last;
        if(n==0) first = last;
        n++;
        assert check();
    }

    /**
     * Remove and return the item from the front of the deque
     * @return the item most recently added
     * @throws java.util.NoSuchElementException if this deque is empty
     */
    public Item removeFirst() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        Item item = first.item;        // save item to return
        first = first.next;            // delete first node
        if(first != null)
          first.pre = null; //avoid loitering
        n--;
        if(n==0) last = null; //avoid loitering
        assert check();
        return item;                   // return the saved item
    }

     /**
     * Remove and return the item from the end of the deque
     * @return the item least recently added
     * @throws java.util.NoSuchElementException if this deque is empty
     */
    public Item removeLast() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        Item item = last.item;        // save item to return
        last = last.pre;            // delete last node
        if(last != null)          //the number of items 1->0
          last.next = null;       //avoid loitering
        n--;
        if(n==0) first = null; //avoid loitering
        assert check();
        return item;                   // return the saved item
    }


    /**
     * Returns (but does not remove) the item most recently added to this deque.
     * @return the item most recently added to this deque
     * @throws java.util.NoSuchElementException if this deque is empty
     */
    /*
    评测系统不允许添加新的API
    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        return first.item;
    }
    */
    /*
     * Returns (but does not remove) the item least recently added to this deque.
     * @return the item least recently added to this deque
     * @throws java.util.NoSuchElementException if this deque is empty
     */
    /*
    public Item last(){
        if(isEmpty()) throw new NoSuchElementException("Stack underflow");
        return last.item;
    }
    */

    /**
     * Returns a string representation of this deque.
     * @return the sequence of items in the deque in LIFO order, separated by spaces
     */
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Item item : this)
            s.append(item + " ");
        return s.toString();
    }

    /**
     * Returns an iterator to this stack that iterates through the items in LIFO order.
     * @return an iterator to this stack that iterates through the items in LIFO order.
     */
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    // an iterator, doesn't implement remove() since it's optional
    private class DequeIterator implements Iterator<Item> {
        private Node current = first;
        public boolean hasNext()  { return current != null;}
        public void remove()      { throw new UnsupportedOperationException();}

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
    }


    // check internal invariants
    private boolean check() {

        // check a few properties of instance variable 'first'
        if (n < 0) {
            return false;
        }
        if (n == 0) {
            if (first != null|| last != null) return false;
        }
        else if (n == 1) {
            if (first == null)      return false;
            if (first.next != null||first != last) return false;
        }
        else {
            if (first == null)      return false;
            if (first.next == null) return false;
            if (last == null) return false;
            if(last.next != null) return false;
        }

        // check internal consistency of instance variable n
        int numberOfNodes = 0;
        for (Node x = first; x != null && numberOfNodes <= n; x = x.next) {
            numberOfNodes++;
        }
        if (numberOfNodes != n) return false;

        return true;
    }

    /**
     * Unit tests the {@code LinkedStack} data type.
     *
     * @param args the command-line arguments
     */
    public static void main(String[] args) {
        Deque<Integer> deque = new Deque<Integer>();

        deque.addFirst(1);
        deque.addFirst(2);
        deque.addLast(3);
        StdOut.print(deque.removeFirst());
        StdOut.print(deque.removeLast());
        StdOut.println("(" + deque.size() + " left on deque)");

        /*
        Deque<String> deque = new Deque<String>();
        Deque<String> dequeMirror = new Deque<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            //StdOut.println(item);
            if (!item.equals("-")){
                deque.addFirst(item);
                dequeMirror.addLast(item);
                //StdOut.println(item+item);
            }

            else if (!deque.isEmpty()&&!dequeMirror.isEmpty()){
              StdOut.print(deque.removeFirst() + " \n");
              StdOut.print(dequeMirror.removeLast()+ " \n");
            }

        }
        StdOut.println("(" + deque.size() + " left on deque)");
        StdOut.println("(" + dequeMirror.size() + " left on dequeMirror)");
        */
    }
}

//https://algs4.cs.princeton.edu/13stacks/ResizingArrayStack.java.html
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdRandom;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item>{
  private Item[] a;
  private int n;
  public RandomizedQueue(){
    a = (Item[]) new Object[2];
    n = 0;
  }
  public boolean isEmpty(){
    return n == 0;
  }
  public int size(){
    return n;
  }
  private void resize(int capacity){
    assert capacity >= n;
    Item[] temp = (Item[]) new Object[capacity];
    for(int i = 0;i<n;i++) temp[i] = a[i];
    a = temp;
    //alternative implementation
    // a = java.util.Arrays.copyOf(a,capacity);
  }


  public void enqueue(Item item){
    if(item == null) throw new IllegalArgumentException("Null item");
    if(n == a.length){
      double alpha = 2*Math.log(1+n);
      resize((int)(alpha*a.length));
    }

    a[n++] = item;
  }
  public Item dequeue(){ //remove and return a random item
    if(isEmpty()) throw new NoSuchElementException("Stack underflow");
    int index = StdRandom.uniform(n);//[0,n) -->int [0,n-1];
    Item item = a[index];
    a[index] = a[n-1];
    a[n-1] = null;
    n--;
    if(n>0 && n<=a.length/4) resize(a.length/2);
    return item;

  }
/*
if(n == a.length){
  alpha = 2;
  resize(alpha*a.length);
}

if(n>0 && n==a.length/4) resize(a.length/2);

  Test 3a-3e: Total memory usage after inserting 2n+1 items
            and deleting n items, where n is a power of 2.

                 n        bytes
----------------------------------------------------------
=> FAILED        8          856   (1.4x)
=> FAILED       64         6232   (1.9x)
=> FAILED      256        24664   (2.0x)
=> FAILED     1024        98392   (2.0x)
=> FAILED     4096       393304   (2.0x)
==> 0/5 tests passed

Memory: 96.00 n - 8.00   (R^2 = 1.000)

Test 4a-4e: Total memory usage after inserting n items and then
            deleting all but one item, where n is a power of 2.
            (should not grow with n or be too large of a constant)

                 n        bytes
----------------------------------------------------------
=> FAILED        8          424   (1.8x)
=> FAILED       64         3112  (13.0x)
=> FAILED      256        12328  (51.4x)
=> FAILED     1024        49192 (205.0x)
=> FAILED     4096       196648 (819.4x)
==> 0/5 tests passed

Memory after adding n = 2^i items: 71498.91   (R^2 = 0.000)


*/
  public Item sample(){ //return a random item
    if(isEmpty()) throw new NoSuchElementException("Stack underflow");
    int index = StdRandom.uniform(n);//[0,n) -->int [0,n-1];
    Item item = a[index];
    return item;
  }
  public Iterator<Item> iterator(){
    return new RandQueueIterator();
  }

  private class RandQueueIterator implements Iterator<Item>{
    private int[]  randIdxs =StdRandom.permutation(n);
    /*
    private final int[]  randIdxs =StdRandom.permutation(n);
     - iterator failed after applying operation

    */
    private int i;
    public RandQueueIterator(){
      i = 0;
    }
    public boolean hasNext(){return i<n;}
    public void remove(){throw new UnsupportedOperationException();}
    public Item next(){
      if(!hasNext()) throw new NoSuchElementException();
      return a[randIdxs[i++]];
    }
  }

  /*
  ResizingArrayStack.java
  public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    // an iterator, doesn't implement remove() since it's optional
    private class ReverseArrayIterator implements Iterator<Item> {
        private int i;

        public ReverseArrayIterator() {
            i = n-1;
        }

        public boolean hasNext() {
            return i >= 0;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            return a[i--];
        }
    }

  */
  public static void main(String[] args){
    RandomizedQueue<String> rq = new RandomizedQueue<String>();
    while(!StdIn.isEmpty()){
      String item = StdIn.readString();
      if(!item.equals("-")){
        rq.enqueue(item);
      }
      else if(!rq.isEmpty()){
        rq.dequeue();
      }
      for(String str : rq)
        StdOut.print(str + " ");

    }
    StdOut.println("\nisEmpty:"+rq.isEmpty()+"\n"+rq.size()+" left on rq");
  }
}

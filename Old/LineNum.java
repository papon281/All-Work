import java.util.*;
import java.io.*;
//A class to represent Linked List
class QNode { 
    private String key; 
    private QNode next; 
    //constructor to create a new node 
    public QNode(String key) 
    { 
        this.key = key; 
        this.next = null; 
    }

    // getter of "key"
    public String getKey(){
        return key;
    }

    // setter of "key"
    public void setKey(String key){
        this.key = key;
    }

    // setter of "next"
    public void setNext(QNode next){
        this.next = next;
    }

    // getter of "next"
    public QNode getNext(){
        return next;
    }
} 
// A class to represent a queue 
// The queue, front stores the front node reference of the linked List and rear stores the 
// last node reference of the linked List 
class Queue { 
    private QNode front, rear; 
    
    public Queue() {
        this.front = null;
        this.rear = null; 
    }
    // Method to add an key to the queue. 
    void enqueue(String key) 
    { 
  
        // Create a new LinkedList node 
        QNode temp = new QNode(key); 
  
        // If queue is empty, then new node is front and rear both 
        if (isEmpty()){
            this.front = this.rear = temp;
            return;
        }

        // Add the new node at the end of queue
        this.rear.setNext(temp);
        // update reference of the rear node
        this.rear = this.rear.getNext();
    } 
  
    // Method to remove an key from queue and return 
    public String dequeue() {
        // If queue is empty, return null.
        if (isEmpty()){
            return null; 
        }
  
        // Store current front in a temporary variable
        QNode temp = this.front;

        // move front one node ahead 
        this.front = this.front.getNext();
  
        // If front becomes null, then change rear also as NULL 
        if (isEmpty()){
            this.rear = null; 
        }
        return temp.getKey();
    }

    public boolean isEmpty(){
        return this.front==null;
    }
} 
  
// Driver class 
public class LineNum { 
    public static void main(String[] args) 
    { 
        Queue q=new Queue();
        int count=0;
        int size=0;
        int n=Integer.parseInt(args[0]);
        Scanner scan=new Scanner(System.in);
        while(scan.hasNextLine()){
            String line=scan.nextLine();
            q.enqueue(line);
            size++;
        }
        System.out.print(n+" from the first is ");
        String result = null;
        // dequeue the first n string from the queue and store the latest one in "result"
        for(int i=1;i<=n;i++){
            result = q.dequeue();
        }
        // print the result
        System.out.println(result);
    } 
}
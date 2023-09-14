
public class Stack implements IStack {
  public static final int MAX = 10;
  private int size;
  private char[] data;
  private int top = -1;
  
  public Stack() {
    this.data = new char[MAX];
    this.size = MAX - 1;
  }

  public int length() {
    return this.top + 1;
  }

  public void push(char elem){
    if(top < size) {
      top++;
      data[top] = elem;
    }
  }

  public void pop(){
    if(top >= 0) {
      top--;
    }
  }
  
  public char top(){
    return top != -1 ? this.data[top] : '\0';
  }
    
  
  public boolean isEmpty(){
    return top == -1;
  }
  
  public boolean isFull(){
    return top == size;
  }
  
  public void displayStack(){
    for(int x = top; x >= 0; x--){
      System.out.println("Index " + (x + 1) + ": " + data[x]);
    }
  }
  
}

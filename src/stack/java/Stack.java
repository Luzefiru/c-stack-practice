/**
 * This class represents a stack data structure that can store characters.
 */
public class Stack implements IStack {

    /**
     * The macro definition similar to the C header files.
     */
    public static final int MAX = 10;

    /**
     * The maximum capacity of the stack.
     */
    private int size;

    /**
     * The internal character array to store stack elements.
     */
    private char[] data;

    /**
     * The index of the top element in the stack, initialized to -1.
     */
    private int top;

    public Stack() {
        this.data = new char[MAX];
        this.size = MAX - 1;
        this.top = -1;
    }

    public int length() {
        return this.top + 1;
    }

    public void push(char elem) {
        if (top < size) {
            top++;
            data[top] = elem;
        }
    }

    public void pop() {
        if (top >= 0) {
            top--;
        }
    }

    public char top() {
        return top != -1 ? this.data[top] : '\0';
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == size;
    }

    public void displayStack() {
        System.out.println("");
        for (int x = top; x >= 0; x--) {
            System.out.println(String.format("|%3c%3c", data[x], '|'));
        }

        if (this.top == -1) {
            System.out.println("|     |");
        }
        System.out.println("-------");
    }

}
public class App {
    public static void main(String[] args) {
        System.out.println("\nTesting /src/java/stack/src/App.java, with Stack.java implementation");

        System.out.println("Stack s = new Stack()");
        Stack s = new Stack();
        System.out.println("");

        System.out.println("s.top()");
        System.out.println(String.format("> the element at the top of the stack = %c (integer value = %d)\n", s.top(), Integer.valueOf(s.top())));

        System.out.println("s.isEmpty()\n> " + s.isEmpty());
        System.out.println("");

        System.out.println("s.isFull()\n> " + s.isFull());
        System.out.println("");

        System.out.println("s.push('U')");
        s.push('U');
        System.out.println("> new length of stack = " + s.length());
        System.out.println("");

        System.out.println("s.top()");
        System.out.println(String.format("> the element at the top of the stack = %c (integer value = %d)\n", s.top(), Integer.valueOf(s.top())));

        System.out.println("s.push('A')");
        s.push('A');
        System.out.println("> new length of stack = " + s.length());
        System.out.println("");

        System.out.println("s.displayStack()");
        s.displayStack();
        System.out.println("");

        System.out.println("s.top()");
        System.out.println(String.format("> the element at the top of the stack = %c (integer value = %d)\n", s.top(), Integer.valueOf(s.top())));

        System.out.println("s.pop()");
        s.pop();
        System.out.println("");

        System.out.println("s.top()");
        System.out.println(String.format("> the element at the top of the stack = %c (integer value = %d)\n", s.top(), Integer.valueOf(s.top())));

        System.out.println("s.displayStack()");
        s.displayStack();
        System.out.println("");

        System.out.println("pushing: R I F E Z");
        s.push('R');
        s.push('I');
        s.push('F');
        s.push('E');
        s.push('Z');
        System.out.println("> new length of stack = " + s.length());
        System.out.println("");

        System.out.println("s.displayStack()");
        s.displayStack();
        System.out.println("");

        System.out.println("s.isFull()\n> " + s.isFull());
        System.out.println("");

        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("s.push('X')");
        s.push('X');
        System.out.println("");

        System.out.println("s.displayStack()");
        s.displayStack();
        System.out.println("");
        System.out.println("> new length of stack = " + s.length());
        System.out.println("");

        System.out.println("s.isFull()\n> " + s.isFull());
        System.out.println("");

        System.out.println("Popping all elements...");
        while (!s.isEmpty())
        {
            System.out.println("s.pop()");
            s.pop();
        }
        System.out.println("");

        System.out.println("s.displayStack()");
        s.displayStack();
        System.out.println("");

        System.out.println("s.isEmpty()\n> " + s.isEmpty());
        System.out.println("");

        System.out.println("> new length of stack = " + s.length());
        System.out.println("");
    }
}

public interface IStack {

    /**
     * Pushes a character element onto the top of the stack if there is space.
     *
     * @param elem The character element to push onto the stack.
     */
    public void push(char elem);

    /**
     * Removes the element at the top of the stack if the stack is not empty.
     */
    public void pop();

    /**
     * Returns the element at the top of the stack, otherwise '\0' if the stack
     * is empty.
     *
     * @return char
     */
    public char top();

    /**
     * Checks if the stack is empty.
     *
     * @return true if the stack is empty, false otherwise.
     */
    public boolean isEmpty();

    /**
     * Checks if the stack is full.
     *
     * @return true if the stack is full, false otherwise.
     */
    public boolean isFull();

    /**
     * Pretty prints the stack's elements, starting from the top-most element to
     * the bottom.
     *
     */
    public void displayStack();

    /**
     * Returns the length of the stack.
     *
     * @return int
     */
    public int length();
}

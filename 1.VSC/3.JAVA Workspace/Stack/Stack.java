package Stack;

public class Stack{
    int[] arr =new int[100];
    int topIndex = 0;
    
    public boolean empty(){
        return this.topIndex == 0;
    }

    public void push(int x){
        this.topIndex++;
        this.arr[topIndex] = x;
    }

    public int top(){
        return this.arr[this.topIndex];
    }

    public void pop(){
        this.topIndex--;
    }
}

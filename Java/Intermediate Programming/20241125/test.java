import java.util.*;

public class test {

    public static void main(String[] args) {
        Scanner io = new Scanner(System.in);
        SimpleLList list = new SimpleLList();
        for (int i = 1; i <= 5; ++i)
            list.add(io.nextLine());
        list.out();
        if (list.hasDuplicate())
            System.out.println("Yes");//
        else
            System.out.println("No");
        list.swap(2, 3);// Swap the second node and the third node.
        list.out();
        list.reverse();// Reverse the list.
        list.out();
        io.close();
    }

}
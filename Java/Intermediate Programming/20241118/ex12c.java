import java.util.Scanner;

public class ex12c
{
    public static void main (String [] args)
    {
        Scanner scan = new Scanner(System.in);
        ScoresL data = new ScoresL(scan);  // 创建对象，不再需要指定初始大小
        data.getData();                  // 填充成绩数据
        System.out.println();
        data.showData();                 // 显示数据

        System.out.print("Enter a value to search for: ");
        double val = scan.nextDouble();
        int loc = data.find(val);        // 查找指定值
        if (loc >= 0)
            System.out.println(val + " was found at loc " + loc);
        else
            System.out.println(val + " was not found ");

        // 演示浅拷贝和深拷贝
        ScoresL shareData = new ScoresL(data, 0); // shareData 和 data 共享 ArrayList
        ScoresL sepData = new ScoresL(data, 1);   // sepData 和 data 拥有独立的 ArrayList

        // 显示初始数据
        shareData.showData();
        sepData.showData();
                
        // 修改 data 的内容
        data.change();
        data.showData();
        shareData.showData();
        sepData.showData();

        // 使用 change2() 添加新的数据项，可能会改变共享状态
        data.change2();
        data.showData();
        shareData.showData();

        // 排序后显示数据，以查看共享状态的影响
        System.out.println("About to sort sharedData Scores object");
        shareData.sort();
        data.showData();
        shareData.showData();
        sepData.showData();
        
        //排序后进行二分查找
        double target=60;
        int loc2=data.findLE(target);
        if (loc2 >= 0)
            System.out.println("The first not less than "+target+" was found at loc " + loc2);
        else
            System.out.println("The first not less than "+target+" was not found.");
        
        loc2=data.findGE(target);
        if (loc2 >= 0)
            System.out.println("The first not greater than "+target+" was found at loc " + loc2);
        else
            System.out.println("The first not greater than "+target+" was not found.");
        
        
        

        
        
        
    }
}

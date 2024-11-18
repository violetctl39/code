import java.util.Scanner;

public class test
{
    public static void main (String [] args)
    {
        Scanner scan = new Scanner(System.in);
        ScoresL data = new ScoresL(scan);  // 创建对象，不再需要指定初始大小
        data.getData();                  // 填充成绩数据
        System.out.println();
        data.showData();                 // 显示数据

        data.sort2();
        
        data.showData();
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

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ScoresL
{
    private ArrayList<Double> theData;  // 用于存储成绩的 ArrayList
    private Scanner inScan;             // 输入 Scanner 对象

    // 构造方法，创建指定容量的 ArrayList 并设置 Scanner 对象
    public ScoresL(Scanner s)
    {
        theData = new ArrayList<>();
        inScan = s;
    }

    // 使用已有的 ScoresL 对象进行复制构造
    public ScoresL(ScoresL oldOne, int flag)
    {
        inScan = oldOne.inScan;
        if (flag == 0)
        {
            // 共享相同的 ArrayList（浅拷贝）
            theData = oldOne.theData;
        }
        else
        {
            // 深拷贝：创建一个新 ArrayList 并复制旧对象的数据
            theData = new ArrayList<>(oldOne.theData);
        }
    }

    // 从用户输入中读取成绩数据并存入 ArrayList 中
    public void getData()
    {
        System.out.print("===   GetData  ===: \n");
        System.out.print("Enter number of scores: ");
        int numScores = inScan.nextInt();
        for (int i = 0; i < numScores; i++)
        {
            System.out.print("Enter score " + i + ": ");
            theData.add(inScan.nextDouble());
        }
    }

    // 显示 ArrayList 中的成绩数据
    public void showData()
    {
        System.out.print("===   ShowData  ===: \n");
        System.out.println("Index : Data");
        System.out.println("-----   ----");
        for (int i = 0; i < theData.size(); i++)
            System.out.println("  " + i + "   : " + theData.get(i));
        System.out.println();
    }

    // 查找指定成绩在 ArrayList 中的索引
    public int find(double x)
    {
        System.out.print("===   FindData  ===: \n");
        for (int i = 0; i < theData.size(); i++)
        {
            if (Math.abs(theData.get(i) - x) < 0.001) // 检查是否接近
                return i;
        }
        return -1;
    }
    public int binarySearch(double target) {
        int l=0,r=theData.size()-1;if(l>r)return -1;
        while(l<r){
            int mid=(l+r)/2+1;
            if(theData.get(mid)>target+0.001)r=mid-1;
            else l=mid;
        }
        return Math.abs(theData.get(l)-target)<0.001?l:-1;
    }
    // 顺序查找第一个不小于目标的数
    public int findLE(double target) {
        for (int i = 0; i < theData.size(); i++) {
            if (theData.get(i) >= target) 
            	return i;
        }
        return -1;
    }
   // 二分查找第一个不小于目标的数
    public int binarySearchLE(double target) {
        int l=0,r=theData.size()-1;if(l>r)return -1;
        while(l<r){
            int mid=(l+r)/2;
            if(theData.get(mid)<target)l=mid+1;
            else r=mid;
        }
        return theData.get(l)>=target?l:-1;
    }
   
    // 顺序查找第一个不大于目标的数
    public int findGE(double target) {
        for (int i = 0; i < theData.size(); i++) {
            if (theData.get(i) <= target) 
            	return i;
        }
        return -1;
    }
    // 二分查找第一个不大于目标的数
    public int binarySearchGE(double target) {
        int l=0,r=theData.size()-1;if(l>r)return -1;
        while(l<r){
            int mid=(l+r)/2+1;
            if(theData.get(mid)>target)r=mid-1;
            else l=mid;
        }
        return theData.get(l)<=target?l:-1;
    }
    

  
    // 允许用户选择一个有效索引并修改对应的成绩
    public void change()
    {
        System.out.print("===   ChangeData  ===: \n");
        int index;
        do
        {
            System.out.print("Enter index to change: ");
            index = inScan.nextInt();
        } while (index < 0 || index >= theData.size());

        System.out.print("Enter new value: ");
        theData.set(index, inScan.nextDouble());
    }

    // 允许用户选择一个索引，如果超出 ArrayList 当前长度，则新增成绩
    public void change2()
    {
        System.out.print("===   ChangeData2  ===: \n");
        int index;
        System.out.print("Enter index to change or add: ");
        index = inScan.nextInt();

        System.out.print("Enter new value: ");
        double value = inScan.nextDouble();

        if (index >= theData.size())
        {
            // 添加到指定索引并填充中间缺少的元素
            while (theData.size() < index)
            {
                theData.add(0.0); // 使用默认值填充
            }
            theData.add(value);
        }
        else
        {
            theData.set(index, value);
        }
    }

    // 对 ArrayList 进行排序
    public void sort()
    {
        System.out.print("===   SortData  ===: \n");
        Collections.sort(theData);
    }
    private void mergeSort(int l,int r){
        if(l>=r)return;
        int mid=(l+r)>>1,lp=l,rp=mid+1;
        mergeSort(l,mid);mergeSort(mid+1,r);
        ArrayList<Double> tmp=new ArrayList<Double>();
        while(lp<=mid||rp<=r){
            if(rp==r+1||(lp<=mid&&theData.get(lp)<theData.get(rp))){
                tmp.add(theData.get(lp));++lp;
            }
            else{
                tmp.add(theData.get(rp));++rp;
            }
        }
        for(int i=0;i<tmp.size();++i)theData.set(l+i,tmp.get(i));
    }
    public void sort2()
    {
        System.out.print("===   SortData  ===: \n");
        mergeSort(0,theData.size()-1);
    }
    
    
}

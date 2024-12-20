public class AccountsTest {
    public static void main(String[] args) {
    System.out.println("=====测试:⽗类引⽤指向⼦类对象====");
    Account account1 = new SavingsAccount("S001", 1000, 0.05);
    // 存款并显示余额（SavingsAccount）
    account1.deposit(200);
    account1.displayAccountInfo();
    // account1.calculateInterest(); // error
    // 检查储蓄账户（SavingsAccount）的利息
    if (account1 instanceof SavingsAccount) {
    ((SavingsAccount) account1).calculateInterest();
    }
    System.out.println("=====测试:⼦类引⽤指向⼦类对象====");
    SavingsAccount savingsAccount2 = new SavingsAccount("S002", 1000, 0.05);
    savingsAccount2.deposit(200); // 存款
    savingsAccount2.displayAccountInfo(); // 显示账户信息
    // 计算利息
    savingsAccount2.calculateInterest();
    }
    }
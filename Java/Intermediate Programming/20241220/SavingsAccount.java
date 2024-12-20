//⼦类：SavingsAccount
class SavingsAccount extends Account {
    private double interestRate; // 利率
    public SavingsAccount(String accountId, double balance, double interestRate) {
        super(accountId, balance);
        this.interestRate = interestRate;
    }
    public void calculateInterest() {
        super.balance+=super.balance*interestRate;
    }
    @Override
    public void displayAccountInfo() {
        System.out.println("账户ID: " + super.accountId + ", 当前余额: " + super.balance+", 当前利率: "+interestRate);
    }
}
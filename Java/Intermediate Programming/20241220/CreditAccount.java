class CreditAccount extends Account {
    private double overdraftLimit; //透⽀限额
    public CreditAccount(String accountId, double balance, double overdraftLimit) {
    super(accountId, balance);
    this.overdraftLimit = overdraftLimit;
    }
    // TO DO，重写取款⽅法，注意补全参数，考虑透⽀限额
    @Override
    public void withdraw(double amount) {
        if (super.balance-amount>=overdraftLimit) {
            super.balance -= amount;
            System.out.println("账户ID: " + super.accountId + " 成功取款: " + amount);
        } else {
            System.out.println("取款失败，超出透支限额!");
        }
    }
    // 检查透⽀状态的⽅法
    public void checkOverdraft() {
        if(super.balance<0)System.out.println("账户ID: " + super.accountId + ", 已透支: " + super.balance*(-1));
        else System.out.println("账户ID: " + super.accountId + ", 未透支");
    }
    @Override
    public void displayAccountInfo() {
        System.out.println("账户ID: " + super.accountId + ", 当前余额: " + super.balance+", 当前透支限额: "+overdraftLimit);
    }
    }
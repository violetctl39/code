class Account {
    protected String accountId;
    protected double balance;

    public Account(String accountId, double balance) {
        // 账户 ID 不能为空
        if (accountId == null || accountId.trim().isEmpty()) {
            throw new IllegalArgumentException("账户ID不能为空");
        }
        // 余额必须⼤于等于 0
        if (balance < 0) {
            throw new IllegalArgumentException("余额不能为负数");
        }
        this.accountId = accountId;
        this.balance = balance;
    }

    public void displayAccountInfo() {
        System.out.println("账户ID: " + accountId + ", 当前余额: " + balance);
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("存款⾦额必须⼤于 0.");
        } else {
            balance += amount;
            System.out.println("账户ID: " + accountId + " 成功存款: " + amount);
        }
    }

    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("账户ID: " + accountId + " 成功取款: " + amount);
        } else {
            System.out.println("取款失败，超出余额!");
        }
    }
}
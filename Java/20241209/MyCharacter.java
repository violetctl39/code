public class MyCharacter {
    private char ch;

    public MyCharacter(char ch) {
        this.ch = ch;
    }

    public char getChar() {
        return ch;
    }

    public void setChar(char ch) {
        this.ch = ch;
    }

    // 转换为原始类型 char
    public char toPrimitive() {
        return ch;
    }

    // 从原始类型 char 创建 MyCharacter 对象
    public static MyCharacter fromPrimitive(char c) {
        return new MyCharacter(c);
    }

    // 重写 toString ?法，便于打印
    @Override
    public String toString() {
        return String.valueOf(ch);
    }

    // 判断是否是字?
    public boolean isLetter() {
        // TO DO
        if(ch>='A'&&ch<='Z')return true;
        if(ch>='a'&&ch<='z')return true;
        return false;
    }

    // 判断是否是数字
    public boolean isDigit() {
        // TO DO
        if(ch>='0'&&ch<='9')return true;
        return false;
    }

    // 将字符转换为?写
    public char toUpperCase() {
        if (ch >= 'a' && ch <= 'z') {
            return (char) (ch - ('a' - 'A'));
        }
        return ch;
    }

    // 将字符转换为?写
    public char toLowerCase() {
        // TO DO
        if(ch>='A'&&ch<='Z')
            return (char)(ch-'A'+'a');
        return ch;
    }
}
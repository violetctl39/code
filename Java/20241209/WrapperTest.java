public class WrapperTest {
    public static void main(String[] args) {
    // 创建?个 MyCharacter 对象
    MyCharacter myChar = new MyCharacter('a');
    // 测试基本?法
    System.out.println("封装的字符是: " + myChar.getChar());
    System.out.println("是否是字符: " + myChar.isLetter());
    System.out.println("是否是数字: " + myChar.isDigit());
    System.out.println("转换为大写: " + myChar.toUpperCase());
    System.out.println("转换为小写: " + myChar.toLowerCase());
    // 测试 MyCharacter 转原始类型 char
    char primitiveChar = myChar.toPrimitive();
    System.out.println("MyCharacter 转换为原始类型 char: " + primitiveChar);
    // 测试原始类型 char 转 MyCharacter
    char rawChar = 'Z';
    MyCharacter newChar = MyCharacter.fromPrimitive(rawChar);
    System.out.println("原始类型 char 转换为 MyCharacter: " + newChar);
    char anotherPrimitive = newChar.toUpperCase(); // 大写保持原样
    System.out.println("转换为大写后得到的原始 char: " + anotherPrimitive);
    }
    }
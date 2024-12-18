// 定义⼀个Animal类
class Animal {
    // 定义⼀些通⽤属性
    private String name;

    // 构造器
    public Animal(String name) {
        this.name = name;
    }

    // 通⽤⽅法，⼦类必须实现
    public void makeSound() {
        System.out.println("");
    }

    // 通⽤⽅法，⼦类必须实现
    public void eat() {
        System.out.println(name + " is eating.");
    }
    public String getName(){
        return new String(name);
    }
}

// 定义Cat类继承⾃Animal类
class Cat extends Animal {
    // 使⽤构造器初始化⽗类属性
    public Cat(String name) {
        super(name);
    }

    // 实现从⽗类继承来⽅法
    @Override
    public void makeSound() {
        System.out.println("miao~!");
    }

    // eat (to do)
    @Override
    public void eat(){
        System.out.println(getName() + " is eating.");
    }
    // 猫特有的⽅法
    public void purr() {
        System.out.println("Purring...");
    }
    
}
class Dog extends Animal{
    public Dog(String name){
        super(name);
    }
    @Override
    public void makeSound(){
        System.out.println("Woof~!");
    }
    @Override
    public void eat(){
        System.out.println(getName() + " is eating.");
    }
}
public class TestCat {
    public static void main(String[] args) {
        Cat myCat = new Cat("Whiskers");
        myCat.makeSound(); // 输出: miao~!
        myCat.eat();
        myCat.purr();
        Dog myDog = new Dog("Brian");
        myDog.makeSound();
        myDog.eat();
    }
}
// Rectangle.java
class Rectangle extends Shape {
    private double length,width;
    public Rectangle(double length,double width){
        this.length=length;this.width=width;
    }
    @Override
    public double getArea(){
        return length*width;
    }
}


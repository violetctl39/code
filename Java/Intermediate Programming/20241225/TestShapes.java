// TestShapes.java
import java.util.ArrayList;
import java.util.List;
class TestShapes {
    public static void main(String[] args) {
        List<Shape> shapes = new ArrayList<>();
        shapes.add(new Circle(5));
        shapes.add(new Rectangle(4, 6));
        for (Shape shape : shapes) {
            System.out.println("The area of the shape is: " + shape.getArea());
        }
    }
}
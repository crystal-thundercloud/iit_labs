import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Ex01();
        Ex02();
    }

    static void Ex01() {
        System.out.println("Ex 1\n");

        Square square = new Square("black", 12.3f);
        Triangle triangle = new Triangle("yellow", 45.6f);
        Circle circle = new Circle("pink", 78.9f);

        System.out.println("Square\nColor: " + square.color + "\nArea: " + square.s + "\n");
        System.out.println("Triangle\nColor: " + triangle.color + "\nArea: " + triangle.s + "\n");
        System.out.println("Circle\nColor: " + circle.color + "\nArea: " + circle.s + "\n");

        Figure someFigure;
        someFigure = square;
        System.out.println("Square as a Figure\nColor: " + someFigure.color + "\nArea: " + someFigure.s + "\n");
        someFigure = triangle;
        System.out.println("Triangle as a Figure\nColor: " + someFigure.color + "\nArea: " + someFigure.s + "\n");
        someFigure = circle;
        System.out.println("Circle as a Figure\nColor: " + someFigure.color + "\nArea: " + someFigure.s + "\n");
    }

    static void Ex02() {
        System.out.println("Ex 2 \n");

        Square square = new Square("white", 123.45f);
        Triangle triangle = new Triangle("blue", 678.9f);

        System.out.println("Square\nColor: " + square.color + "\nArea: " + square.s + "\n");
        System.out.println("Triangle\nColor: " + triangle.color + "\nArea: " + triangle.s + "\n");

        Scanner input = new Scanner(System.in);
        System.out.print("Enter operation (sum, sub, mult, div): ");
        String operation = input.nextLine();

        Operator op = new Operator();
        Calculator calc = new Calculator();

        op.Operate(square, triangle, operation, calc);
    }
}

abstract class Figure {
    public String color;
    public float s;

    Figure() {
        color = "None";
        s = 0;
    }

    Figure(String Color, float S) {
        color = Color;
        s = S;
    }
}

class Square extends Figure {

    Square() {
        super();
    }

    Square(String Color, float S) {
        super(Color, S);
    }
}

class Triangle extends Figure {

    Triangle() {
        super();
    }

    Triangle(String Color, float S) {
        super(Color, S);
    }
}

class Circle extends Figure {

    Circle() {
        super();
    }

    Circle(String Color, float S) {
        super(Color, S);
    }
}

class Operator {
    public void Operate(Figure f1, Figure f2, String op, Calculator calculator) {
        System.out.print("Result of " + op + ": ");
        calculator.calc(op, f1.s, f2.s);
    }
}

class Calculator extends Operator implements Summ, Subtraction, Division, Multiplication {
    public float result;

    public void calc(String op, float s1, float s2) {
        switch (op) {
            case ("sum") -> result = Sum(s1, s2);
            case ("sub") -> result = Sub(s1, s2);
            case ("mult") -> result = Mult(s1, s2);
            case ("div") -> result = Div(s1, s2);
        }

        System.out.println(result);
    }

    @Override
    public float Div(float s1, float s2) {
        return s1 / s2;
    }

    @Override
    public float Mult(float s1, float s2) {
        return s1 * s2;
    }

    @Override
    public float Sub(float s1, float s2) {
        return s1 - s2;
    }

    @Override
    public float Sum(float s1, float s2) {
        return s1 + s2;
    }
}

interface Summ {
    float Sum(float s1, float s2);
}

interface Subtraction {
    float Sub(float s1, float s2);
}

interface Multiplication {
    float Mult(float s1, float s2);
}

interface Division {
    float Div(float s1, float s2);
}

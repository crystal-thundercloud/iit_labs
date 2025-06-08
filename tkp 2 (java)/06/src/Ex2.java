import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) {
        Star star = new Star("красный", 64.625f, 7, 15.5f);

        Scanner s = new Scanner(System.in, "cp866");
        System.out.print("Введите внутрений радиус кольца: ");
        float rad1 = s.nextFloat();
        System.out.print("Введите внешний радиус кольца: ");
        float rad2 = s.nextFloat();

        float area = (float)((Math.PI * rad2 * rad2) - (Math.PI * rad1 * rad1));
        
        Ring ring = new Ring("золотой", area, rad1, rad2);

        System.out.println("\nПлощадь звезды: " + star.area);
        System.out.println("Площадь кольца: " + ring.area);

        Calculator o = new Calculator();
        o.calculate(star.area, ring.area);
    }
}

class Operator {
    public String GetOperation() {
        System.out.print("Введите название операции (sum, sub, mult, div): ");
        Scanner s = new Scanner(System.in, "cp866");
        String operation = s.nextLine();

        switch (operation) {
            case "sum":
                System.out.print("Результат суммирования: ");
                return operation;
            case "sub":
                System.out.print("Результат вычитания: ");
                return operation;
            case "mult":
                System.out.print("Результат умножения: ");
                return operation;
            case "div":
                System.out.print("Результат деления: ");
                return operation;
            default:
                System.out.println("Неизвестная команда, повторите ввод");
                return GetOperation();
        }
    }
}

class Calculator extends Operator implements Summ, Substraction, Division,
        Multiplication {

    public void calculate(float area1, float area2) {
        String operation = super.GetOperation();

        switch (operation) {
            case "sum":
                System.out.print(Sum(area1, area2));
                break;
            case "sub":
                System.out.print(Sub(area1, area2));
                break;
            case "mult":
                System.out.print(Mult(area1, area2));
                break;
            case "div":
                System.out.print(Div(area1, area2));
                break;
            default:
                System.out.println("Неизвестная команда");
        }
    }

    @Override
    public float Sum(float area1, float area2) {
        return area1 + area2;
    }

    @Override
    public float Sub(float area1, float area2) {
        return area1 - area2;
    }

    @Override
    public float Mult(float area1, float area2) {
        return area1 * area2;
    }

    @Override
    public float Div(float area1, float area2) {
        return area1 / area2;
    }
}

interface Summ {
    float Sum(float area1, float area2);
}

interface Substraction {
    float Sub(float area1, float area2);
}

interface Multiplication {
    float Mult(float area1, float area2);
}

interface Division {
    float Div(float area1, float area2);
}

abstract class Figure {

    public String color; // цвет
    public float area; // площадь

    Figure() {
        color = "Неопределён";
        area = 0;
    }

    Figure(String Color, float Area) {
        color = Color;
        area = Area;
    }
}

class Trapezoid extends Figure {

    public float upperBase; // верхнее основание трапеции
    public float lowerBase; // нижнее основание трапеции
    public float height; // высота трапеции
    
    Trapezoid() {
        super();
        upperBase = lowerBase = height = 0;
    }

    Trapezoid(String Color, float Area, float UpperBase, float LowerBase, float Height) {
        super(Color, Area);
        upperBase = UpperBase;
        lowerBase = LowerBase;
        height = Height;
    }
}

class Star extends Figure {

    public int raysNumber; // количество лучей звезды
    public float radius; // радиус звезды

    Star() {
        super();
        radius = raysNumber = 0;
    }

    Star(String Color, float Area, int RaysNumber, float Radius) {
        super(Color, Area);
        raysNumber = RaysNumber;
        radius = Radius;
    }
}

class Ring extends Figure {

    public float innerRadius; // внутренний радиус кольца
    public float outterRadius; // внешний радиус кольца

    Ring() {
        super();
        innerRadius = outterRadius = 0;
    }

    Ring(String Color, float Area, float InnerRadius, float OutterRadius) {
        super(Color, Area);
        innerRadius = InnerRadius;
        outterRadius = OutterRadius;
    }
}


import java.util.Scanner;

public class Ex1 {
    public static void main(String[] args) {

        // доступ к объектам через объектные переменные подклассов
        Trapezoid trapezoid = new Trapezoid("фиолетовый", 18, 5, 13, 2);
        Star star = new Star("красный", 64.625f, 7, 15.5f);
        
        Scanner s = new Scanner(System.in, "cp866");
        System.out.print("\nВведите цвет кольца: ");
        String color = s.nextLine();
        System.out.print("Введите внутрений радиус кольца: ");
        float rad1 = s.nextFloat();
        System.out.print("Введите внешний радиус кольца: ");
        float rad2 = s.nextFloat();

        float area = (float)((Math.PI * rad2 * rad2) - (Math.PI * rad1 * rad1));
        
        Ring ring = new Ring(color, area, rad1, rad2);
        
        System.out.println("\nТрапеция\nЦвет: " + trapezoid.color + "\nПлощадь: " + trapezoid.area
                + "\nВерхнее основание: " + trapezoid.upperBase + "\nНижнее основание: " + trapezoid.lowerBase
                + "\nВысота: " + trapezoid.height);
        
        System.out.println("\nЗвезда\nЦвет: " + star.color + "\nПлощадь: " + star.area + "\nЧисло лучей: "
                + star.raysNumber + "\nРадиус: " + star.radius);

        System.out.println("\nКольцо\nЦвет: " + ring.color + "\nПлощадь: " + ring.area + "\nВнутренний радиус: "
                + ring.innerRadius + "\nВнешний радиус: " + ring.outterRadius);

        // доступ к объектам через объектную переменную абстрактного суперкласса
        Figure figure;

        figure = trapezoid;
        System.out.println("\nФигура-трапеция\nЦвет: " + figure.color + "\nПлощадь: " + figure.area);
        
        figure = star;
        System.out.println("\nФигура=звезда\nЦвет: " + figure.color + "\nПлощадь: " + figure.area);

        figure = ring;
        System.out.println("\nФигура-кольцо\nЦвет: " + figure.color + "\nПлощадь: " + figure.area);

    }
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

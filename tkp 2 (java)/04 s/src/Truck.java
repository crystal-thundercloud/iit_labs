import java.util.Scanner;

public class Truck extends Auto {
    private String model;
    private int power;
    private Boolean trailer; //c прицепом или без

    public Truck() {
        super();
        model = "";
        power = 0;
        trailer = false;
    }

    public Truck(String firma, String num, int speed, String name, int n, Boolean f) {
        super(firma, num, speed);
        model = name;
        power = n;
        trailer = f;
    }

    public void setModel(String name) {
        model = name;
    }

    public String getModel() {
        return model;
    }

    public void setPower(int n) {
        power = n;
    }

    public int getPower() {
        return power;
    }

    public void setTrailer(Boolean b) {
        trailer = b;
    }

    public Boolean isTrailer() {
        return trailer;
    }

    public void setAllInfo() {
        Scanner in = new Scanner(System.in, "cp866");
        System.out.print("Введите фирму-производитель грузового авто: ");
        String nazv = in.next();
        setFirm(nazv);
        System.out.print("Enter trucks plate number: ");
        String num = in.next();
        setPlateNum(num);
        System.out.print("Введите максимальную скорость грузового авто: ");
        int s = in.nextInt();
        setMaxSpeed(s);
        System.out.print("Введите модель грузового авто: ");
        model = in.next();
        System.out.print("Введите мощность грузового авто: ");
        power = in.nextInt();
        System.out.print("Введите признак прицепа грузового авто (true/false): ");
        trailer = in.nextBoolean();
        System.out.println();
    }

    public String toString() {
        return "\n\tГрузовик" + "\n\t" + "Фирма: " + getFirm() + "\n\t" + "Plate number: " + getPlateNum() + "\n\t" + "Максимальная скорость: " + getMaxSpeed()
                + "\n\t"
                + "Модель: " + model + "\n\t" + "Мощность: " + power + "\n\t" + "Признак прицепа: " + trailer + "\n";
    }
}
package Ex;

import java.util.Scanner;

public class App {
     public static void main(String[] args) {

        Tech myTech1=new Tech();
        Scanner in = new Scanner(System.in, "cp866");

        System.out.print("Введите фирму: ");
        String nazv=in.next();
        myTech1.setFirm(nazv);

        System.out.print("Введите цвет: ");
        String color=in.next();
        myTech1.setColor(color);

        System.out.print("Введите операционную систему: ");
        String os=in.next();
        myTech1.setOS(os);

        System.out.print("Введите объём физической памяти (ГБ): ");
        float mem=in.nextFloat();
        myTech1.setMemory(mem);

        System.out.println("Какая-то техника: " + myTech1.getFirm() + " " + myTech1.getColor() + " " + myTech1.getOS() + " " + myTech1.getMemory());
        System.out.println();

        Notebook myNotebook1 = new Notebook("MSI", "Black and red", "Windows", 2.5f, true, true);
        Notebook myNotebook2 = new Notebook();
        
        System.out.print("Введите фирму ноутбука: ");
        nazv=in.next();
        myNotebook2.setFirm(nazv);
        
        System.out.print("Введите цвет ноутбука: ");
        color=in.next();
        myNotebook2.setColor(color);

        System.out.print("Введите операционную систему ноутбука: ");
        os=in.next();
        myNotebook2.setOS(os);

        System.out.print("Введите объём физической памяти ноутбука (ТБ): ");
        mem=in.nextFloat();
        myNotebook2.setMemory(mem);

        System.out.print("Введите наличие дискретной графики у ноутбука (true/false): ");
        Boolean f = in.nextBoolean();
        myNotebook2.setDiscreteGraphic(f);

        System.out.print("Введите наличие камеры у ноутбука (true/false): ");
        f = in.nextBoolean();
        myNotebook2.setCameraInfo(f);

        System.out.println();

        System.out.println("Первый ноутбук: " + myNotebook1.toString());
        System.out.println("Второй ноутбук: " + myNotebook2.toString());
        
        Smartphone mySmartphone = new Smartphone();
        
        System.out.print("Введите фирму смартфона: ");
        nazv=in.next();
        mySmartphone.setFirm(nazv);
        
        System.out.print("Введите цвет смартфона: ");
        color=in.next();
        mySmartphone.setColor(color);

        System.out.print("Введите операционную систему смартфона: ");
        os=in.next();
        mySmartphone.setOS(os);

        System.out.print("Введите объём физической памяти смартфона (ГБ): ");
        mem=in.nextFloat();
        mySmartphone.setMemory(mem);

        System.out.print("Введите версию операционной системы смартфона: ");
        mem=in.nextFloat();
        mySmartphone.setOSversion(mem);

        System.out.print("Введите наименование модели смартфона: ");
        os=in.next();
        mySmartphone.setModelInfo(os);

        System.out.println(mySmartphone.toString());

        RepairService rs = new RepairService();
        rs.addTech(myNotebook1);
        rs.addTech(myNotebook2);
        rs.addTech(mySmartphone);

        System.out.println("В сервисе находятся ноутбуки в количестве " + rs.countNotebooks()
                + " и смартфоны в количестве " + rs.countSmartphones());
        System.out.println("Список всей техники в сервисе: ");
        rs.printService();
    }
}

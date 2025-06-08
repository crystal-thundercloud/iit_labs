package pkg03;

import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author cdctt
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // ex01();
        // ex02();
        // ex03();
        // ex04();
        // ex05();
        ex06();
    }
    
    static void ex01() {
        System.out.println("\nНапишите программу с методом для отображения"
		+ "\nтекстовой строки в обратном порядке");
        
        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Введите любую строку: ");
        String str = s.nextLine();

        String str2 = new StringBuffer(str).reverse().toString();
        System.out.println("\nПеревёрнутая строка:\n" + str2);
    }
    
    static void ex02() {
        System.out.println("\nНапишите программу с методом для подсчета"
                + "\nколичества вхождений символа в текстовую строку");

        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Введите любую строку: ");
        String str = s.nextLine();

        System.out.println("Введите любой символ: ");
        String sym = s.nextLine();

        int counter = 0;
        while (str.indexOf(sym) != -1) { // чувствительно к регистру
            counter++;
            str = str.substring(str.indexOf(sym) + 1);
        }

        System.out.println("\nКоличество вхождений \"" + sym + "\" в строку: " + counter);
    }
 
    static void ex03() {
        System.out.println("\nНапишите программу с методом, которым текст"
                + "\nотображается в консоли, причем каждое слово из текста"
                + "\nотображается в отдельной строке");

        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Введите любую строку: ");
        String str[] = s.nextLine().split(" ");

        System.out.println("Строка по словам: ");
        for (int i = 0; i < str.length; i++) {
            System.out.println(str[i]);
        }
    }
    
    static void ex04() {
        System.out.println("\nНапишите программу, в которой определяется время"
		+ "\nи дата через 1 000 000 секунд после текущей даты и времени");

        System.out.println("Текущая дата: " + (new Date(System.currentTimeMillis())) + "\nДата + млн с: " + (new Date(System.currentTimeMillis() + (1000000 * 1000))));
    }
    
    static void ex05() {
        System.out.println("\nНапишите программу, в которой на заданном"
                + "\nинтервале времени случайно выбирается дата и время,"
                + "\nи для этой даты отображается день недели");

        Random rand = new Random();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("E dd MMMM YYYY HH:mm:ss");

        LocalDateTime dt1 = LocalDateTime.of(LocalDate.of(1900, 1, 1), LocalTime.of(0, 0, 0));
        LocalDateTime dt2 = LocalDateTime.of(LocalDate.of(2100, 12, 31), LocalTime.of(23, 59, 59));

        LocalDateTime result = LocalDateTime.ofEpochSecond(
                rand.nextLong(dt1.toEpochSecond(ZoneOffset.UTC), dt2.toEpochSecond(ZoneOffset.UTC) + 1), 0,
                ZoneOffset.UTC);
        System.out.println("Случайная дата и её день недели: " + result.format(dtf));
    }
    
    static void ex06() {
        System.out.println("\nНапишите программу, в которой дата выводится"
		+ "\nв формате, в котором сначала следует год, затем месяц,"
		+ "\nпосле этого - день месяца");
        
        System.out.println("Текущая дата в формате: " + LocalDateTime.now().format(DateTimeFormatter.ofPattern("YYYY MM dd")));
    }
}
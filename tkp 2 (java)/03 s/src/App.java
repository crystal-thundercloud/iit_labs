import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

public class App {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        ex01();
        ex02();
        ex03();
        ex04();
        ex05();
        ex06();
    }
    
    static void ex01() {
        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Type in any string: ");
        String str = s.nextLine();

        System.out.println("\nReversed string:\n" + new StringBuffer(str).reverse().toString());
    }
    
    static void ex02() {
        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Type in any string: ");
        String str = s.nextLine();

        System.out.println("Type in any symbol: ");
        String sym = s.nextLine();

        int counter = 0;
        while (str.indexOf(sym) != -1) {
            counter++;
            str = str.substring(str.indexOf(sym) + 1);
        }

        System.out.println("Symbol \"" + sym + "\" occurs " + counter + " times");
    }
 
    static void ex03() {
        Scanner s = new Scanner(System.in, "Cp866");

        System.out.println("Type in any string: ");
        String str[] = s.nextLine().split(" ");

        System.out.println("String split by words: ");
        for (int i = 0; i < str.length; i++) {
            System.out.println(str[i]);
        }
    }
    
    static void ex04() {
        System.out.println("Current date: " + (new Date(System.currentTimeMillis())) + "\nCurrent date + million s: " + (new Date(System.currentTimeMillis() + (1000000 * 1000))));
    }
    
    static void ex05() {
        Random rand = new Random();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("E dd MMMM YYYY HH:mm:ss");

        LocalDateTime dt1 = LocalDateTime.of(LocalDate.of(1900, 1, 1), LocalTime.of(0, 0, 0));
        LocalDateTime dt2 = LocalDateTime.of(LocalDate.of(2100, 12, 31), LocalTime.of(23, 59, 59));

        LocalDateTime result = LocalDateTime.ofEpochSecond(
                rand.nextLong(dt1.toEpochSecond(ZoneOffset.UTC), dt2.toEpochSecond(ZoneOffset.UTC) + 1), 0,
                ZoneOffset.UTC);
        System.out.println("Random date and its weekday: " + result.format(dtf));
    }
    
    static void ex06() {
        System.out.println("Formatted current date: " + LocalDateTime.now().format(DateTimeFormatter.ofPattern("YYYY MM dd")));
    }
}
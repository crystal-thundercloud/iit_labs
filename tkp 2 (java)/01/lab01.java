import java.util.*;
public class lab01 {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in, "Cp866");
        
        String name;
        int age;

        System.out.println("Как Вас зовут?");

        name = inp.nextLine();
        
        System.out.println("Добрый день, " + name + "!" + "\nСколько Вам лет?");

        age = inp.nextInt();
        
        System.out.println(name+", Вам "+age+" лет!");
    }
}
    

import java.util.*;

public class HelloWorldConsol {
    public static void main(String[] args) {
    // Объект класса Scanner создается на основе объекта System.in:
    Scanner inp=new Scanner(System.in, "Cp866");
    String name; // Текстовое поле (имя):
    int age; // Числовое поле (возраст):
    System.out.println("Как Вас зовут?"); // Задаем вопрос:
    name=inp.nextLine();// Считываем текст (имя):
    System.out.println("Добрый день, "+name+"!"); // Приветствие:
    System.out.println("Сколько Вам лет?"); // Задаем вопрос:
    age=inp.nextInt();// Считываем число (возраст):
    System.out.println(name+", Вам "+age+" лет!"); // Вывод сообщения:
    }
}
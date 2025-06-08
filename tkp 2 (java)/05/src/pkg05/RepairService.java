package pkg05;

import java.util.ArrayList;

/**
 * Класс ремонтного сервиса, содержащий список экземпляров класса {@link Tech} и расширяющих его классов {@link Notebook} и {@link Smartphone}
 * @author 211-727 Шемарева Анастасия
 */

public class RepairService {
    /** Список техники в сервисе - ноутбуки и смартфоны */
    private ArrayList<Tech> masTech = new ArrayList<>();

    /**
     * Конструктор - создание нового экземпляра ремонтного сервиса
     * @see RepairService#RepairService(ArrayList)
     */
    public RepairService() {
    }
 
    /**
     * Конструктор - создание нового экземпляра ремонтного сервиса
     * @param n - список, содержащий список техники
     * @see RepairService#RepairService(ArrayList)
     */   
    public RepairService(ArrayList<Tech> n) {
        masTech = n;
    }

    /**
     * Процедура добавления экземпляра техники в список
     * @param m - экземпляр класса {@link Tech} или расширяющих его классов  {@link Notebook} и {@link Smartphone}
     */
    public void addTech(Tech m) {
        masTech.add(m);
    }

    /**
     * Процедура поиска экземпляра техники в списке
     * @param m - экземпляр класса {@link Tech} или расширяющих его классов  {@link Notebook} и {@link Smartphone}, который необходимо найти
     * @return возвращает true, если экземпляр найден в списке
     */    
    public Boolean findTech(Tech m) {
        return masTech.contains(m);
    }

    /**
     * Процедура удаления экземпляра техники из списка
     * @param m - экземпляр класса {@link Tech} или расширяющих его классов  {@link Notebook} и {@link Smartphone}, который необходимо удалить
     * @return возвращает true, если экземпляр найден и удалён из списка
     */ 
    public Boolean removeTech(Tech m) {
        return masTech.remove(m);
    }

    /**
     * Процедура подсчёта количества экземпляров класса  {@link Notebook} в списке
     * @return возвращает количество найденных экземпляров класса Notebook
     */ 
    public int countNotebooks() {
        int counter = 0;
        for (Tech t : masTech) if (t instanceof Notebook) counter++;
        return counter;
    }

    /**
     * Процедура подсчёта количества экземпляров класса {@link Smartphone} в списке
     * @return возвращает количество найденных экземпляров класса Smartphone
     * @see Smartphone
     */ 
    public int countSmartphones() {
        int counter = 0;
        for (Tech t : masTech) if (t instanceof Smartphone) counter++;
        return counter;
    }

    /** 
     * Процедура получения всей техники из списка сервиса в понятном пользователю виде
     */
    public void printService() {
        for (Tech t:masTech) System.out.println(t.toString());
    }
}

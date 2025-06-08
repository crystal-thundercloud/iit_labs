package pkg05;

/**
 * Класс смартфона, расширяющий класс компьютерной техники {@link Tech}
 * @author 211-727 Шемарева Анастасия
 */

public class Smartphone extends Tech {
    /** Версия операционной системы */
    private float OSversion;
    /** Модель */
    private String model;

    /** 
     * Процедура установки версии операционной системы смартфона
     * @param OSVersion - версия операционной системы
     */
    public void setOSversion(float OSVersion) {
        OSversion = OSVersion;
    }

    /** 
     * Процедура установки модели смартфона
     * @param Model - строка с наименованием модели смартфона
     */
    public void setModelInfo(String Model) {
        model = Model;
    }

    /** 
     * Процедура получения версии опрационной системы смартфона {@link Smartphone#OSversion}
     * @return возвращает число - версию операционной системы смартфона
     */
    public float getOSversion() {
        return OSversion;
    }

    /** 
     * Процедура получения наименования модели смартфона {@link Smartphone#model}
     * @return возвращает строку с наименованием модели смартфона
     */
    public String getModel() {
        return model;
    }

    /** 
     * Конструктор - создание нового экземпляра смартфона
     * @see Smartphone#Smartphone(String, String, String, float, float, String)
     */    
    public Smartphone() {
        super();
        OSversion = 0.0f;
        model = "Unknown";
    }

    /** 
     * Конструктор - создание нового экземпляра смартфона
     * @param Firm - строка с наименованием фирмы-производителя смартфона
     * @param Color - строка с наименованием цвета смартфона
     * @param OS - строка с наименованием операционной системы смартфона
     * @param Memory - число - объём физической памяти смартфона
     * @param OSVersion - версия операционной системы
     * @param Model - строка с наименованием модели смартфона
     * @see Smartphone#Smartphone()
     */   
    public Smartphone(String Firm, String Color, String OS, float Memory, float OSVersion, String Model) {
        super(Firm, Color, OS, Memory);
        OSversion = OSVersion;
        model = Model;
    }

    /** 
     * Процедура получения всех параметров смартфона в понятном пользователю виде
     * @return возвращает строку со значениями всех параметров смартфона и подписями к ним
     */
    public String toString() {
        return "\nСмартфон фирмы " + getFirm() + "\nЦвета " + getColor() + "\nНа операционной системе " + getOS()
            + "\nС объёмом памяти " + getMemory() + "\nВерсия операционной системы: " + getOSversion() + "\nМодель: " + getModel() + "\n";
    }
}

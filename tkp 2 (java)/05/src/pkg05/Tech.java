package pkg05;

/**
 * Класс компьютерной техники, содержащий основные параметры
 * @author 211-727 Шемарева Анастасия
 */

public class Tech {
    /** Фирма-производитель техники */
    private String firm;
    /** Цвет техники */
    private String color;
    /** Операционная система техники */
    private String os;
    /** Объём физической памяти техники */
    private float memory;

    /** 
     * Процедура установки фирмы-производителя техники
     * @param Firm - строка с наименованием фирмы-производителя
     */
    public void setFirm(String Firm) {
        firm = Firm;
    }
    
    /** 
     * Процедура установки цвета техники
     * @param Color - строка с наименованием цвета техники
     */
    public void setColor(String Color) {
        color = Color;
    }
    
    /** 
     * Процедура установки операционной системы техники
     * @param OS - строка с наименованием операционной системы техники
     */
    public void setOS(String OS) {
        os = OS;
    }
    
    /** 
     * Процедура установки объёма физический памяти техники
     * @param Memory - число - объём физической памяти техники
     */
    public void setMemory(float Memory) {
        memory = Memory;
    }
    
    /** 
     * Процедура получения фирмы-производителя техники {@link Tech#firm}
     * @return возвращает строку с наименованием фирмы-производителя техники
     */
    public String getFirm() {
        return firm;
    }
    
    /** 
     * Процедура получения цвета техники {@link Tech#color}
     * @return возвращает строку с наименованием цвета техники
     */    
    public String getColor() {
        return color;
    }
    
    /** 
     * Процедура получения операционной системы техники {@link Tech#os}
     * @return возвращает строку с наименованием операционной системы техники
     */    
    public String getOS() {
        return os;
    }
    
    /** 
     * Процедура получения объёма физической памяти техники {@link Tech#memory}
     * @return возвращает строку с объёмом физической памяти техники
     */    
    public float getMemory() {
        return memory;
    }
    
    /** 
     * Конструктор - создание нового экземпляра компьтерной техники
     * @see Tech#Tech(String, String, String, float)
     */
    public Tech() {
        firm = "Без названия";
        color = "black";
        os = "Windows";
        memory = 0.0f;
    }
    
    /** 
     * Конструктор - создание нового экземпляра компьтерной техники
     * @param Firm - строка с наименованием фирмы-производителя техники
     * @param Color - строка с наименованием цвета техники
     * @param OS - строка с наименованием операционной системы техники
     * @param Memory - число - объём физической памяти техники
     * @see Tech#Tech()
     */
    public Tech(String Firm, String Color, String OS, float Memory) {
        firm = Firm;
        color = Color;
        os = OS;
        memory = Memory;
    }
}

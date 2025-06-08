package pkg05;

/**
 * Класс ноутбука, расширяющий класс компьютерной техники {@link Tech}
 * @author 211-727 Шемарева Анастасия
 */

public class Notebook extends Tech {
    /** Наличие дискретной видеокарты */
    private boolean discreteGraphic;
    /** Наличие камеры */
    private boolean camera;

    /** 
     * Процедура установки наличия дискретной видеокарты ноутбука
     * @param DiscreteGraphic - наличие дискретной графики
     */
    public void setDiscreteGraphic(boolean DiscreteGraphic) {
        discreteGraphic = DiscreteGraphic;
    }

    /** 
     * Процедура установки наличия камеры ноутбука
     * @param Camera - наличие камеры
     */
    public void setCameraInfo(boolean Camera) {
        camera = Camera;
    }

    /** 
     * Процедура получения информации о наличии дискретной видеокарты ноутбука {@link Notebook#discreteGraphic}
     * @return возвращает true, если имеется дискретная видеокарта
     */
    public boolean hasDiscreteGraphic() {
        return discreteGraphic;
    }

    /** 
     * Процедура получения информации о наличии камеры в ноутбуке {@link Notebook#camera}
     * @return возвращает true, если имеется камера
     */
    public boolean hasCamera() {
        return camera;
    }

    /** 
     * Конструктор - создание нового экземпляра ноутбука
     * @see Notebook#Notebook(String, String, String, float, boolean, boolean)
     */
    public Notebook() {
        super();
        discreteGraphic = camera = false;
    }

    /** 
     * Конструктор - создание нового экземпляра ноутбука
     * @param Firm - строка с наименованием фирмы-производителя ноутбука
     * @param Color - строка с наименованием цвета ноутбука
     * @param OS - строка с наименованием операционной системы ноутбука
     * @param Memory - число - объём физической памяти ноутбука
     * @param DiscreteGraphic - наличие дискретной графики
     * @param Camera - наличие камеры
     * @see Notebook#Notebook()
     */
    public Notebook(String Firm, String Color, String OS, float Memory, boolean DiscreteGraphic, boolean Camera) {
        super(Firm, Color, OS, Memory);
        discreteGraphic = DiscreteGraphic;
        camera = Camera;
    }

    /** 
     * Процедура получения всех параметров ноутбука в понятном пользователю виде
     * @return возвращает строку со значениями всех параметров ноутбука и подписями к ним
     */
    public String toString() {
        return "\nНоутбук фирмы " + getFirm() + "\nЦвета " + getColor() + "\nНа операционной системе " + getOS()
            + "\nС объёмом памяти " + getMemory() + "\nДискретная графика " + ((hasDiscreteGraphic())? "присутствует" : "отсутствует")
            + ((hasCamera())? "\nС веб-камерой" : "\nБез веб-камеры") + "\n";
    }
}

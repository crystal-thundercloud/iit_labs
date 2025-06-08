public class Auto {
    private String firm; //создаем закрытый член нашего класса с названием фирмы автомобиля
    private String gosNum; //госномер
    private int maxSpeed; // закрытый член класса, содержащий максимальную скорость

    public void setFirm(String firma) { //открытая функция (метод класса) для задания
        firm = firma; //значения фирмы автомобиля
    }
    public void setGosnum(String num) { //открытая функция (метод класса) для задания
        gosNum = num; //значения фирмы автомобиля
    }

    public void setMaxSpeed(int speed) { //открытая функция (метод класса) для задания
        maxSpeed = speed; //значения максимальной скорости автомобиля
    }

    public int getMaxSpeed() { //открытая функция (метод класса) для вывода значения
        return maxSpeed; //максимальной скорости
    }

    public String getFirm() { //открытая функция (метод класса) для вывода значения
        return firm; //заданной фирмы
    }

    public String getGosNum() { //открытая функция (метод класса) для вывода значения
        return gosNum; //заданной фирмы
    }

    public Auto() { // конструктор класса (без параметров)
        firm = "Без названия";
        gosNum = "А000АА";
        maxSpeed = 0;
    }

    public Auto(String firma, String num, int speed) { //конструктор класса (с параметрами)
        firm = firma;
        gosNum = num;
        maxSpeed = speed;
    }
}


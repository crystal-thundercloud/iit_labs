package Ex;

public class Notebook extends Tech {
    private boolean discreteGraphic; //дискретная ли видеокарта
    private boolean camera; //есть ли камера

    public void setDiscreteGraphic(boolean DiscreteGraphic) {
        discreteGraphic = DiscreteGraphic;
    }

    public void setCameraInfo(boolean Camera) {
        camera = Camera;
    }

    public boolean hasDiscreteGraphic() {
        return discreteGraphic;
    }

    public boolean hasCamera() {
        return camera;
    }

    public Notebook() {
        super();
        discreteGraphic = camera = false;
    }

    public Notebook(String Firm, String Color, String OS, float Memory, boolean DiscreteGraphic, boolean Camera) {
        super(Firm, Color, OS, Memory);
        discreteGraphic = DiscreteGraphic;
        camera = Camera;
    }

    public String toString() {
        return "\nНоутбук фирмы " + getFirm() + "\nЦвета " + getColor() + "\nНа операционной системе " + getOS()
            + "\nС объёмом памяти " + getMemory() + "\nДискретная графика " + ((hasDiscreteGraphic())? "присутствует" : "отсутствует")
            + ((hasCamera())? "\nС веб-камерой" : "\nБез веб-камеры") + "\n";
    }
}

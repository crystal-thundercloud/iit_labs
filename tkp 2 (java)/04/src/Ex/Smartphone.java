package Ex;

public class Smartphone extends Tech {
    private float OSversion; //версия операцинной системы
    private String model; //модель

    public void setOSversion(float OSVersion) {
        OSversion = OSVersion;
    }

    public void setModelInfo(String Model) {
        model = Model;
    }

    public float getOSversion() {
        return OSversion;
    }

    public String getModel() {
        return model;
    }

    public Smartphone() {
        super();
        OSversion = 0.0f;
        model = "Unknown";
    }

    public Smartphone(String Firm, String Color, String OS, float Memory, float OSVersion, String Model) {
        super(Firm, Color, OS, Memory);
        OSversion = OSVersion;
        model = Model;
    }

    public String toString() {
        return "\nСмартфон фирмы " + getFirm() + "\nЦвета " + getColor() + "\nНа операционной системе " + getOS()
            + "\nС объёмом памяти " + getMemory() + "\nВерсия операционной системы: " + getOSversion() + "\nМодель: " + getModel() + "\n";
    }
}

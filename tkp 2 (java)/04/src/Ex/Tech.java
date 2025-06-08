package Ex;

public class Tech {
    private String firm; //производитель
    private String color; //цвет
    private String os; //операционная система
    private float memory; //физическая память

    public void setFirm(String Firm) {
        firm = Firm;
    }
    
    public void setColor(String Color) {
        color = Color;
    }
    
    public void setOS(String OS) {
        os = OS;
    }
    
    public void setMemory(float Memory) {
        memory = Memory;
    }

    public String getFirm() {
        return firm;
    }
    
    public String getColor() {
        return color;
    }
    
    public String getOS() {
        return os;
    }
    
    public float getMemory() {
        return memory;
    }

    public Tech() {
        firm = "Без названия";
        color = "black";
        os = "Windows";
        memory = 0.0f;
    }

    public Tech(String Firm, String Color, String OS, float Memory) {
        firm = Firm;
        color = Color;
        os = OS;
        memory = Memory;
    }
}

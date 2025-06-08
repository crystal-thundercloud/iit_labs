package Ex;

public class Furniture {
    private float width;
    private float depth;
    private float height;
    private String color;
    
    public void setColor(String Color) {
        color = Color;
    }
    
    public void setWidth(float Width) {
        width = Width;
    }
    
    public void setDepth(float Depth) {
        depth = Depth;
    }
    
    public void setHeight(float Height) {
        height = Height;
    }

    public String getColor() {
        return color;
    }
    
    public float getWidth() {
        return width;
    }
    
    public float getDepth() {
        return depth;
    }
    
    public float getHeight() {
        return height;
    }

    public Furniture() {
        width = 0.0f;
        depth = 0.0f;
        height = 0.0f;
        color = "black";
    }

    public Furniture(float Width, float Depth, float Height, String Color) {
        width = Width;
        depth = Depth;
        height = Height;
        color = Color;
    }
}

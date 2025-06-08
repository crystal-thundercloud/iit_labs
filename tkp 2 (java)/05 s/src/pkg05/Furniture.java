package pkg05;
/**
 * Base class containing main furniture parametres
 * @author Meftah Saad
 */
public class Furniture {
    /** Furniture width (cm) */
    private float width;
    /** Furniture depth (cm) */
    private float depth;
    /** Furniture height (cm) */
    private float height;
    /** Furniture color name */
    private String color;
    
    /** 
     * Set furniture color name
     * @param Color name of the color
     */
    public void setColor(String Color) {
        color = Color;
    }

    /**
     * Set furniture width (cm)
     * @param Width furniture width
     */
    public void setWidth(float Width) {
        width = Width;
    }

    /**
     * Set furniture depth (cm)
     * @param Depth furniture depth
     */
    public void setDepth(float Depth) {
        depth = Depth;
    }

    /**
     * Set furniture height (cm)
     * @param Height furniture height
     */
    public void setHeight(float Height) {
        height = Height;
    }

    /**
     * Get furniture color
     * @return string containing furniture color name
     */
    public String getColor() {
        return color;
    }

    /**
     * Get furniture width
     * @return float representing furniture width in cm
     */
    public float getWidth() {
        return width;
    }

    /**
     * Get furniture depth
     * @return float representing furniture depth in cm
     */
    public float getDepth() {
        return depth;
    }

    /**
     * Get furniture height
     * @return float representing furniture height in cm
     */
    public float getHeight() {
        return height;
    }
    
    /**
     * Basic constructor creating a piece of furniture
     * @see #Furniture(float, float, float, java.lang.String) 
     */
    public Furniture() {
        width = 0.0f;
        depth = 0.0f;
        height = 0.0f;
        color = "black";
    }

    /**
     * Basic constructor creating a piece of furniture
     * @param Width furniture width (cm)
     * @param Depth furniture depth (cm)
     * @param Height furniture height (cm)
     * @param Color furniture color name
     * @see #Furniture()
     */
    public Furniture(float Width, float Depth, float Height, String Color) {
        width = Width;
        depth = Depth;
        height = Height;
        color = Color;
    }
}

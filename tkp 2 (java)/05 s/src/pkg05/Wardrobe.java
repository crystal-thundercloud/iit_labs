package pkg05;

/**
 * Wardrobe class, extending furniture class
 */
public class Wardrobe extends Furniture {
    /** Number of sections in the wardrobe */
    private int sectionsNum;
    /** Is there a mirror? */
    private boolean mirror;
    /** Is it a sliding wardrobe? */
    private boolean sliding;
    
    /**
     * Set number of sections in the wardrobe
     * @param SectionsNum number of sections
     */
    public void setSectionsNum(int SectionsNum) {
        sectionsNum = SectionsNum;
    }
    
    /**
     * Set the presence of mirror for this wardrobe
     * @param hasMirror set true, if there is a mirror
     */
    public void setMirror(boolean hasMirror) {
        mirror = hasMirror;
    }

    /**
     * Set wardrobe doors form-factor
     * @param isSliding set true, if it is a sliding wardrobe
     */
    public void setSliding(boolean isSliding) {
        sliding = isSliding;
    }

    /**
     * Get number of sections in the wardrobe
     * @return number of sections
     */
    public int getSectionsNum() {
        return sectionsNum;
    }

    /**
     * Is there a mirror in the wardrobe?
     * @return true, if there is a mirror
     */
    public boolean hasMirror() {
        return mirror;
    }

    /**
     * Is it a sliding wardrobe?
     * @return truem if it is a sliding wardrobe
     */
    public boolean isSliding() {
        return sliding;
    }
    
    /**
     * Basic constructor creating a wardrobe
     * @see #Wardrobe(float, float, float, java.lang.String, int, boolean, boolean) 
     */
    public Wardrobe() {
        super();
        sectionsNum = 1;
        mirror = sliding = false;
    }

    /**
     * Basic constructor creating a wardrobe
     * @param Width wardrobe width (cm)
     * @param Depth wardrobe depth (cm)
     * @param Height wardrobe height (cm)
     * @param Color wardrobe color
     * @param SectionsNum number of sections in the wardrobe
     * @param hasMirror is there a mirror in this wardrobe?
     * @param isSliding is it a sliding wardrobe?
     * @see #Wardrobe()
     */
    public Wardrobe(float Width, float Depth, float Height, String Color, int SectionsNum, boolean hasMirror, boolean isSliding) {
        super(Width, Depth, Height, Color);
        mirror = hasMirror;
        sliding = isSliding;
    }
    
    /**
     * Get all wardrobe characteristics in user-friendly form
     * @return string containing wardrobe characteristics with labels
     */
    public String toString() {
        return "\n" + (isSliding()? "Sliding wardrobe " : "Wardrobe ") + (hasMirror()? "with mirror" : "without mirror") + "\nSize: " + getWidth() + "x" + getDepth() + "x" + getHeight() + " cm" + "\nColor: " + getColor() + "\n";
    }
}

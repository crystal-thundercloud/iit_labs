package Ex;

public class Wardrobe extends Furniture {
    private int sectionsNum;
    private boolean mirror;
    private boolean sliding;

    public void setSectionsNum(int SectionsNum) {
        sectionsNum = SectionsNum;
    }

    public void setMirror(boolean hasMirror) {
        mirror = hasMirror;
    }

    public void setSliding(boolean isSliding) {
        sliding = isSliding;
    }

    public int getSectionsNum() {
        return sectionsNum;
    }

    public boolean hasMirror() {
        return mirror;
    }

    public boolean isSliding() {
        return sliding;
    }
    
    public Wardrobe() {
        super();
        sectionsNum = 1;
        mirror = sliding = false;
    }

    public Wardrobe(float Width, float Depth, float Height, String Color, int SectionsNum, boolean hasMirror, boolean isSliding) {
        super(Width, Depth, Height, Color);
        mirror = hasMirror;
        sliding = isSliding;
    }

    public String toString() {
        return "\n" + (isSliding()? "Sliding wardrobe " : "Wardrobe ") + (hasMirror()? "with mirror" : "without mirror") + "\nSize: " + getWidth() + "x" + getDepth() + "x" + getHeight() + " cm" + "\nColor: " + getColor() + "\n";
    }
}

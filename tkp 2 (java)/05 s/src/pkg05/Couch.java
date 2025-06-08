package pkg05;

/**
 * Couch class, extending furniture class
 */
public class Couch extends Furniture {
    /** Number of seats on the couch */
    private int seatsNum;
    /** Is it a corner couch? */
    private boolean corner;
   
    /**
     * Set number of seats on the couch
     * @param SeatsNum number of seats
     */
    public void setSeatsNum(int SeatsNum) {
        seatsNum = SeatsNum;
    }

    /**
     * Set couch form-factor
     * @param isCorner if true, couch is cornered
     */
    public void setCorner(boolean isCorner) {
        corner = isCorner;
    }

    /**
     * Get number of seats on the couch
     * @return number of seats
     */
    public int getSeatsNum() {
        return seatsNum;
    }

    /**
     * Get couch form-factor
     * @return true, if couch is cornered
     */
    public boolean isCorner() {
        return corner;
    }

    /**
     * Basic constructor creating a couch
     * @see #Couch(float, float, float, java.lang.String, int, boolean) 
     */
    public Couch() {
        super();
        seatsNum = 1;
        corner = false;
    }

    /**
     * Basic constructor creating a couch
     * @param Width couch width (cm)
     * @param Depth couch depth (cm)
     * @param Height couch height (cm)
     * @param Color couch color name
     * @param SeatsNum couch seats number
     * @param isCorner is couch cornered or not
     * @see #Couch() 
     */
    public Couch(float Width, float Depth, float Height, String Color, int SeatsNum, boolean isCorner) {
        super(Width, Depth, Height, Color);
        seatsNum = SeatsNum;
        corner = isCorner;
    }

    /**
     * Get all couch characteristics in user-friendly form
     * @return string containing couch characteristics with labels
     */
    public String toString() {
        return "\n" + (isCorner()? "Corner couch" : "Couch") + "\nSize: " + getWidth() + "x" + getDepth() + "x" + getHeight() + " cm" + "\nColor: " + getColor() + "Seats number: " + getSeatsNum() + "\n";
    }
}

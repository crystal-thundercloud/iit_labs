package Ex;

public class Couch extends Furniture {
    private int seatsNum;
    private boolean corner;
   
    public void setSeatsNum(int SeatsNum) {
        seatsNum = SeatsNum;
    }

    public void setCorner(boolean isCorner) {
        corner = isCorner;
    }

    public int getSeatsNum() {
        return seatsNum;
    }

    public boolean isCorner() {
        return corner;
    }

    public Couch() {
        super();
        seatsNum = 1;
        corner = false;
    }

    public Couch(float Width, float Depth, float Height, String Color, int SeatsNum, boolean isCorner) {
        super(Width, Depth, Height, Color);
        seatsNum = SeatsNum;
        corner = isCorner;
    }

    public String toString() {
        return "\n" + (isCorner()? "Corner couch" : "Couch") + "\nSize: " + getWidth() + "x" + getDepth() + "x" + getHeight() + " cm" + "\nColor: " + getColor() + "Seats number: " + getSeatsNum() + "\n";
    }
}

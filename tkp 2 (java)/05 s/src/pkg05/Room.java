package pkg05;

import java.util.ArrayList;
/**
 * Room class, containing a list of furniture
 */
public class Room {
    /** A list containing furniture in the room */
    private ArrayList<Furniture> arrFurniture = new ArrayList<>();

    /**
     * Basic constructor creating a room
     * @see #Room(java.util.ArrayList) 
     */
    public Room() {
    }
    
    /**
     * Basic constructor creating a room
     * @param n furniture list
     * @see #Room()
     */
    public Room(ArrayList<Furniture> n) {
        arrFurniture = n;
    }

    /**
     * Add new furniture to the room
     * @param m furniture to be added
     */
    public void addFurniture(Furniture m) {
        arrFurniture.add(m);
    }
    
    /**
     * Check if there is a specified furniture in the room
     * @param m furniture to be found
     * @return true, if furniture was found
     */
    public Boolean findFurniture(Furniture m) {
        return arrFurniture.contains(m);
    }

    /**
     * Remove specified furniture from the room
     * @param m furniture to be removed
     * @return true, if furniture was removed successfully
     */
    public Boolean removeFurniture(Furniture m) {
        return arrFurniture.remove(m);
    }

    /**
     * Count number of couches in the room
     * @return number of couches
     */
    public int countCouches() {
        int counter = 0;
        for (Furniture t : arrFurniture) if (t instanceof Couch) counter++;
        return counter;
    }

    /**
     * Count number of wardrobes in the room
     * @return number of wardrobes
     */
    public int countWardrobes() {
        int counter = 0;
        for (Furniture t : arrFurniture) if (t instanceof Wardrobe) counter++;
        return counter;
    }

    /**
     * Print all room furniture characteristics in user-friendly form
     */
    public void printRoomFurniture() {
        for (Furniture t:arrFurniture) System.out.println("\t"+t.toString());
    }
}

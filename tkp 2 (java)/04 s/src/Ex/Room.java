package Ex;

import java.util.ArrayList;

public class Room {
    private ArrayList<Furniture> arrFurniture = new ArrayList<Furniture>();

    public Room() {
    }
    
    public Room(ArrayList<Furniture> n) {
        arrFurniture = n;
    }

    public void addFurniture(Furniture m) {
        arrFurniture.add(m);
    }
    
    public Boolean findFurniture(Furniture m) {
        return arrFurniture.contains(m);
    }

    public Boolean removeFurniture(Furniture m) {
        return arrFurniture.remove(m);
    }

    public int countCouches() {
        int counter = 0;
        for (Furniture t : arrFurniture) if (t instanceof Couch) counter++;
        return counter;
    }

    public int countWardrobes() {
        int counter = 0;
        for (Furniture t : arrFurniture) if (t instanceof Wardrobe) counter++;
        return counter;
    }

    public void printRoomFurniture() {
        for (Furniture t:arrFurniture) System.out.println("\t"+t.toString());
    }
}

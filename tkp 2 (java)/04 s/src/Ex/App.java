package Ex;

import java.util.Scanner;

public class App {
     public static void main(String[] args) {

        Furniture furni = new Furniture();
        Scanner in = new Scanner(System.in, "cp866");

        System.out.print("Type in width: ");
        furni.setWidth(in.nextFloat());

        System.out.print("Type in depth: ");
        furni.setDepth(in.nextFloat());

        System.out.print("Type in height: ");
        furni.setHeight(in.nextFloat());

        System.out.print("Type in color: ");
        furni.setColor(in.next());

        System.out.println("Some furniture: " + furni.getDepth() + "x" + furni.getWidth() + "x" + furni.getHeight() + " cm " + furni.getColor() + "\n");

        Couch couch1 = new Couch(220.5f, 85f, 45.8f, "White", 2, false);
        Couch couch2 = new Couch();
        
        System.out.print("Type in couch width: ");
        couch2.setWidth(in.nextFloat());
        
        System.out.print("Type in couch depth: ");
        couch2.setDepth(in.nextFloat());
        
        System.out.print("Type in couch height: ");
        couch2.setHeight(in.nextFloat());
        
        System.out.print("Type in couch color: ");
        couch2.setColor(in.next());

        System.out.print("Type in couch seats number: ");
        couch2.setSeatsNum(in.nextInt());

        System.out.print("Is it corner couch? (true/false): ");
        couch2.setCorner(in.nextBoolean());

        System.out.println();

        System.out.println("First couch: " + couch1.toString());
        System.out.println("Second couch: " + couch2.toString());
        
        Wardrobe wardrobe = new Wardrobe();
        
        System.out.print("Type in wardrobe width: ");
        wardrobe.setWidth(in.nextFloat());
        
        System.out.print("Type in wardrobe depth: ");
        wardrobe.setDepth(in.nextFloat());
        
        System.out.print("Type in wardrobe height: ");
        wardrobe.setHeight(in.nextFloat());
        
        System.out.print("Type in wardrobe color: ");
        wardrobe.setColor(in.next());

        System.out.print("Type in wardrobe sections number: ");
        wardrobe.setSectionsNum(in.nextInt());

        System.out.print("Is it sliding wardrobe? (true/false): ");
        wardrobe.setSliding(in.nextBoolean());

        System.out.print("Is there a mirror in this wardrobe? (true/false): ");
        wardrobe.setMirror(in.nextBoolean());

        System.out.println(wardrobe.toString());

        Room rs = new Room();
        rs.addFurniture(couch1);
        rs.addFurniture(couch2);
        rs.addFurniture(wardrobe);

        System.out.println("There are " + rs.countCouches() + " couches and " + rs.countWardrobes() + " wardrobes in the room");
        System.out.println("List of furniture in the room: ");
        rs.printRoomFurniture();
    }
}

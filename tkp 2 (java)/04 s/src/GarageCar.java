import java.util.ArrayList;

public class GarageCar {
    private ArrayList<Auto> masCar = new ArrayList<Auto>();

    public void addCar(Auto m) {
        masCar.add(m);
    }

    public GarageCar() {
    }

    public Boolean findCar(Auto m) {
        return masCar.contains(m);
    }

    public GarageCar(ArrayList<Auto> n) {
        masCar = n;
    }

    public Boolean removeCar(Auto m) { // delete car
        return masCar.remove(m);
    }

    public void printGarage() {
        System.out.println("В гараже: ");
        for (Auto a:masCar){
            System.out.println("\t"+a.toString());
        }
    }
}

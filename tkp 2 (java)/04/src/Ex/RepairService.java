package Ex;

import java.util.ArrayList;

public class RepairService {
    private ArrayList<Tech> masTech = new ArrayList<Tech>();

    public RepairService() {
    }
    
    public RepairService(ArrayList<Tech> n) {
        masTech = n;
    }

    public void addTech(Tech m) {
        masTech.add(m);
    }
    
    public Boolean findTech(Tech m) {
        return masTech.contains(m);
    }

    public Boolean removeTech(Tech m) {
        return masTech.remove(m);
    }

    public int countNotebooks() {
        int counter = 0;
        for (Tech t : masTech) if (t instanceof Notebook) counter++;
        return counter;
    }

    public int countSmartphones() {
        int counter = 0;
        for (Tech t : masTech) if (t instanceof Smartphone) counter++;
        return counter;
    }

    public void printService() {
        for (Tech t:masTech) System.out.println("\t"+t.toString());
    }
}

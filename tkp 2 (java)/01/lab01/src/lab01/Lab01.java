package lab01;
import javax.swing.*;

public class Lab01 {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Всем большой привет!");
        
        String name;
        
        name = JOptionPane.showInputDialog("Привет, как Вас зовут?");
        
        JOptionPane.showMessageDialog(null, "Приятно познакомиться, \n" + name + "!");
        JOptionPane.showMessageDialog(null, name);
        
        byte x=10, y=50;
        x=(byte)(x+1);
        byte z=(byte)(x+y);
        JOptionPane.showMessageDialog(null, z);
    }
}

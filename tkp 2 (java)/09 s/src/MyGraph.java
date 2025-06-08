import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyGraph extends JFrame implements ActionListener {
    private MyPanel myPanel = new MyPanel();

    public static void main(String[] args) {
        new MyGraph("Окно сграфикой");
    }

    public MyGraph(String s) {
        super(s);
        JMenuBar myMenuBar=new JMenuBar();
        JMenu menu = new JMenu("What to draw");
        
        JMenuItem[] menuBtns = new JMenuItem[6];

        for (int i = 0; i < menuBtns.length; i++) {
            menuBtns[i] = new JMenuItem(MyPanel.Figure.values()[i].toString());
            menuBtns[i].addActionListener(this);
            menu.add(menuBtns[i]);
        }

        myMenuBar.add(menu);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setJMenuBar(myMenuBar);
        add(myPanel, BorderLayout.CENTER);
        
        pack();
        Dimension size = getSize();
        size.setSize(size.width * 5.5f, size.height + 150);
        setSize(size);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        myPanel.ris(e.getActionCommand());
    }
}

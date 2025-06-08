import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyGraph extends JFrame implements ActionListener {
    private JMyPanel myPanel = new JMyPanel();

    public static void main(String[] args) {
        new MyGraph("Окно сграфикой");
    }

    public MyGraph(String s) {
        super(s);
        JMenuBar myMenuBar=new JMenuBar();// создаем строку меню
        JMenu menu = new JMenu("Нарисовать...");
        
        // число пунктов меню всегда равно количеству пунктов в enum
        JMenuItem[] menuBtns = new JMenuItem[JMyPanel.Figure.values().length];

        for (int i = 0; i < menuBtns.length; i++) {
            menuBtns[i] = new JMenuItem(JMyPanel.Figure.values()[i].toString());
            menuBtns[i].addActionListener(this);
            if (i < menuBtns.length - 1) {
                // очистка - отдельный пункт меню, так удобнее
                // поэтому она не добавляется на панель в цикле
                menu.add(menuBtns[i]);
            }
        }

        myMenuBar.add(menu);
        // добавить очистку после основного меню
        myMenuBar.add(menuBtns[menuBtns.length-1]);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setJMenuBar(myMenuBar);
        add(myPanel, BorderLayout.CENTER);
        
        pack();
        // ширина окна под длину фамилии и без упаковки
        Dimension size = getSize();
        size.setSize(size.width * 4.6, size.height + 265);
        setSize(size);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        myPanel.ris(e.getActionCommand());
    }
}

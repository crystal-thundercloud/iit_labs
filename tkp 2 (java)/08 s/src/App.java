import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.ArrayList;

public class App {
    static int num1;
    static int num2;
    static int operation;
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        Dimension dim = new Dimension(75, 50);
        
        JLabel label1 = new JLabel("Метка 1");
        label1.setBorder(new EmptyBorder(10,5,10,5));
        JSlider slider = new JSlider();
        slider.setBorder(new EmptyBorder(10, 40, 10, 40));
        
        JLabel label2 = new JLabel("Метка 2");
        label2.setBorder(new EmptyBorder(10,5,10,5));
        JTextField textField = new JTextField();
        textField.setText("0");
        
        slider.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                label2.setText(Integer.toString(slider.getValue()));
            }
        });

        
        slider.addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                if (e.getWheelRotation() < 0) slider.setValue(slider.getValue() - 1);
                else if (e.getWheelRotation() > 0) slider.setValue(slider.getValue() + 1);

            }
        });
        
        JPanel northPanel = new JPanel();
        northPanel.setLayout(new BorderLayout());
        northPanel.add(label1, BorderLayout.WEST);
        northPanel.add(slider, BorderLayout.CENTER);
        northPanel.add(label2, BorderLayout.EAST);
        northPanel.add(textField, BorderLayout.SOUTH);
        
        JPanel cent = new JPanel(new BorderLayout());
        ArrayList<JButton> masB=new ArrayList<JButton>();
        JPanel centerPanel = new JPanel(new GridLayout(4, 3, 10, 10));
        for (int i = 1; i <= 12; i++) {
            if (i == 10 || i == 12) {
                JLabel space = new JLabel();
                space.setPreferredSize(dim);
                centerPanel.add(space);
            } else if (i == 11) {
                JButton but = new JButton("0");
                but.setPreferredSize(new Dimension(dim));
                centerPanel.add(but);
                masB.add(but);
            } else {
                JButton but = new JButton("" + i);
                but.setPreferredSize(new Dimension(dim));
                centerPanel.add(but);
                masB.add(but);
                if (i == 3 || i == 6 || i == 9) {
                    JLabel space = new JLabel();
                    space.setPreferredSize(dim);
                    centerPanel.add(space);
                }
            }
        }
        
        for (JButton btn : masB) {
            btn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    if (textField.getText() == "0") System.out.println(textField.getText());
                    textField.setText(textField.getText() + btn.getText());
                }
            });
        }

        JPanel eastPanel = new JPanel(new GridBagLayout());
        JButton but1 = new JButton("+");
        but1.setPreferredSize(new Dimension(dim));
        but1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                num1 = Integer.parseInt(textField.getText());
                operation = 1;
                label1.setText(Integer.toString(num1));
                textField.setText("");
            }
        });
            
        JButton but2 = new JButton("-");
        but2.setPreferredSize(new Dimension(dim));
        but2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                num1 = Integer.parseInt(textField.getText());
                operation = 2;
                label1.setText(Integer.toString(num1));
                textField.setText("");
            }
        });

        JButton but3 = new JButton("=");
        but3.setPreferredSize(new Dimension(dim));
        but3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                num2 = Integer.parseInt(textField.getText());
                int result = 0;
                if (operation == 1) result = num1 + num2;
                else if (operation == 2) result = num1 - num2;
                textField.setText(Integer.toString(result));
                num1 = num2 = operation = 0;
            }
        });

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.weighty = 0.0;
        gbc.anchor = GridBagConstraints.NORTHEAST;
        gbc.insets.bottom = 10;

        eastPanel.add(but1, gbc); eastPanel.add(but2, gbc); eastPanel.add(but3,gbc);
        JPanel trueEast = new JPanel(new BorderLayout());
        JLabel sp = new JLabel();
        sp.setPreferredSize(dim);
        trueEast.add(eastPanel, BorderLayout.NORTH);
        trueEast.add(sp, BorderLayout.EAST);
        
        cent.add(centerPanel, BorderLayout.WEST);
        cent.add(trueEast, BorderLayout.EAST);
        
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(northPanel, BorderLayout.NORTH);
        mainPanel.add(cent, BorderLayout.CENTER);

        frame.getContentPane().add(mainPanel);

        frame.setSize(1600, 900);
        frame.setVisible(true);
        frame.pack();
        frame.setMinimumSize(frame.getSize());
    }
}

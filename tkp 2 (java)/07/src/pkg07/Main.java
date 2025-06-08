package pkg07;

import java.awt.*;
import java.util.ArrayList;
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame(""); // в задании нет заголовка
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,600);
        
        // слева область текста
        JTextArea textarea = new JTextArea("TextArea");
        textarea.setPreferredSize(new Dimension(160, 200));
        
        // сверху и снизу лейблы, автоматически по ширине окна
        // но им нужно сделать выравнивание текста по центру
        JLabel label1 = new JLabel("Метка 1");
        label1.setHorizontalAlignment(JLabel.CENTER);
        
        JLabel label2 = new JLabel("Метка 2");
        label2.setHorizontalAlignment(JLabel.CENTER);

        // массив для хранения кнопок и панель с компоновкой в виде сетки 5 на 3
        ArrayList<JButton> btnArr = new ArrayList<>();
        ButtonGroup btnGroup = new ButtonGroup();
        JPanel btnPanel = new JPanel(new GridLayout(5, 3, 0, 0));
        
        // счётчик для имён кнопок, чтобы не делать второй for
        int counter = 1;
        
        // всего на панели 15 элементов - 8 кнопок и 7 белых полей
        for (int i = 0; i < 15; i++) {
            if (i % 2 != 0) { // каждый чётный элемент - белое поле
                // на картинке специфичная рамка у белых полей
                JTextField ta = new JTextField(""); // оказалось, это не teaxtarea, а textfield
                ta.setPreferredSize(new Dimension(115, 70));
                btnPanel.add(ta);
            }
            else { // каждый нечётный элемент - кнопка
                JButton btn = new JButton("Кнопка " + counter);
                btn.setPreferredSize(new Dimension(115, 70));
                btnArr.add(btn);
                btnGroup.add(btn);
                btnPanel.add(btn);
                counter++;
            }
        }
        
        frame.add(textarea,BorderLayout.WEST);
        frame.add(label1, BorderLayout.NORTH);
        frame.add(btnPanel,BorderLayout.EAST);
        frame.add(label2, BorderLayout.SOUTH);
        
        frame.setVisible(true);
        frame.pack();
        frame.setMinimumSize(frame.getSize());
    }
}

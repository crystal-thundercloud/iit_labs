import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.util.ArrayList;
import javax.swing.*;

public class App {
    public static void main(String[] args) {
        JFrame frame = new JFrame("");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,600);
        
        JTextArea textarea = new JTextArea("TextArea");
        textarea.setPreferredSize(new Dimension(160, 200));
        
        JLabel label1 = new JLabel("Метка 1");
        label1.setHorizontalAlignment(JLabel.CENTER);
        
        JLabel label2 = new JLabel("Метка 2");
        label2.setHorizontalAlignment(JLabel.CENTER);

        ArrayList<JButton> btnArr = new ArrayList<>();
        ButtonGroup btnGroup = new ButtonGroup();
        ArrayList<JTextField> textFieldsArr = new ArrayList<>();
        JPanel btnPanel = new JPanel(new GridLayout(5, 3, 0, 0));
        
        int counter = 1;
        
        for (int i = 0; i < 15; i++) {
            if (i % 2 != 0) {
                JTextField ta = new JTextField("");
                ta.setPreferredSize(new Dimension(115, 70));
                textFieldsArr.add(ta);
                btnPanel.add(ta);
            } else {
                JButton btn = new JButton("Кнопка " + counter);
                btn.setPreferredSize(new Dimension(115, 70));
                btnArr.add(btn);
                btnGroup.add(btn);
                btnPanel.add(btn);
                counter++;
            }
        }
        
        // обойтись без второго for не получилось...
        for (int i = 0; i < textFieldsArr.size(); i++) {
            JTextField tf = textFieldsArr.get(i); // когда у текстового поля меняется фон, в нём появляется текст
            tf.addPropertyChangeListener("background", new PropertyChangeListener() {
                public void propertyChange(PropertyChangeEvent evt) {
                    tf.setText("Фон изменён!");
                }
            });
            JButton btn = btnArr.get(i); // при нажатии на кнопку происходит изенение фона текстового поля с тем же номером
            btn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    tf.setBackground(Color.GREEN);
                }
            });
            if (i == textFieldsArr.size() - 1) { // последняя кнопка сбрасывает фоны и тексты полей
                JButton lastBtn = btnArr.get(i + 1);
                lastBtn.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        for (JTextField tf : textFieldsArr) {
                            tf.setBackground(Color.white);
                            tf.setText(null);
                        }
                    }
                });
            }
        }

        // добавление слушателя прокрутки колёсика мыши на области текста
        textarea.addMouseWheelListener(new MouseWheelListener() {
            public void mouseWheelMoved(MouseWheelEvent e) {
                if (e.getWheelRotation() < 0)
                    textarea.setText("Прокрутка вниз");
                else if (e.getWheelRotation() > 0) textarea.setText("Прокрутка вверх");
            }
        });

        frame.add(textarea,BorderLayout.WEST);
        frame.add(label1, BorderLayout.NORTH);
        frame.add(btnPanel,BorderLayout.EAST);
        frame.add(label2, BorderLayout.SOUTH);
        
        frame.setVisible(true);
        frame.pack();
        frame.setMinimumSize(frame.getSize());
    }
}

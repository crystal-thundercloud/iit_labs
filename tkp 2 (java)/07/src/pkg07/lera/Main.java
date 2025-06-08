/**
* @author Ануфриева Валерия 211-727
*/
//Для выполнения данной лабораторной работы нам понадобятся следующие элементы:
//JPanel – класс для работы с панелями; x5
//JTextField – однострочное текстовое поле; x6
//JCheckBox – кнопка-флажок; x9
//JComboBox – выпадающий список; x1
//JSpinner – компонент, позволяющий выбрать значение из указанной последовательности; x1
//JRadioButton – переключатели, радио-кнопк; x2
//JTextArea – многострочное текстовое поле; x1
//JSlider – компонент, позволяющий выбрать значение из заданного диапазона; x1
//И следующие компоновки:
//BorderLayout – размещает элементы в один из пяти регионов; x1
//GridLayout – размещает элементы таблично; x1
//BoxLayout – размещает элементы по вертикали или по горизонтали; x1
//FlowLayout – размещает элементы по порядку в том же направлении, что и ориентация контейнера; x1
import javax.swing.*;
import java.awt.*;
public class Main
{
public static void main(String[] args)
{
JFrame frame = new JFrame("TKP LAB 7 Anufrieva 211-727");// создаем окно с заголовком
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//делаем базовым действием при закрытие
// окна выход из приложения, иначе окно закроется, а программа в памяти останется
frame.setSize(300,300);//задаем размер окна
frame.setVisible(true);//делаем его видимым

JPanel textBoxes=new JPanel();//создаем панель для текстовых полей (6 штук)
textBoxes.setLayout(new GridLayout(2,3));//устанавливаем компоновщик (таблично: 2 строки, 3 столбца)
textBoxes.add(new JTextField("Text Box 1"));
textBoxes.add(new JTextField("Text Box 2"));
textBoxes.add(new JTextField("Text Box 3"));
textBoxes.add(new JTextField("Text Box 4"));
textBoxes.add(new JTextField("Text Box 5"));
textBoxes.add(new JTextField("Text Box 6"));
Box choiceCells=new Box(BoxLayout.Y_AXIS);//для ячеек выбора создаем объект Box для компоновки BoxLayout
choiceCells.add(new JCheckBox("Choice 1"));
choiceCells.add(new JCheckBox("Choice 2"));
choiceCells.add(new JCheckBox("Choice 3"));
choiceCells.add(new JCheckBox("Choice 4"));
choiceCells.add(new JCheckBox("Choice 5"));
choiceCells.add(new JCheckBox("Choice 6"));
choiceCells.add(new JCheckBox("Choice 7"));
choiceCells.add(new JCheckBox("Choice 8"));
choiceCells.add(new JCheckBox("Choice 9"));
JPanel otherButtons = new JPanel();//панель для других кнопок и элементов
otherButtons.setLayout(new FlowLayout());//компоновка для средней панели
otherButtons.add(new JComboBox(new String[]{"Hello", "This", "is", "my", "first", "ComboBox"}));//списочек
otherButtons.add(new JSpinner());//выбор цифрового значения
otherButtons.add(new JRadioButton("RadioButton 1"));//2 радиокнопки
otherButtons.add(new JRadioButton("RadioButton 2"));
//размещаем все элементы в компоновку BorderLayout по заданию:
frame.add(textBoxes,BorderLayout.NORTH); //текстовые поля наверх
frame.add(choiceCells,BorderLayout.WEST);//ячейки с выбором слева
frame.add(otherButtons,BorderLayout.CENTER);//другие виды кнопок в центр
frame.add(new JTextArea("Text Area"),BorderLayout.EAST);//текстовая область справа
frame.add(new JSlider(),BorderLayout.SOUTH);//ползунок вниз
}
}
import java.awt.*;
import java.awt.geom.*;

import javax.swing.JPanel;

public class JMyPanel extends JPanel {
    public static enum Figure {
        Линию, Овал, Прямоугольник, Скруглённый_прямоугольник, Фамилию, Очистить
    };

    private Figure vibor = Figure.Очистить;

    public JMyPanel() {
    }

    public void ris(String s) {
        vibor = Figure.valueOf(s);
        repaint();
    }

    public void paintComponent(Graphics gr) {
        super.paintComponent(gr);
        Graphics2D g = (Graphics2D) gr;
        BasicStroke pen;
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        switch (vibor) {
            case Линию:
                pen = new BasicStroke(20, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
                g.setStroke(pen);
                g.setColor(Color.blue);
                g.drawLine(20, 20, 100, 100);
                break;
            case Овал:
                // элементы массива с четными индексами задают длину штриха в пикселах, элементы с нечетными
                //индексами — длину промежутка; массив перебирается циклически;
                float[] dash = { 10, 30 };
                //определяем перо толщиной 10 точек, с квадратными концами линий, закругленными стыками линий,
                //расстоянием в 10 точек, с которого начинает действовать закругление, массив, определяющий вид
                //линии, и с какого элемента массива начинать узор
                pen = new BasicStroke(10, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_ROUND, 10, dash, 0);
                g.setStroke(pen);
                g.setColor(Color.red);
                //устанавливаем стиль заливки, в качестве параметра задаем градиент от красного к зеленому,
                //30, 30 – начальная точка первого цвета, 50, 50 – начальная точка второго цвета, true –
                //цикличность градиента
                g.setPaint(new GradientPaint(30, 30, Color.red, 50, 50, Color.green, true));
                //g.fill – создание объекта с заливкой, в качестве параметра задается объект из пакета Graphics2D,
                //в нашем случае – эллипс
                g.fill(new Ellipse2D.Double(20, 20, 100, 100));
                break;
            case Прямоугольник:
                float[] dash2 = { 20, 20 };
                pen = new BasicStroke(5, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_BEVEL, 1, dash2, 0);
                g.setStroke(pen);
                g.setColor(Color.magenta);
                g.drawRect(20, 20, 100, 100);
                break;
            case Скруглённый_прямоугольник:
                float[] dash3 = { 20, 20, 2, 20, 2, 20 };
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash3, 0);
                g.setStroke(pen);
                g.setColor(Color.yellow);
                g.drawRoundRect(20, 20, 100, 100, 60, 60);
                break;
            case Фамилию:
                //Ш                
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1);
                g.setStroke(pen);

                g.setColor(Color.getHSBColor(0.5f, 1f, 1f));
                g.drawArc(45, 50, 15, 15, 0, 180);
                
                g.setColor(Color.getHSBColor(0.53f, 1f, 1f));
                g.drawArc(20, 40, 40, 40, 180, 180);

                g.setColor(Color.getHSBColor(0.56f, 1f, 1f));
                g.drawArc(20, 20, 75, 75, -30, 210);
                
                g.setColor(Color.getHSBColor(0.59f, 1f, 1f));
                g.drawLine(87, 80,40, 150);

                g.setColor(Color.getHSBColor(0.62f, 1f, 1f));
                g.drawArc(36, 140, 50, 50, 150, 120);

                g.setColor(Color.getHSBColor(0.65f, 1f, 1f));
                g.drawLine(60, 190, 80, 190);
                
                float[] dash4 = { 10, 15, 10, 15, 1 , 15};
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash4, 10f);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(0.68f, 1f, 1f));
                g.drawLine(80, 190,155, 80);
                
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(0.71f, 1f, 1f));
                g.drawLine(80, 190,135, 190);

                g.setColor(Color.getHSBColor(0.74f, 1f, 1f));
                g.drawArc(105, 140, 50, 50, -90, 60);
                
                g.setColor(Color.getHSBColor(0.77f, 1f, 1f));
                g.drawLine(153, 175,220, 80);

                g.setColor(Color.getHSBColor(0.8f, 1f, 1f));
                g.drawArc(155, 162, 30, 30, 130, 220);

                //е
                g.drawLine(203, 165, 213, 150);               

                g.setColor(Color.getHSBColor(0.83f, 1f, 1f));
                g.drawArc(203, 150, 50, 40, 160, 170);
                g.drawArc(210, 140, 50, 40, 20, 120);

                g.setColor(Color.getHSBColor(0.86f, 1f, 1f));
                g.drawArc(212, 145, 45, 20, 180, 180);
                
                //м
                g.setColor(Color.getHSBColor(0.89f, 1f, 1f));
                g.drawArc(273, 170, 20, 20, 160, 180);

                g.setColor(Color.getHSBColor(0.92f, 1f, 1f));
                g.drawLine(291, 185, 320, 145);
                
                g.setColor(Color.getHSBColor(0.95f, 1f, 1f));
                g.drawLine(322, 142, 322, 190);
                
                float[] dash5 = { 1, 15 };
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash5, 0);
                g.setStroke(pen);

                g.setColor(Color.getHSBColor(0.98f, 1f, 1f));
                g.drawLine(322, 190, 357, 145);

                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND, 1);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(1f, 1f, 1f));
                g.drawLine(359, 145, 359, 180);

                g.setColor(Color.getHSBColor(0.03f, 1f, 1f));
                g.drawArc(359, 170, 20, 20, 160, 180);
                
                //а
                g.setColor(Color.getHSBColor(0.03f, 1f, 1f));
                g.drawLine(403, 165, 413, 150);               

                g.setColor(Color.getHSBColor(0.06f, 1f, 1f));
                g.drawArc(403, 150, 40, 40, 170, 130);
                g.drawArc(410, 140, 50, 50, 20, 120);
                
                g.setColor(Color.getHSBColor(0.09f, 1f, 1f));
                g.drawLine(762-325, 185, 448, 175);
                
                g.setColor(Color.getHSBColor(0.12f, 1f, 1f));
                g.drawLine(448, 175, 475, 140);

                g.setColor(Color.getHSBColor(0.15f, 1f, 1f));
                g.drawArc(448, 170, 20, 20, 150, 180);

                //р
                float[] dash6 = { 10, 15, 30, 15, 1, 15, 30, 15, 10, 15, 1, 15};
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash6, 50);
                g.setStroke(pen);

                g.setColor(Color.getHSBColor(0.16f, 1f, 1f));
                g.drawLine(440, 260, 540, 130);

                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(0.19f, 1f, 1f));
                g.drawArc(525, 140, 38, 20, -25, 160);

                g.setColor(Color.getHSBColor(0.22f, 1f, 1f));
                g.drawLine(548, 170, 561, 155);
                
                g.setColor(Color.getHSBColor(0.25f, 1f, 1f));
                g.drawArc(543, 170, 20, 20, 130, 180);

                //е
                g.setColor(Color.getHSBColor(0.28f, 1f, 1f));
                g.drawArc(585, 150, 40, 40, 120, 200);
                
                g.setColor(Color.getHSBColor(0.4f, 1f, 1f));
                g.drawArc(600, 135, 25, 25, 0, 270);

                //в
                g.drawOval(655, 140, 50, 50);

                float[] dash7 = { 1, 15, 30, 15 };
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash7, 25);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(0.43f, 1f, 1f));
                g.drawArc(650, 50, 350, 300, 115, 45);

                g.setColor(Color.getHSBColor(0.46f, 1f, 1f));
                g.drawArc(740, 62, 50, 40, -40, 160);
                
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1);
                g.setStroke(pen);
                g.setColor(Color.getHSBColor(0.49f, 1f, 1f));
                g.drawArc(528, -119, 300, 250, -145, 100);

                g.setColor(Color.getHSBColor(0.51f, 1f, 1f));
                g.drawArc(548, 33, 50, 50, 20, 200);

                g.setColor(Color.getHSBColor(0.53f, 1f, 1f));
                g.drawArc(577, 43, 20, 20, 180, 180);

                //а
                g.setColor(Color.getHSBColor(0.49f, 1f, 1f));        
                g.drawArc(730, 170, 20, 20, 160, 180);
                
                g.setColor(Color.getHSBColor(0.52f, 1f, 1f));
                g.drawLine(751, 180, 780, 140);
                
                g.setColor(Color.getHSBColor(0.55f, 1f, 1f));
                g.drawLine(780, 140, 780, 180);

                g.setColor(Color.getHSBColor(0.58f, 1f, 1f));
                g.drawArc(780, 170, 20, 20, 160, 180);

                g.setColor(Color.getHSBColor(0.61f, 1f, 1f));
                g.drawLine(758, 170, 780, 170);

                break;
            case Очистить:
                g.clearRect(0, 0, getSize().width, getSize().height);
                break;
        }
    }
}
import java.awt.*;
import java.awt.geom.*;

import javax.swing.JPanel;

public class MyPanel extends JPanel {
    public static enum Figure {
        Line, Oval, Rectangle, Rounded_rectangle, Surname, Clear_all
    };

    private Figure vibor = Figure.Clear_all;

    public MyPanel() {
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
            case Line:
                pen = new BasicStroke(20, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
                g.setStroke(pen);
                g.setColor(Color.blue);
                g.drawLine(20, 20, 100, 100);
                break;
            case Oval:
                float[] dash = { 10, 30 };
                pen = new BasicStroke(10, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_ROUND, 10, dash, 0);
                g.setStroke(pen);
                g.setColor(Color.red);
                g.setPaint(new GradientPaint(30, 30, Color.red, 50, 50, Color.green, true));
                g.fill(new Ellipse2D.Double(20, 20, 100, 100));
                break;
            case Rectangle:
                float[] dash2 = { 20, 20 };
                pen = new BasicStroke(5, BasicStroke.CAP_SQUARE, BasicStroke.JOIN_BEVEL, 1, dash2, 0);
                g.setStroke(pen);
                g.setColor(Color.magenta);
                g.drawRect(20, 20, 100, 100);
                break;
            case Rounded_rectangle:
                float[] dash3 = { 20, 20, 2, 20, 2, 20 };
                pen = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL, 1, dash3, 0);
                g.setStroke(pen);
                g.setColor(Color.yellow);
                g.drawRoundRect(20, 20, 100, 100, 60, 60);
                break;
            case Surname:
                g.setPaint(new GradientPaint(0, 45,Color.getHSBColor(0.85f, 1, 0.5f), 50, 90, Color.getHSBColor(0.75f, 0.5f, 0.5f), true));

                g.fillRect(0, 20, 20, 100);
                
                g.fillPolygon(new int[] {40, 80, 40}, new int[] {40, 120, 120}, 3);
                g.fillPolygon(new int[] {55, 125, 90}, new int[] {20, 20, 90}, 3);
                g.fillPolygon(new int[] {140, 140, 100}, new int[] {40, 120, 120}, 3);
                
                g.fillRect(160, 20, 20, 100);

                g.fillRect(200, 40, 60, 20);
                g.fillRect(200, 80, 60, 20);

                g.fillRect(260, 20, 20, 100);
                
                g.fillRect(300, 40, 60, 20);
                g.fillRect(340, 60, 20, 20);
                g.fillRect(300, 80, 60, 40);
                
                g.fillRect(360, 20, 20, 100);
                
                g.fillRect(380, 40, 40, 80);
                g.fillRect(440, 40, 40, 80);
                
                g.fillPolygon(new int[] {480, 520, 480}, new int[] {20, 20, 120}, 3);
                g.fillPolygon(new int[] {540, 550, 530}, new int[] {40, 60, 60}, 3);
                g.fillPolygon(new int[] {523, 558, 575, 505}, new int[] {80, 80, 120, 120}, 4);
                g.fillPolygon(new int[] {560, 600, 600}, new int[] {20, 20, 120}, 3);
                
                g.fillRect(600, 20, 20, 100);

                g.fillRect(640, 20, 60, 40);
                g.fillRect(640, 80, 60, 40);
                
                g.fillRect(720, 20, 20, 100);

                break;
            case Clear_all:
                g.clearRect(0, 0, getSize().width, getSize().height);
                break;
        }
    }
}
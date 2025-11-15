import javax.swing.*;
import java.awt.*;

public class LAB_3 {
    public static void main(String[] args) throws Exception {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("주사위 채우기");

        int rowNum = (int) ((Math.random() * 10 + 1));
        int colNum = (int) ((Math.random() * 10 + 1));
        int btnCount = rowNum * colNum;
        Color[] colorAry = {null, Color.RED, Color.GREEN, Color.BLUE, Color.YELLOW, Color.MAGENTA, Color.ORANGE};

        frame.setLayout(new GridLayout(rowNum, colNum, 5, 5));
        JButton[] btn = new JButton[btnCount];

        for (int i = 0; i < btnCount; i++) {
            int diceNum = (int) ((Math.random() * 6 + 1));
            btn[i] = new JButton(Integer.toString(diceNum));
            btn[i].setBackground(colorAry[diceNum]);
            frame.add(btn[i]);
        }

        frame.setSize(500, 500);
        frame.setVisible(true);
    }
}

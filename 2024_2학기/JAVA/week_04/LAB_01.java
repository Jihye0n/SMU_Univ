// 뜀뛰기하는 토끼

import java.util.Scanner;

class Rabbits {
    String shape;
    int xPos;
    int yPos;

    void setPosition(int x, int y) {
        xPos = x;
        yPos = y;
    }
}

public class LAB_1 {
    public static void main (String[] args) {
        Scanner s = new Scanner(System.in);

        Rabbits rabbit;
        int userX, userY;

        rabbit = new Rabbits();
        rabbit.shape = "토끼";

        while (true) {
            System.out.print("토끼가 이동할 X좌표 ==> ");
            userX = s.nextInt();
            System.out.print("토끼가 이동할 Y좌표 ==> ");
            userY = s.nextInt();

            rabbit.setPosition(userX, userY);
            System.out.printf("** 토끼의 현재 위치는 (%d, %d)입니다. \n", userX, userY);
        }

    }

}


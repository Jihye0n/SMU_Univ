// 같은 숫자가 나올 때까지 주사위 던지기(객체지향 버전)

class Dice {
    private int number;

    public void setNumber(int number) {
        this.number = number;
    }

    public int getNumber() {
        return this.number;
    }
}

public class LAB_2 {
    public static void main (String[] args) {
        int count = 0;
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();
        Dice dice3 = new Dice();

        while (true) {
            count++;

            dice1.setNumber((int) (Math.random()*6 + 1));
            dice2.setNumber((int) (Math.random()*6 + 1));
            dice3.setNumber((int) (Math.random()*6 + 1));
            break;
        }

        System.out.printf("3개 주사위는 모두 %d입니다. \n", dice1.getNumber());
        System.out.printf("같은 숫자가 나올 때까지 %d번 던졌습니다. \n", count);
    }
}

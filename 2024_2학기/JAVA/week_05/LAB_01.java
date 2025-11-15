// 자동차를 상속받은 스포츠카와 스쿨버스

import java.util.Scanner;

class Car {
    int speed = 0;

    void upSpeed(int value) {
        this.speed += value;
    }
}

// 속도 제한
class SchoolBus extends Car {
    void upSpeed(int value) {
        this.speed += value;
        if (this.speed > 60)
            this.speed = 60;
    }
}

// 속도 제한이 없다. (슈퍼클래스와 동일한 기능을 가지고 있다.)
class SportsCar extends Car {

}

public class LAB_1 {
    public static void main (String[] args) {
        Scanner sc =new Scanner(System.in);

        int axel;
        SchoolBus bus = new SchoolBus();
        SportsCar car = new SportsCar();

        while (true) {
             System.out.print("가속할 속도 ==> ");
             axel = sc.nextInt();

             if(axel == 0) {
                 break;
             }

             bus.upSpeed(axel);
             car.upSpeed(axel);

             System.out.printf("** 스쿨버스의 현재 속도 : %d \n", bus.speed);
             System.out.printf("** 스포츠카의 현재 속도 : %d \n", car.speed);
        }

        sc.close();
    }
}

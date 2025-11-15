// PC방 이용자의 나의 검사하기

import java.util.Scanner;

public class LAB_3 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        byte age;

        System.out.print("나이 입력 ==> ");
        age = sc.nextByte();

        if(age >= 20) {
            System.out.println("즐거운 시간 보내세요.^^");
            System.out.println("협조 감사합니다.");
        } else {
            System.out.println("청소년은 밤 10시 이후 이용 하실 수 없습니다.");
        }
    }
}

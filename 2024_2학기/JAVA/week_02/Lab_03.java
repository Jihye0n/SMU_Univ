import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double pound, kg;
        System.out.print("파운드(1b)를 입력하세요 : ");
        pound = s.nextDouble();
        kg = pound * 0.453592;
        System.out.println(pound + "파운드(1b)는 " + kg + "킬로그램(kg)입니다.");

        System.out.print("킬로그램(kg)을 입력하세요 : ");
        kg = s.nextDouble();
        pound = kg * 2.204623;
        System.out.println(kg + "킬로그램(kg)은 " + pound + "파운드(1b)입니다.");
        s.close();
    }
}


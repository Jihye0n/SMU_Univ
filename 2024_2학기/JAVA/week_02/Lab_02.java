import java.util.Scanner;

public class Lab2_2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("정수1 ==> ");
        int num1 = s.nextInt();

        System.out.print("정수2 ==> ");
        int num2 = s.nextInt();

        int add = num1 + num2;
        System.out.println(num1 + "+" + num2 + "=" + add);

        int sub = num1 - num2;
        System.out.println(num1 + "-" + num2 + "=" + sub);

        int mult = num1 * num2;
        System.out.println(num1 + "*" + num2 + "=" + mult);

        double div = (double) num1 / num2;
        System.out.printf(num1 + "/" + num2 + "= %.2f%n",div);

        int res = num1 % num2;
        System.out.println(num1 + "%" + num2 + "=" + res);

        s.close();

    }
}

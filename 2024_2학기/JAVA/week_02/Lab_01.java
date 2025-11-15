import java.util.Scanner;

public class Lab2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("## 택배 보내기입니다. 다음을 각각 입력하세요 ##");
        
        System.out.print("받는 사람 : ");
        String name = s.nextLine();

        System.out.print("주소 : ");
        String address = s.nextLine();

        System.out.print("무게(g) : ");
        int weight = s.nextInt();
        
        System.out.println("** 받는 사람 ==>" + name);
        System.out.println("** 주소 ==>" + address);
        System.out.println("** 배송비 ==>" + weight * 5 + "원");
        s.close();
    }
}

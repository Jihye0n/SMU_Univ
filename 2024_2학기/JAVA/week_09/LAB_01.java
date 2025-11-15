import java.io.FileWriter;
import java.util.Scanner;

public class LAB_1 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        FileWriter fw = new FileWriter("./secure.txt");
        String inStr, secure;

        while (true) {
            System.out.print("스파이에게 전달할 메시지 ==> ");
            inStr = s.nextLine();
            if (inStr.equals(""))
                break;

            // 암호화
            secure = "";
            for (int i = 0; i < inStr.length(); i++) {
                int num = (int)inStr.charAt(i);
                num += 100;
                secure += (char)num;
            }

            // 복호화
            /*
            secure = "";
            for (int i = 0; i < inStr.length(); i++) {
                int num = (int)inStr.charAt(i);
                num -= 100;
                secure += (char)num;
            }
            */

            fw.write(secure + "\n");
        }

        fw.close();
        System.out.println("--- secure.txt 암호화 완료 ---");
    }
}

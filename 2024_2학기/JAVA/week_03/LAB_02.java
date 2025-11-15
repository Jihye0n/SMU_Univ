// 대 소문자 변환하기

public class LAB_2 {
    public static void main(String[] args) {
        String str = "Java";
        System.out.println("원본 문자열 ==>" + str );
        System.out.print("변환 문자열 ==>" );
        String newstr = "";

        newstr = str.substring(0,1).toLowerCase();
        newstr += str.substring(1,4).toUpperCase();
        System.out.print(newstr);
    }
}

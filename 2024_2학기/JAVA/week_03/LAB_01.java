// 문자열 거꾸로 출력하기

public class LAB_1 {
    public static void main(String[] args) {
        String str = "블랙핑크";
        System.out.println("원본 문자열 ==> " + str);
        System.out.print("반대 문자열 ==> ");

        System.out.print(str.charAt(3));
        System.out.print(str.charAt(2));
        System.out.print(str.charAt(1));
        System.out.print(str.charAt(0));
    }
}

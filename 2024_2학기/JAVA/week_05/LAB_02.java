// 오늘의 명언 출력하기

public class LAB_2 {
    public static void main (String[] args) {
        String[] wiseSay = {"삶이 있는 한 희망은 있다.", "언제나 현재에 집중할 수 있다면 행복할 것이다.",
                            "신은 용기 있는 자를 결코 버리지 않는다.", "피할 수 없으면 즐겨라."};

        int today = (int)(Math.random()*wiseSay.length);
        System.out.println("오늘의 명언 ==> " + wiseSay[today]);
    }
}

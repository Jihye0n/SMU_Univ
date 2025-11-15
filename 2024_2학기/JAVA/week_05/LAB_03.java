// 심사위원 점수 결과 구하기

import java.util.Scanner;

public class LAB_3 {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] score = new int[5];
        int hap = 0;
        double avg;

        System.out.println("김연아 선수 경기 끝났습니다. 짝짝짝");

        for (int i = 0; i < 5; i++) {
            System.out.print("평가 점수 ==> ");
            score[i] = sc.nextInt();
        }

        for (int i = 0; i < 5; i++) {
            hap += score[i];
        }
        avg = (double) hap / 5;

        System.out.printf("심사위원 평균 점수 : %5.2f", avg);
    }
}

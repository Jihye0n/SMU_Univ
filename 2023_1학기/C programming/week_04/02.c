// 프로그램 사용자로부터 시,분,초를 입력 받아서 초로 변환하여 출력하는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

int main() // 프로그램 시작 점
{
	int num = 0, hour = 0, min = 0, sec = 0, i = 0; // 정수형 메모리 num, hour, min, sec, i를 만들고 모두 0을 대입

	printf("시, 분, 초를 입력 : "); // "시, 분, 초를 입력 : "을 출력
	scanf_s("%d %d %d", &hour, &min, &sec); // 정수를 입력받아 첫번째 정수는 hour의 주소로 배달
	// 두번째 입력받은 정수는 min의 주소로 배달
	// 세번째 입력받은 정수는 sec의 주소로 배달

	num = (hour * 3600) + (min * 60) + sec; // hour의 값 곱하기 3600의 값과 min의 값 곱하기 60의 값을 더한 뒤, sec의 값까지 더하여 num에 대입
	printf("sec is %d \n", num); // num의 값을 출력
}
// 프로그램 사용자로부터 초를 입력 받아서 시,분,초로 변환하여 출력하는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	int num = 0, hour = 0, min = 0, sec = 0; // 정수형 메모리 num, hour, min, sec를 만들고, 모두 0으로 초기화

	printf("초를 입력 : "); // "초를 입력"을 출력
	scanf_s("%d", &num); // 입력받은 정수를 num 주소로 배달
	// printf("num is %d \n", num);

	hour = num / 3600; // hour에 3600 나누기 num의 값을 대입
	printf("hour is %d \n", hour); // "hour(시)"을 출력

	min = (num % 3600) / 60; // 3600 나누기 num을 했을 때의 나머지 값을 60으로 나누어 그 값을 min에 대입
	printf("min is %d \n", min); // "min(분)"을 출력

	sec = (num % 3600) % 60; // 3600 나누기 num을 했을 때의 나머지 값을 60으로 나누어 나온 나머지 값을 sec에 대입
	printf("sec is %d \n", sec); // "sec(초)"를 출력
}
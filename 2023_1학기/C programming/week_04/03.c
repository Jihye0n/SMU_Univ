// 프로그램 사용자로부터 시,분,초를 입력 받아 정상적으로 작동하는 디지털 시계

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <windows.h> // 프로그램 시작 전 윈도우 함수 포함

int main() // 프로그램 시작 점
{
	int num = 0, hour = 0, min = 0, sec = 0, i = 0; // 정수형 메모리 num, hour, min, sec, i를 만들고 모두 0을 대입

	printf("시, 분, 초를 입력 : "); // "시, 분, 초를 입력 : "을 출력
	scanf_s("%d %d %d", &hour, &min, &sec); // 정수를 입력받아 첫번째 정수는 hour의 주소로 배달
	// 두 번째 입력받은 정수는 min의 주소로 배달
	// 세 번째 입력받은 정수는 sec의 주소로 배달

	while (1) // 0외의 다른수 이기 때문에 무한 반복
	{
		sec = sec + 1; // sec에 1을 증가
		if (sec == 60) // sec의 값이 60과 같아지면
		{
			min = min + 1; // min에 1을 증가
			sec = 0; // sec의 값을 0으로 초기화
		}
		if (min == 60) // min의 값이 60과 같아지면
		{
			hour = hour + 1; // hour에 1을 증가
			min = 0; // min의 값을 0으로 초기화
		}
		if (hour == 24) // hour의 값이 24와 같아지면
			hour = 0; // hour의 값을 0으로 초기화
		printf("%02d: %02d : %02d \r", hour, min, sec); // hour의 값과 min의 값과 sec의 값을 출력
		Sleep(1000); // 1초 딜레이를 준다.
	}
}
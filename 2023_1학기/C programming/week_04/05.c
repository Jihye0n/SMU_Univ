// 프로그램 사용자로부터 년,월,일,시,분,초를 입력 받아 정상적으로 작동하는 디지털달력기능이 있는 디지털시계

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <windows.h> // 프로그램 시작 전 윈도우 함수 포함

int main() // 프로그램 시작점
{
	int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0, i = 0;
	// 정수형 메모리 year, month, day, hour, min, sec만들고 모두 0으로 초기화

	printf("년, 월, 일을 입력 : "); // "년, 월, 일을 입력 : "을 출력
	scanf_s("%d %d %d", &year, &month, &day); // 입력받은 첫 번째 정수는 year의 주소로 배달
	// 두 번째 입력받은 정수는 month의 주소로 배달
	// 세 번째 입력받은 정수는 day의 주소로 배달

	printf("시, 분, 초를 입력 : "); // "시, 분, 초를 입력 : "을 출력
	scanf_s("%d %d %d", &hour, &min, &sec); // 입력받은 첫 번째 정수는 hour의 주소로 배달
	// 두 번째 입력받은 정수는 min의 주소로 배달
	// 세 번째 입력받은 정수는 sec의 주소로 배달

	while (1) // 0외의 다른 수 이기 때문에 무한 반복
	{
		sec = sec + 1; // sec의 값에 1을 증가
		if (sec == 60) // sec의 값이 60과 같으면
		{
			min = min + 1; // min의 값에 1을 증가
			sec = 0; // sec의 값을 0으로 초기화
		}
		if (min == 60) // min의 값이 60과 같으면
		{
			hour = hour + 1; // hour의 값에 1을 증가
			min = 0; // min의 값을 0으로 초기화
		}
		if (hour == 24) // hour의 값이 24와 같으면
		{
			day = day + 1; // day의 값에 1을 증가
			hour = 0; // day의 값을 0으로 초기화
		}

		// 윤년 계산
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) // year의 값이 4로 나누어 떨어지면서 100으로 나누어 떨어지지 않거나 혹은 year의 값이 400으로 나누어 떨어질 때
		{
			if (month == 2) // month의 값이 2와 같으면서
			{
				if (day == 30) // day의 값이 30과 같으면
				{
					day = 1; // day의 값을 1로 초기화
					month = month + 1; // month의 값에 1을 증가
				}
			}
		}

		// 평년 계산
		if (month == 2 && year % 4 != 0 || (year % 4 == 0 && year % 100 == 0 && year % 400 != 0)) // month의 값이 2와 같으면서 year의 값을 4로 나누었을 때 나누어지지 않거나 혹은 year의 값을 4로 나누었을때 나누어 떨어지면서 100으로 나누었을때 나누어 떨어지면서 400으로 나누었을 때는 나누어 떨어지지 않으면
		{
			if (day == 29) // day의 값이 29와 같으면
			{
				day = 1; // day의 값을 1로 초기화
				month = month + 1; // month의 값에 1을 증가
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) // month의 값이 4 혹은 6 혹은 9 혹은 11과 같으면서
		{
			if (day == 31) // day의 값이 31과 같으면
			{
				day = 1; // day의 값을 1로 초기화
				month = month + 1; // month의 값에 1을 증가
			}
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) // month의 값이 1 혹은 3 혹은 5 혹은 7 혹은 8 혹은 10 혹은 12와 같으면서
		{
			if (day == 32) // day의 값이 32와 같으면
			{
				day = 1; // day의 값을 1로 초기화
				month = month + 1; // month의 값에 1을 증가
			}
		}
		if (month == 13) // month의 값이 13과 같으면
		{
			month = 1; // month의 값을 1로 초기화
			year = year + 1; // year의 값에 1을 증가
		}
		printf("%d-%d-%d %02d:%02d:%02d \r", year, month, day, hour, min, sec);// year, month, day, hour, min, sec의 값을 출력
		Sleep(1000); // 1초 딜레이를 준다.
	}
}
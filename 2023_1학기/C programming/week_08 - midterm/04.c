/* 
4 - 1.  프로그램 사용자로부터 현재시간 시, 분, 초 3개의 변수를 입력받아서 실제로 작동하는 디지털시계 프로그램을 작성하시오.
4 - 2. 프로그램 사용자로부터 알람시간 시, 분, 초 3개의 변수를 입력 받아서 알람 기능이 작동하는 프로그램을 작성하시오.
 1 ) 해당 알람 시간이 되면 알림메시지와 알림음을 출력하시오.
 2 ) 남은 시간을 시 : 분:초 형태로 표시되도록 처리하시오.
 3 ) 항상 동일한 위치에 시간이 표시되도록 처리하시오.
 
 디지털 시계 시간 설정(시, 분, 초) : 13 00 00
 알람 시간 설정(시, 분, 초) : 15 50 00
 현재시간 : 14 : 00 : 01, 알람시간 : 15 : 50 : 00, 남은시간 : 01 : 49 : 50
*/

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <windows.h> // 프로그램 시작 전 Sleep() 함수 포함

void main() // 프로그램 시작 점
{
	int hour = 0, min = 0, sec = 0, curTime = 0; // 정수형 메모리 hour, min, sec, curTime를 만들고 모두 0으로 초기화
	int ahour = 0, amin = 0, asec = 0, alTime = 0; // 정수형 메모리 ahour, amin, asec, alTime를 만들고 모두 0으로 초기화
	int rhour = 0, rmin = 0, rsec = 0, reTime = 0; // 정수형 메모리 rhour, rmin, rsec, reTime를 만들고 모두 0으로 초기화

	printf("디지털 시계 시간 설정(시, 분, 초) : "); // "디지털 시계 시간 설정(시, 분, 초) : "을 출력
	scanf_s("%d %d %d", &hour, &min, &sec); // 첫 번째 입력받은 정수를 hour의 메모리 주소로 배달, 두 번째 입력받은 정수를 min의 메모리 주소로 배달, 세 번째 입력받은 정수를 sec의 메모리 주소로 배달
	printf("알람 시간 설정(시, 분, 초) : "); // "알람 시간 설정(시, 분, 초) : "을 출력
	scanf_s("%d %d %d", &ahour, &amin, &asec); // 첫 번째 입력받은 정수를 ahour의 메모리 주소로 배달, 두 번째 입력받은 정수를 amin의 메모리 주소로 배달, 세 번째 입력받은 정수를 asec의 메모리 주소로 배달

	while (1) // 0 이외의 다른 수 이기 때문에 무한 반복
	{
		// 디지털 시계 만들기(4 - 1번 문제)
		sec = sec + 1; // sec의 값에 1을 증가
		if (sec == 60) // sec의 값이 60 이면
		{
			min = min + 1; // min의 값에 1을 증가
			sec = 0; // sec를 0으로 초기화
		}
		if (min == 60) // min의 값이 60 이면
		{
			hour = hour + 1; // hour의 값에 1을 증가
			min = 0; // min을 0으로 초기화
		}
		if (hour == 24) // hour의 값이 24 이면
			hour = 0; // hour을 0으로 초기화

		// 남은시간 구하기(4 - 2번 문제)
		curTime = hour * 3600 + min * 60 + sec; // curTime에 hour의 값 곱하기 3600 값과 min의 값 곱하기 60의 값과 sec의 값을 더하여 대입
		alTime = ahour * 3600 + amin * 60 + asec; // alTime에 ahour의 값 곱하기 3600 값과 amin의 값 곱하기 60의 값과 asec의 값을 더하여 대입
		reTime = alTime - curTime; // reTime에 alTime값 - curTime의 값을 대입

		// 알람기능 만들기(4 - 2번 문제)
		if (alTime - curTime <= 0) // alTime - curTime의 값이 0보다 작거나 0과 같으면
		{
			if (alTime - curTime == 0) // alTime - curTime의 값이 0 이라면
				printf("\a\a\a\a"); // 알람 울림
			printf("알람이 울립니다!"); // "알람이 울립니다!"를 출력
			rhour = 0; // rhour의 값 0으로 초기화
			rmin = 0; // rmin의 값 0으로 초기화
			rsec = 0; // rsec의 값 0으로 초기화
		}

		else // 아니라면
		{
			rhour = reTime / 3600; // rhour에 reTime의 값을 3600으로 나눈 몫을 대입
			rmin = (reTime % 3600) / 60; // rmin에 reTime의 값을 3600으로 나눈 나머지를 다시 60으로 나눈 몫을 대입
			rsec = (reTime % 3600) % 60; // rsec에 reTime의 값을 3600으로 나눈 나머지를 다시 60으로 나눈 나머지의 값을 대입
		}
		printf("현재 시간 : %02d:%02d:%02d, 알람 시간 : %02d:%02d:%02d, 남은시간 : %02d:%02d:%02d\r", hour, min, sec, ahour, amin, asec, rhour, rmin, rsec); // hour, min, sec, ahour, amin, asec, rhour, rmin, rsec 의 값을 출력
		Sleep(1000); // 딜레이
	}
}
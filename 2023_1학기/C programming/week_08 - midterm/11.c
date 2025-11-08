// (보너스 문제) 프로그램 사용자로부터 1 ~ 9 사이의 숫자 3개를 입력받고 야구게임을 진행하는 프로그램을 작성하시오. 단 프로그램 진행 조건은 프로그래머가 기술하고 설정하여 작성하시오.

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <stdlib.h> // 프로그램 시작 전 rand() 함수 포함

void main() // 프로그램 시작 점
{
	int com[3] = { 0 }, usr[3] = { 0 }, i = 0, j = 0, t = 0, strike = 0, count = 0, ball = 0; // 정수형 메모리 com 3개, usr 3개, i, j, t, strike, count, ball을 만들고 모두 0으로 초기화
	// { 0 } -> 0을 하나만 쓰면 나머지는 0로 채워짐
	printf("야구 게임입니다. \n"); // "야구 게임입니다."를 출력
	printf("랜덤으로 세개의 숫자가 생성되었습니다. \ n"); // "세개의 숫자가 생성되었습니다."를 출력
	printf("\n"); // 다음줄
	printf("1에서 9까지 3개의 숫자를 입력하시오. (기회는 10번) \ n"); // "1부터 9까지의 숫자를 입력하시오. (기회는 열번)"을 출력

	srand(time(NULL)); // srand에 time(NULL)를 넣어줌으로써 시간(초)이 대입되어 rand의 시드가 계속 바뀐다.
	// printf("t is %d \n", t);

	// 3개의 숫자 랜덤으로 생성
	for (i = 0; i < 3; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복문 종료
	{
		com[i] = rand() % 9 + 1; // 1에서 9까지의 랜덤숫자를 num[i]번째에 대입
		for (j = 0; j < i; j = j + 1) // j에 0을 대입하고 1씩 증가하면서 반복하다가 i가 되면 반복문 종료
		{
			// 중복 숫자 확인
			if (com[i] == com[j]) // 중복 숫자가 있다면
			{
				// printf("same number %d\n", com[i]);
				com[i] = rand() % 9 + 1; // 1에서 9까지의 랜덤숫자를 num[i]번째에 대입
				j = j - 1; // j에 1을 감소
			}
		}
	}
	// for (i = 0; i < 3; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복문 종료
	// printf("%d \n", com[i]); // num[i]값을 출력

	while (1) // 0외의 다른 수 이기 때문에 무한 반복
	{
		// 숫자 입력받기
		for (j = 0; j < 3; j = j + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
		{
			printf("입력 : "); // "입력 : "을 출력
			scanf_s("%d", &usr[j]); // 정수를 입력받아 usr의 j번째 메모리 주소로 배달
		}
		count = count + 1; // count에 1을 증가
		// printf("count is %d \n", count);

		// 열번 입력할 때
		if (count == 10) // count의 값이 10이면
		{
			printf("10번이 넘었습니다. 다음에 다시 도전하세요."); // "10번이 넘었습니다. 다음에 다시 도전하세요."를 출력
			break; // while 반복문에서 빠져나옴
		}

		// 잘못된 숫자 입력
		if (usr[0] == 0 || usr[0] > 9 || usr[1] == 0 || usr[1] > 9 || usr[2] == 0 || usr[2] > 9) // usr의 값이 0이거나 9를 넘을 경우
		{
			printf("1부터 9까지의 숫자가 아닙니다. 다시 입력하세요. \ n"); // "1부터 9까지의 숫자가 아닙니다. 다시 입력하세요."를 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 중복된 숫자 입력
		if (usr[0] == usr[1] || usr[0] == usr[2] || usr[1] == usr[2]) // 중복 숫자 제외
		{
			printf("중복된 숫자는 게임을 진행할 수 없습니다. 다시 입력하세요. \ n"); // "중복된 숫자는 게임을 진행할 수 없습니다. 다시 입력하세요."를 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 숫자와 숫자의 위치 비교
		for (i = 0; i < 3; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
		{
			for (j = 0; j < 3; j = j + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
			{
				if (com[i] == usr[j]) // com의 값과 usr의 값이 같으면서
				{
					if (i == j) // com의 위치와 usr의 위치가 같으면
						strike = strike + 1; // strike에 1을 증가
					else // 위치가 다르면
						ball = ball + 1; // ball에 1을 증가
				}
			}
			// printf("com is %d, usr is %d", com[i], usr[i]);
		}
		printf("strike is %d , ball is %d \n", strike, ball); // strike와 ball의 값 출력

		// 볼
		if (ball < 4) // ball의 값이 4 미만이면
			ball = 0; // ball의 값을 초기화

		// 스트라이크
		if (strike < 3) // strike의 값이 3 미만이면
			strike = 0; // strike의 값을 초기화

		if (strike == 3) // strike의 값이 3이면
		{
			printf("축하합니다. 스트라이크입니다. \n"); // "축하합니다. 스트라이크입니다."를 출력
			printf("%d번 만에 맞추셨습니다. \n", count); // count의 값 출력
			break; // while 반복문에서 빠져나옴
		}
	}
}
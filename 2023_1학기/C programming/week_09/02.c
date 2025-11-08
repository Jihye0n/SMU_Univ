// 입력 받은 성적을 오름차순, 내림차순 정렬하여 화면에 출력하는 프로그램

# include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
// 데이터가 10개 있으면 9패스 돌림

void main() // 프로그램 시작 점
{
	int score[10] = { 0 }, i = 0, j = 0, temp = 0, od = 0; // 정수형 메모리 score 10개를 만들고 i, j, temp, od를 만들고 모두 0으로 초기화

	// 성적 입력 받기
	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 i에 1씩 증가하면서 9까지 반복
	{
		printf("성적 입력 : "); // "성적 입력 : "을 출력
		scanf_s("%d", &score[i]); // 입력받은 정수를 score의 i번째 메모리 주소로 배달
	}

	// 오름차순, 내림차순 입력 받기
	printf("오름차순은 1번, 내림차순은 2번을 선택해주세요 : "); // "오름차순은 1번, 내림차순은 2번을 선택해주세요 : "를 출력
	scanf_s("%d", &od); // 입력받은 정수를 od의 메모리 주소로 배달

	for (j = 0; j < 10 - 1; j = j + 1) // j에 0을 대입하고 j에 1씩 증가하면서 반복하다가 10 - 1 이 되면 반복문 종료
	{
		for (i = 0; i < (10 - 1 - j); i = i + 1) // i에 0을 대입하고 i에 1씩 증가하면서 반복하다가 10 - 1 - i 가 되면 반복문 종료
		{
			// printf("%d\n", score[i]);

			// 오름차순 구하기
			if (od == 1 && score[i] > score[i + 1]) // od의 값이 1 이면서 score[i]의 값이 score[i + 1]의 값보다 클다면
			{
				temp = score[i]; // temp에 score[i]의 값 대입
				score[i] = score[i + 1]; // score[i]에 score[i + 1]의 값 대입
				score[i + 1] = temp; // score[i + 1]에 temp의 값 대입
			}

			// 내림차순 구하기
			if (od == 2 && score[i] < score[i + 1]) // od의 값이 2 이면서 score[i]의 값이 score[i + 1]의 값보다 작다면
			{
				temp = score[i]; // temp에 score[i]의 값 대입
				score[i] = score[i + 1]; // score[i]에 score[i + 1]의 값 대입
				score[i + 1] = temp; // score[i + 1]에 temp의 값 대입
			}
		}
	}
	// 성적 출력
	for (i = 0; i < 10; i = i + 1) // i에 0을 대입 i에 1씩 증가하면서 반복하다가 10이 되면 반복문 종료
		printf("%d ", score[i]); // score[i]의 값 출력
}
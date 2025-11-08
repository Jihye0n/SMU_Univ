// 프로그램 사용자로부터 10명의 C프로그램 중간고사 성적을 입력 받아서 총합과 평균을 출력하는 프로그램

# include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	int score[10] = { 0 }, sum = 0, i = 0; // 정수형 메모리 score 10개와 sum, i를 만들고 모두 0으로 초기화
	// score : 0의값이 0번메모리에 들어가고 나머지는 자동으로 0으로 채워짐
	double avg = 0; // 실수형 메모리 avg를 만들고 0으로 초기화

	// 성적 입력 받기
	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 i에 1씩 증가하면서 9까지 반복
	{
		printf("성적 입력 : "); // "성적 입력 : "을 출력
		scanf_s("%d", &score[i]); // 입력받은 정수를 score의 i번째 메모리 주소로 배달
		sum = sum + score[i]; // sum에 score[i]값을 더하여 대입
	}

	// 평균 구하기
	avg = (double)sum / 10; // 계산할때만 sum을 소수로 강제 형변환을 하여 10으로 나누고 avg에 대입
	printf("총합 : %d, 평균 : %f", sum, avg); // sum, avg값을 출력
}
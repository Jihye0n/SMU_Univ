// 사용자로부터 하나의 숫자를 입력 받아 이 숫자가 소수인지 아닌지 판단하는 프로그램 (소수 : 1과 자기자신으로만 나눠지는 숫자)

#include <stdio.h> // 프로그램 시작전 표준 입출력 함수 포함

void main() // 프로그램 시작
{
	int num = 0, i = 0, count = 0; // 정수형 메모리 num, i, count를 만들고 0을 대입

	printf("정수 하나 입력 : "); // "정수 하나 입력 : " 을 출력
	scanf_s("%d", &num); // 키보드로 부터 %d에 정수를 받아서 num의 주소로 배달

	for (i = 1; i <= num; i = i + 1) // (1) i에 1을 대입 -> (2) i가 num의 값에 이하일 때 까지 반복 -> (4) i에 1을 증가
	{
		if (num % i == 0) // (3) num의 값을 i의 값으로 나누었을때 나누어 떨어진다면 
		{
			count = count + 1; // true일 경우 count의 값에 1을 증가
			printf("num is %d \n", i); // true일 경우 출력
		}
	}

	printf("count is %d \n", count); // count값 출력	
	if (count == 2)
		printf("%d 숫자는 %d번 나누어 졌으니 소수 입니다. \n", num, count); // count의 값이 2일 때 출력
	else
		printf("%d 숫자는 %d번 나누어 졌으니 소수가 아닙니다. \n", num, count); // count의 값이 2가 아닐 때 출력
}
// 프로그램 사용자로부터 2개의 정수를 입력받아 두수 사이에 존재하는 모든 소수(prime number)와 합을 출력하는 프로그램을 작성하시오.

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작점
{
	int num1 = 0, num2 = 0, i = 0, j = 0, flag = 0, sum = 0, temp = 0; // 정수형 메모리 num1, num2, i, j, flag, sum, temp를 만들고 모두 0으로 초기화

	printf("2개의 정수 입력 : "); // "2개의 정수 입력 : "을 출력
	scanf_s("%d %d", &num1, &num2); // 첫 번째 입력 받은 정수는 num1의 메모리 주소로 배달, 두 번째 입력 받은 정수는 num2의 메모리 주소로 배달

	if (num1 > num2) // num1의 값이 num2의 값보다 크다면
	{
		temp = num1; // temp에 num1의 값 대입
		num1 = num2; // num1에 num2의 값 대입
		num2 = temp; // num2에 temp의 값 대입
	}
	// printf("%d %d", num1, num2);

	// 소수와 소수의 합 구하기
	for (i = num1; i <= num2; i = i + 1) // i에 num1의 값을 대입하고 1씩 증가하면서 반복하다가 num2의 값보다 크면 반복문 종료
	{
		for (j = 1; j <= i; j = j + 1) // j에 1을 대입하고 1씩 증가하면서 반복하다가 i의 값보다 크면 반복문 종료
		{
			if (i % j == 0) // i 나누기 j 했을 때 나머지의 값이 0 이면
				flag = flag + 1; // flag에 1을 증가
			if (flag > 2) // flag가 2보다 크면
				break; // 반복 종료
		}
		if (flag == 2) // flag의 값이 2와 같으면
		{
			printf("%d is 소수 \n", i); // i의 값 출력
			sum = sum + i; // sum에 i값을 증가
		}
		flag = 0; // flag를 0으로 초기화
	}
	printf("소수의 합 : %d", sum); // sum의 값 출력
}
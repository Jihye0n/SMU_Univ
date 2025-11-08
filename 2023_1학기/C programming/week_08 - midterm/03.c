// 프로그램 사용자로부터 3개의 정수를 입력받아 최대공약수와 최소공배수를 계산하여 출력하는 프로그램을 작성하시오.

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	int num1 = 0, num2 = 0, num3 = 0, i = 0, gcd = 0, lcm = 0, temp = 0; // 정수형 메모리 num1, num2, num3, i, gcd, lcm을 만들고 모두 0으로 초기화

	printf("3개의 정수 입력 : "); // "3개의 정수 입력 : "를 출력
	scanf_s("%d %d %d", &num1, &num2, &num3); // 첫 번째 입력 받은 정수는 num1의 메모리 주소로 배달, 두 번째 입력 받은 정수는 num2의 메모리 주소로 배달, 세 번째 입력 받은 정수는 num3의 메모리 주소로 배달

	// num3가 제일 작은 수로 만들기(내림차순)
	if (num1 < num2) // num1의 값이 num2의 값 보다 작으면
	{
		temp = num2; // temp에 num2의 값 대입
		num2 = num1; // num2에 num1의 값 대입
		num1 = temp; // num1에 temp의 값 대입
	}
	if (num1 < num3) // num1의 값이 num3의 값 보다 작으면
	{
		temp = num3; // temp에 num3의 값 대입
		num3 = num1; // num3에 num1의 값 대입
		num1 = temp; // num1에 temp의 값 대입
	}
	if (num2 < num3) // num2의 값이 num3의 값 보다 작으면
	{
		temp = num3; // temp에 num3의 값 대입
		num3 = num2; // num3에 num2의 값 대입
		num2 = temp; // num2에 temp의 값 대입
	}
	// printf("%d %d %d", num1, num2, num3);

	// 최대공약수 구하기
	for (i = 1; i < num3; i = i + 1) // i에 1을 대입하고 1씩 증가하면서 num3의 값이 되면 반복문 종료
	{
		if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0) // num1, num2, num3를 각자 i로 나누었을때 나머지가 0 이면
		{
			gcd = i; // gcd에 i값을 대입
			// printf("gcd is %d \n", gcd);
		}
	}

	// 최소공배수 구하기
	for (i = 1; i <= num1 * num2 * num3; i = i + 1) // i에 1을 대입하고 1씩 증가하면서 반복하다가 num1 곱하기 num2 곱하기 num3 곱하기의 값이 되면 반복문 종료
	{
		if (i % num1 == 0 && i % num2 == 0 && i % num3 == 0) // i를 각자 num1, num2, num3로 나누었을때 나머지가 0 이면
		{
			lcm = i; // lcm에 i값을 대입
			break; // 반복문 종료
		}
	}

	printf("gcd is %d, lcm is %d \n", gcd, lcm); // gcd, lcm의 값 출력
}
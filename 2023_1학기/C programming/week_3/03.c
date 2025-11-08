// 사용자로부터 숫자 두개를 입력 받아 두 수 사이의 존재하는 모든 약수를 찾아서 화면에 출력하는 프로그램

#include <stdio.h> // 프로그램 시작전 표준 입출력 함수 포함

void main() // 프로그램 시작점
{
	int num1 = 0, num2 = 0, i = 0, temp = 0, count = 0; // 정수형 메모리 num1, num2, i, temp(임시 메모리), count를 만들고
	// num1, num2, i, temp, count에 0을 대입				      
	printf("두 개의 정수 입력 : "); // "두 개의 정수 입력 : " 을 출력
	scanf_s("%d %d", &num1, &num2); // 첫 번째에 있는 %d에서 입력받은 정수를 num1의 주소로 배달
	// 두 번째에 있는 %d에서 입력받은 정수를 num2의 주소로 배달

	if (num1 > num2) // num1의 값이 num2의 값보다 클 때
	{
		temp = num1; // temp에 num1의 값을 대입
		num1 = num2; // num1에 num2의 값을 대입
		num2 = temp; // num2에 temp의 값을 대입
	}
	// printf("num1 = %d, num2 = %d \n", num1, num2);

	for (i = num1; i <= num2; i = i + 1) // (1) i에 num1의 값을 대입 -> (2) i가 num2의 값보다 이상이 될 때까지 반복 -> (4) i에 1을 증가
	{
		if (num2 % i == 0) // (3) num2의 값을 i로 나누었을 때 나누어 떨어진다면
		{
			count = count + 1; // count에 1을 증가
			printf("i is %d \n", i); // i의 값을 출력
		}
		// printf("count is %d \n", count); // count 값을 출력
	}
// 프로그램 사용자로부터 세 개의 정수를 입력 받아서 세 수의 최대공약수와 최소공배수를 구하는 프로그램 (3개를 받아서 min만)

#include <stdio.h> // 프로그램 시작전 표준 입출력 함수 포함

void main() // 프로그램 시작점
{
	int num1 = 0, num2 = 0, num3 = 0, i = 0, temp = 0, gcm = 0, lcm = 0;
	// 정수형 메모리 num1, num2, num3, i, temp, gcm, lcm 을 만들고
	// num1, num2, num3, i, temp, gcm(최대공약수), lcm(최소공배수) 에 0을 대입

	printf("세 개의 정수 입력 : "); // "세 개의 정수 입력 : " 을 출력
	scanf_s("%d %d %d", &num1, &num2, &num3);
	// 첫 번째에 있는 %d에서 입력받은 정수를 num1의 주소로 배달
	// 두 번째에 있는 %d에서 입력받은 정수를 num2의 주소로 배달
	// 세 번째에 있는 %d에서 입력받은 정수를 num3의 주소로 배달

	if (num1 > num2) // num1의 값이 num2의 값보다 클 때
	{
		temp = num1; // temp에 num1의 값을 대입
		num1 = num2; // num1에 num2의 값을 대입
		num2 = temp; // num2에 temp의 값을 대입
	}
	if (num1 > num3) // num1의 값이 num3의 값보다 클 때
	{
		temp = num1; // temp에 num1의 값을 대입
		num1 = num3; // num1에 num3의 값을 대입
		num3 = temp; // num3에 temp의 값을 대입
	}
	if (num2 > num3) // num2의 값이 num3의 값보다 클 때
	{
		temp = num2; // temp에 num2의 값을 대입
		num2 = num3; // num2에 num3의 값을 대입
		num3 = temp; // num3에 temp의 값을 대입
	}
	// printf("num1=%d, num2=%d, num3=%d \n", num1, num2 num3);

	for (i = 1; i <= num1; i = i + 1) // (1) i에 1을 대입 -> (2) i가 num1의 값보다 이상이 될 때까지 반복 -> (4) i에 1을 증가
	{
		if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0) // (3) num1을 i로 나누어 떨어지면서 num2가 i로 나누어 떨어지고 num3도 i로 나누어 떨어지면
		{
			gcm = i; // gcm에 i를 대입
			printf("i is %d \n", i); // i의 값 출력
		}
	}
	printf("gcm is %d \n", gcm); // gcm의 값 출력

	lcm = (num1 / gcm) * (num2 / gcm) * (num3 / gcm) / gcm;
	printf("lcm is %d \n", lcm); // lcm의 값 출력
}
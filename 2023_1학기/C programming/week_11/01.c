// 프로그램 사용자로 부터 2명의 사람 이름을 입력 받아서 처리, 두 사람 이름의 대소 관계를 판별하는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <string.h> // 프로그램 시작 전 단어들에 활용할 수 있는 함수들 포함

void main() // 프로그램 시작 점
{
	char name1[10] = "", name2[10] = "", len = 0, result = 0; // 문자열 길이가 10개인 메모리를 name1과 name2를 만들고, len, result도 만들어 모두 0으로 초기화

	printf("첫번째 이름 입력 : "); // "첫번째 이름 입력 : "을 출력
	gets_s(&name1[0], 10); // 입력받은 문자열을 name1의 0번째 메모리 주소로 배달
	printf("두번째 이름 입력 : "); // "두번째 이름 입력 : "을 출력
	gets_s(&name2[0], 10); // 입력받은 문자열을 name2의 0번째 메모리 주소로 배달
	// gets - > 키보드로 부터 문자열을 입력받는 함수(특수목적용)
	// scanf는 엔터키와 공백을 받으면 종료(단어 입력받기 좋다), gets는 엔터키에서만 종료 (문장을 입력받기 좋다)

	// len = strlen(&name1[0]); // strlen의 함수 결과를 len에 대입

	result = strcmp(&name1[0], &name2[0]); // c컴파일러 안에 가지고 있는 함수 strcmp()를 사용하여 문자열을 비교한 뒤 result에 값을 대입

	if (result == 0) // result의 값이 0 과 같으면
	{
		printf("%s 와(과) %s 은(는) 같은 이름 입니다.", name1, name2); // name1과 name2의 값을 출력
	}
	else // result의 값이 0 이 아니라면
	{
		if (result > 0) // result의 값이 0 보다 크다면
		{
			printf("%s 보다 %s 이(가) 작습니다.", name1, name2); // name1과 name2의 값을 출력
		}
		else // result의 값이 0 보다 작다면
		{
			printf("%s 보다 %s 이(가) 큽니다.", name1, name2); // name1과 name2의 값을 출력
		}
	}

	// printf("1:%s, 2:%s , len :%d, result ; %d \n", &name1[0], &name2[0], len, result);
}
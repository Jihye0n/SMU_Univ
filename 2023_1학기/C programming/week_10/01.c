// 프로그램 사용자로부터 2개의 단어를 입력 받아서 두 단어의 같은지 큰지 작은지 판별해서 출력하는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	char name[2][10] = { "" }, result = 0, len1 = 0, len2 = 0; // 문자열 길이가 10개인 메모리를 2개 만들고, result, len1, len2도 만들어 모두 0으로 초기화

	printf("첫번째 사람 입력 : "); // "첫번째 사람 입력 : "을 출력
	gets(&name[0][0]); // 입력받은 문자열을 0번째 0번째의 주소로 배달, // 약어로 name[0] 도 쓰임
	printf("두번째 사람 입력 : "); // "두번째 사람 입력 : "을 출력
	gets(&name[1][0]); // 입력받은 문자열을 1번째 0번째의 주소로 배달 // 약어로 name[0] 도 쓰임
	// printf는 공백과 엔터키에 반응하고, gets는 엔터키에서만 반응한다.

	result = strcmp(name[0], name[1]); // c컴파일러 안에 가지고 있는 함수 strcmp()를 사용하여 문자열을 비교한 뒤 result에 값을 대입

	if (result == 0) // result의 값이 0 과 같으면
	{
		printf("%s 와(과) %s 은(는) 같은 이름 입니다.", name[0], name[1]); // name[0]과 name[1]의 값을 출력
	}
	else // result의 값이 0 이 아니라면
	{
		if (result > 0) // result의 값이 0 보다 크다면
		{
			printf("%s 보다 %s 이(가) 작습니다.", name[0], name[1]); // name[0]과 name[1]의 값을 출력
		}
		else // result의 값이 0 보다 작다면
		{
			printf("%s 보다 %s 이(가) 큽니다.", name[0], name[1]); // name[0]과 name[1]의 값을 출력
		}
	}

	/* len1 = strlen(name[0]);
	len2 = strlen(name[0]);
	printf("1:%d, 2:%d \n", len1, len2);

	printf("1:%s, 2:%s, result:%d \n", &name[0][0], &name[1][0], result);*/
}
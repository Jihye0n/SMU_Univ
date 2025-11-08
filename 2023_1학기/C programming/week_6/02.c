// 프로그램 사용자로 부터 길이 20글자 이내의 단어 2개를 입력받아 처리하는 프로그램

#include <stdio.h> // 프로그램시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	char word_1[21] = "", word_2[21] = "", i = 0, wordCnt_1 = 0, wordCnt_2 = 0, flag = 0; // 문자열 21개('\0'포함) word_1과 word_2를 만들고, i, wordCnt_1, wordCnt_2, flag를 만들어 모두 0으로 초기화
	printf("단어 입력 : "); // "단어 입력 : " 을 출력
	scanf_s("%s", &word_1[0], sizeof(word_1)); // 문자열을 입력받아서 word_1의 0번째 메모리 주소로 배달
	printf("단어 입력 : "); // "단어 입력 : " 을 출력
	scanf_s("%s", &word_2[0], sizeof(word_2)); // 문자열을 입력받아서 word_2의 0번째 메모리 주소로 배달

	// printf("%s \n", &word_1[0]);
	// printf("%s \n", &word_2[0]);

	// 첫번째 입력 단어 길이 구하기
	for (i = 0; i < 21; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 21이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word_1[i] == '\0') // (3) word_1의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wordCnt_1 = wordCnt_1 + 1; // wordCnt_1의 값에 1을 증가
	}

	// 두번째 입력 단어 길이 구하기
	for (i = 0; i < 21; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 21이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word_2[i] == '\0') // (3) word_2의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wordCnt_2 = wordCnt_2 + 1; // wordCnt_2의 값에 1을 증가
	}

	// 두 단어의 길이 비교
	if (wordCnt_1 == wordCnt_2) // wordCnt_1의 값과 wordCnt_2의 값이 같으면
	{
		for (i = 0; i < wordCnt_1; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 wordCnt_1의 값이랑 같아지게 되면 반복문 종료 -> (4) i의 값에 1을 증가
		{
			if (word_1[i] == word_2[i]) // (3) word_1의 i번째 있는 문자와 word_2의 i번째 있는 문자가 같으면
				flag = flag + 1; // flag의 값에 1을 증가
			else // 같지 않으면
				break; // 반복 종료
		}
		if (flag == wordCnt_1) // flag의 값과 wordCnt_1의 값이 같으면
			printf("두 단어는 같은 단어입니다."); // "두 단어는 같은 단어입니다."를 출력
		else // flag의 값과 wordCnt_1의 값이 같지 않으면
			printf("두 단어는 다른 단어입니다."); // "두 단어는 다른 단어입니다."를 출력
	}
	else // wordCnt_1의 값과 wordCnt_2의 값이 같지 않으면
		printf("두 단어는 다른 단어입니다."); // "두 단어는 다른 단어입니다."를 출력
}
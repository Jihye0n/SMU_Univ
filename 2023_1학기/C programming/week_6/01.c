// 프로그램 사용자로 부터 길이 20글이내의 단어를 입력받아서 처리하는 프로그램

#include <stdio.h> // 프로그램시작 전 표준 입출력 함수 포함
// #include <string.h>

void main() // 프로그램 시작 점
{
	char word[20] = "", i = 0, wordCnt = 0, flag = 0;// 문자열 20개 word를 만들고, i, wordCnt, flag 도 만들어 0으로 초기화
	printf("단어 입력 : "); // "단어 입력 : " 을 출력
	scanf_s("%s", &word[0], sizeof(word)); // 문자열을 입력받아서 word의 0번째 메모리 주소로 배달

	// 단어 길이 구하기
	for (i = 0; i < 20; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 20이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word[i] == '\0') // (3) word의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wordCnt = wordCnt + 1; // wordCnt의 값에 1을 증가
	}
	// wordCnt = strlen(&word[0]);

	printf("단어 : %s, 단어길이 : %d \n", &word[0], wordCnt); // word의 0번째 메모리부터의 문자와 wordCnt 값을 출력

	// 회문 판별
	for (i = 0; i < (wordCnt / 2); i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 wordCnt를 2로 나눈값이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word[i] == word[wordCnt - 1 - i]) // (3) word의 i번째에 있는 문자가 wordCnt-1-i 번째에 문자와 같으면
			flag = flag + 1; // flag의 값에 1을 증가
		else // 다르면
			break; // 반복 종료
	}
	// flag = strcmp(&word[0], &word[0]);

	if ((wordCnt / 2) == flag) // wordCnt를 2로 나눈 값이 flag의 값과 같으면
		printf("회문입니다."); // "회문입니다."를 출력
	else // 아닐경우
		printf("회문이 아닙니다."); // "회문이 아닙니다."를 출력

	// printf("flag is %d \n", flag);
}
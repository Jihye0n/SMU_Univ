// 프로그램 사용자로부터 1개의 영단어를 입력받아서 입력받은 단어의 길이와 해당 단어가 회문 단어인지 판단하는 프로그램을 작성하시오. 단 입력 가능한 영단어의 최대길이는 50글자까지입니다.

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	char word[50] = "", i = 0, wlen = 0, flag = 0; // 문자열 word 50개를 만들고, i, wlen, flag도 만들어 모두 0으로 초기화

	printf("영단어 입력 : "); // "영단어 입력 : " 을 출력
	scanf_s("%s", &word[0], sizeof(word)); // 문자열을 입력받아서 word의 0번째 메모리 주소로 배달

	// 단어 길이 구하기
	for (i = 0; i < 50; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 i의 값이 50이 되면 반복문 종료
	{
		if (word[i] == '\0') // word의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wlen = wlen + 1; // wlen의 값에 1을 증가
	}
	printf("word length is %d \n", wlen); // wlen의 값 출력

	// 회문 판별
	for (i = 0; i < (wlen / 2); i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 i의 값이 wlen을 2로 나눈값이 되면 반복문 종료
	{
		if (word[i] == word[wlen - 1 - i]) // word의 i번째에 있는 문자가 wlen - 1 - i번째에 문자와 같으면
			flag = flag + 1; // flag의 값에 1을 증가
		else // 다르면
			break; // 반복 종료
	}
	//printf("flag is %d \n", flag);

	if ((wlen / 2) == flag) // wlen을 2로 나눈 몫이 flag의 값과 같으면
		printf("회문입니다."); // "회문입니다."를 출력
	else // 아닐경우
		printf("회문이 아닙니다."); // "회문이 아닙니다."를 출력
}
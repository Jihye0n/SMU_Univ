// 프로그램 사용자로부터 파일명을 입력 받아 텍스트 파일에 존재하는 단어의 개수와 단어의 최대길이를 찾아서 화면에 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS // 안전하지 않아도 프로그램을 돌린다.
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	unsigned char fname[256] = "", word[256] = "", sname[256] = ""; // 문자열 메모리 fname, word, sname을 만들고 모두 0으로 초기화 // 파일글자는 256까지 지원
	int count = 0, max = 0, len = 0; // 정수형 메모리 count, max, len을 만들고 모두 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(&fname[0]); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	// printf("file name is %s \n", fname);

	// 파일 열기, // 파일접근 할 때 파일구조체변수 사용
	FILE* fp = fopen(fname, "rt"); //파일이 저장된 주소, fname의 파일을 read text모드로 열어서 fp에 대입
	FILE* fp_out = fopen(sname, "wt"); // sname의 파일을 write text모드로 열어서 파일을 생성하고 fp_out에 대입
	// "rt" 뿐만 아니라 "wt". "rb", "wb" 도 있다.

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한 반복
	{
		fscanf(fp, "%s", &word[0]); // fp파일에서 word의 0번째 주소를 받아온다.
		// printf("word is %s \n", word);
		// 단어의 길이 확인

		len = strlen(word); // word의 길이를 구해 len에 대입
		fprintf(fp_out, "%d : %s, %d \n", count, &word[0], len); // fp_out파일로 count, word[0], len의 값 들을 포함해서 출력* 파일에 출력된다*
			count = count + 1; // count에 1을 증가

		// 최대 길이 확인
		if (len > max) // len의 값이 max보다 크다면
			max = len; // max에 len의 값을 대입

		// fp가 끝인지 아닌지 확인
		if (feof(fp)) // fp가 끝이라면
			break; // 반복문 종료
	}

	// 단어의 개수와 최대 길이 확인
	printf("단어의 개수 : %d, 단어의 최대 길이 : %d \n", count, max); // count, max의 값을 출력

	// 파일 닫기
	fclose(fp); // fp 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

/*
접두어에 f가 붙어있으면 파일을 컨트롤 하는 함수
fopen(), fclose()
fscanf() // 파일에서 읽기 // 텍스트파일을 읽고 쓸때
fprintf() // 파일로 출력 // 텍스트파일을 읽고 쓸때
fread() // 실행파일을 읽고 쓸때(바이트 단위)
fwrite() // 실행파일을 읽고 쓸때(바이트 단위)
feof() // 파일에 끝은 (end of flie)이라는 기호가 들어가 있음,
*/
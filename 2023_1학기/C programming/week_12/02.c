// 파일에 존재하는 모든 단어를 컴퓨터 메모리로 이동하여 오름차순 정렬하여 파일에 저장하는 프로그램

#define _CRT_SECURE_NO_WARNINGS // 안전하지 않아도 프로그램을 돌린다.
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	unsigned char fname[256] = "", word[7657][17] = { "" }, sname[256] = "", data = 0, temp[17] = ""; // 문자열 메모리 fname, word, sname, data, temp를 만들고 모두 0으로 초기화
	int count = 0, i = 0, j = 0; // 정수형 메모리 count, i, j를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(&fname[0]); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	// printf("file name is %s \n", fname);

	// 파일 열기
	FILE* fp = fopen(fname, "rt"); //파일이 저장된 주소, fname의 파일을 read text모드로 열어서 fp에 대입
	FILE* fp_out = fopen(sname, "wt"); // sname의 파일을 write text모드로 열어서 파일을 생성하고 fp_out에 대입

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		fscanf(fp, "%s", &word[count][0]); // // fp파일에서 word[count]번째의 0번째 주소를 받아온다.
		count = count + 1; // count에 1을 증가

		// fp가 끝인지 아닌지 확인
		if (feof(fp)) // fp가 끝이라면
			break; // 반복문 종료
	}

	// 오름차순 정렬
	for (j = 0; j < count - 1; j++) // j에 0을 대입하고 1씩 증가하면서 (count - 1)의 값과 같아지면 반복문 종료
	{
		for (i = 0; i < count - j; i++) // i에 0을 대입하고 1씩 증가하면서 (count - j)의 값과 같아지면 반복문 종료
		{
			if (strcmp(word[i], word[i + 1]) > 0) // strcmp() 함수를 사용하여 word[i]와 word[i + 1]를 비교한 뒤 0 보다 크면
			{
				strcpy_s(temp, sizeof(word[i]), word[i]); // word[i]번 메모리에 있는 데이터를 temp에 복사
				strcpy_s(word[i], sizeof(word[i]), word[i + 1]); // word[i + 1]번 메모리에 있는 데이터를 word[i]번 메모리로 복사
				strcpy_s(word[i + 1], sizeof(word[i]), temp); // temp에 있는 데이터를 word[i + 1]번 메모리로 복사
			}
		}
	}

	// 오름차순으로 파일에 출력
	for (i = 0; i < count; i++) // i에 0을 대입하고 1씩 증가하면서 count와 같은 값이 되면 반복문 종료
		fprintf(fp_out, "%d:%s \n", i, word[i]); // fp_out파일로 i, word[i]의 값을 포함해서 출력

	// 파일 닫기
	fclose(fp); // fp 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}
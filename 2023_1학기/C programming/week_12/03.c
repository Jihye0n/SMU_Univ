// 프로그램 사용자로부터 파일명을 입력 받아 해당파일을 램섬웨어 암호화/복호화 하는 프로그램 ( 단, 프로그램 메뉴는 사용자 정의 함수를 이용 )

#define _CRT_SECURE_NO_WARNINGS // 안전하지 않아도 프로그램을 돌린다.
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

int menu() // int는 함수가 끝나고 반환되는 정수 1개의 값이 있다.
{
	int n = 0; // 지역변수이다. // 정수형 메모리 n을 만들고 0으로 초기화

	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("이 프로그램은 랜섬웨어 암호/복호화 프로그램입니다.\ n"); // "이 프로그램은 랜섬웨어 암호/복호화 프로그램입니다."를 출력
	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("1. 파일 암호화 \n"); // "1. 파일 암호화"를 출력
	printf("2. 파일 복호화 \n"); // "2. 파일 복호화"를 출력
	printf("3. 프로그램 종료 \n"); // "3. 프로그램 종료"를 출력
	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("메뉴를 선택하세요 : "); // "메뉴를 선택하세요 : "를 출력
	scanf("%d", &n); // 입력받은 정수가 n의 메모리 주소로 배달
	getchar(); // 엔터키가 여기로 들어간다
	return n; // n의 값이 menu로 들어간다
}
// 파라미터 패싱

void encrypt() // void는 함수가 끝나고 반환되는 값이 없다.
{
	unsigned char fname[256] = "", sname[256] = "", data = 0; // 문자열 메모리 fname, sname, data를 만들고 모두 0으로 초기화
	int key = 0; // 정수형 메모리 key를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(fname); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	printf("암호 키 값을 입력하세요 : "); // "암호 키 값을 입력하세요 : "를 출력
	scanf("%d", &key); // 입력받은 정수를 key의 메모리 주소로 배달

	FILE* fp_in = fopen(fname, "rb"); // 파일이 저장된 주소, fname의 파일을 read 바이너리 모드로 열어서 fp_in에 대입
	FILE* fp_out = fopen(sname, "wb"); // sname의 파일을 write 바이너리 모드로 열어서 파일을 생성하고 fp_out에 대입

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp_in == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		fread(&data, sizeof(char), 1, fp_in); // fp_in에서 1바이트[sizeof(char)] 하나를 읽어서 data에 배달
		data = data ^ key; // 암호화 처리
		// fp가 끝인지 아닌지 확인
		if (feof(fp_in)) // fp_in이 끝이라면
			break; // 반복문 종료
		fwrite(&data, sizeof(char), 1, fp_out); // data에 있는 1바이트[sizeof(char)] 하나를 fp_out에 쓴다
	}
	printf("%s ---> %s 파일로 암호화 처리되었습니다. \n", fname, sname); // 암호화 처리 안내문 출력

	// 파일 닫기
	fclose(fp_in); // fp_in 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

void decrypt()
{
	unsigned char fname[256] = "", sname[256] = "", data = 0; // 문자열 메모리 fname, sname, data를 만들고 모두 0으로 초기화
	int key = 0; // 정수형 메모리 key를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(fname); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	printf("암호 키 값을 입력하세요 : "); // "암호 키 값을 입력하세요 : "를 출력
	scanf("%d", &key); // 입력받은 정수를 key의 메모리 주소로 배달

	FILE* fp_in = fopen(fname, "rb"); // 파일이 저장된 주소, fname의 파일을 read 바이너리 모드로 열어서 fp_in에 대입
	FILE* fp_out = fopen(sname, "wb"); // sname의 파일을 write 바이너리 모드로 열어서 파일을 생성하고 fp_out에 대입

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp_in == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		fread(&data, sizeof(char), 1, fp_in); // fp_in에서 1바이트[sizeof(char)] 하나를 읽어서 data에 배달
		data = data ^ key; // 복호화 처리
		// fp가 끝인지 아닌지 확인
		if (feof(fp_in)) // fp_in이 끝이라면
			break; // 반복문 종료
		fwrite(&data, sizeof(char), 1, fp_out); // data에 있는 1바이트[sizeof(char)] 하나를 fp_out에 쓴다
	}
	printf("%s ---> %s 파일로 복호화 처리되었습니다. \n", fname, sname); // 복호화 처리 안내문 출력

	// 파일 닫기
	fclose(fp_in); // fp_in 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

void main() // 프로그램 시작 점
{
	int no = 0; // 정수형 메모리 no를 만들고 0으로 초기화
	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		no = menu(); // menu() 함수 호출하여 결과값을 no에 대입
		// printf("선택된 값은 : %d \n", no);
		if (no == 1) // no의 값이 1과 같다면
			encrypt(); // encrypt() 함수 호출
		if (no == 2) // no의 값이 2와 같다면
			decrypt(); // decrypt() 함수 호출
		if (no == 3) // no의 값이 3과 같다면
			break; // 반복문 종료
	}
}
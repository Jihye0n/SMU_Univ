// 단어를 맞출떄 마다 점수, 현재타수, 평균타수를 화면에 출력하는 프로그램
/*
 (word.txt파일의 모든 단어를 메모리로 이동, 이동된 단어중 5개를 랜덤하게 선택하여 화면에 표시. 
 5개의 단어중 하나를 맞추면 화면에서 지워지도록 하고, 5개의 단어를 모두 맞추면 새로운 단어 5개를 화면에 다시 표시 종료를 입력하면 프로그램을 종료)
*/

// 문장을 읽을때는 gets를 사용 단어를 읽을 때는 scanf를 사용
#define _CRT_SECURE_NO_WARNINGS // 안전하지 않아도 프로그램을 돌린다.
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <Windows.h> // 프로그램 시작 전 Sleep() 함수 포함
#include <stdlib.h> // 프로그램 시작 전 rand() 함수 포함

int menu() // int는 함수가 끝나고 반환되는 정수 1개의 값이 있다.
{
	int n = 0; // 지역변수이다. // 정수형 메모리 n을 만들고 0으로 초기화

	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("이 프로그램은 제가 만든 프로그램입니다.\ n"); // "이 프로그램은 제가 만든 프로그램입니다."를 출력
	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("1. 파일 암호화 \n"); // "1. 파일 암호화"를 출력
	printf("2. 파일 복호화 \n"); // "2. 파일 복호화"를 출력
	printf("3. 한글 단문 연습 프로그램 \n"); // "3. 한글 단문 연습 프로그램"을 출력
	printf("4. 한글 타자 연습 프로그램 \n"); // "4. 한글 타자 연습 프로그램"을 출력
	printf("5. 프로그램 종료 \n"); // "5. 프로그램 종료"를 출력
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
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력 gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
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

void decrypt() // void는 함수가 끝나고 반환되는 값이 없다.
{
	unsigned char fname[256] = "", sname[256] = "", data = 0; // 문자열 메모리 fname, sname, data를 만들고 모두 0으로 초기화
	int key = 0; // 정수형 메모리 key를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(fname); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력 gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
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

void short_test() // void는 함수가 끝나고 반환되는 값이 없다.
{
	// wordshort.txt 단문 길이 및 최대 길이 측정
	char wordDB[1261][77] = { "" }, ans[77] = ""; // 문자열 메모리 wordDB, ans를 만들고 모두 0으로 초기화
	int strCount = 0, max = 0, len = 0, choice = 0, score = 0, cur = 0, avg = 0, inputCnt = 0; // 정수형 메모리 strCount, max, len, choice, score, cur, avg, inputCnt를 만들고 모두 0으로 초기화
	unsigned int start_t = 0, end_t = 0, totalCur = 0; // 정수형 메모리 start_t, end_t, totalCur을 만들고 모두 0으로 초기화
	FILE* fp = fopen("wordshort.txt", "rt"); // 파일이 저장된 주소, wordshort.txt 파일을 read text모드로 열어서 fp에 대입

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		fgets(&wordDB[strCount][0], sizeof(wordDB[strCount]), fp); // fp가 가리키는 파일에서 한 줄씩 주소를 받아 온다.
		len = strlen(wordDB[strCount]); // 문자열(wordDB[strCount])의 길이를 측정해서 len에 대입

		// 마지막 앞에 엔터키가 들어가있어서 엔터키가 날려야 한다. ( fgets는 엔터키도 입력)
		wordDB[strCount][len - 1] = '\0'; // wordDB 마지막 문자 바로 앞에 '\0'을 대입
		// 최대값 구하기
		if (len > max) max = len; // len이 max보다 크다면 len을 max에 대입
		// printf("%s : %d, %d", wordDB[strCount], len, max);
		strCount++; // strCount에 1을 증가
		// getch();
		if (feof(fp)) break; // fp가 끝이라면 반복문 종료
	}
	// printf("strCount is %d, max length is %d \n", strCount, max);

	for (int i = 0; i < strCount; i++) // i에 0을 대입하고 1씩 증가하면서 strCount가 되면 반복 종료
	{
		printf("%s", wordDB[i]); // wordDB[i] 출력
	}
	fclose(fp); // fp 파일 닫기

	// 1261개 문장중 하나의 문장을 선택
	srand(time(NULL)); // 1970년 1월 1일 0시 0분 부터 현재까지의 시간(초)을 대입
	choice = rand() % strCount; // 1에서 1261까지의 랜덤숫자를 choice에 대입

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		system("cls"); // 화면 지우기
		printf("한글 단문 연습 프로그램입니다. 프로그램을 종료하시려면 \"종료\"를 입력하세요 \n"); // "한글 단문 연습 프로그램입니다. 프로그램을 종료하시려면 "종료"를 입력하세요"를 출력
		printf("점수 : %d, 현재 타수 : %d, 평균 타수 : %d \n", score, cur, avg); // score, cur, avg의 값을 출력
		printf("----------------------------------------- \n"); // "----------------------------------------- " 출력
		printf("%s \n", wordDB[choice]); // wordDB[choice] 출력

		// while (!kbhit()) {} // 키보드가 눌러지지 않으면 계속 무한루프, 키보드가 입력되면 1이 들어감
		start_t = time(NULL); // 시작시간
		gets(&ans[0]); // 입력
		end_t = time(NULL); // 종료시간
		len = strlen(ans); // ans의 길이를 측정해서 len에 대입

		inputCnt++; // inputCnt에 1씩 증가
		// printf("소요시간 %d, len is %d \n", end_t - start_t, len);
		// Sleep(1000);

		// printf("%d, %d \n", strlen(wordDB[choice]), strlen(ans));

		if (strcmp(ans, "종료") == 0) break; // 종료라고 넣으면 while문 빠져나간다.
		if (strcmp(ans, wordDB[choice]) == 0) // ans와 wordDB[choice] 비교했을 때 같으면
		{
			printf("정답입니다. \n"); // "정답입니다."를 출력
			choice = rand() % strCount; // 랜덤으로 문장 선택, 1에서 1261까지의 랜덤숫자를 choice에 대입
			Sleep(100); // 딜레이를 준다
			score = score + 10; // score에 10을 증가하고 대입
			cur = (60 * len) / (end_t - start_t); // 현재 타수를 구하여 cur에 대입
			totalCur += cur;
			avg = totalCur / inputCnt; // 평균 타수를 구하여 avg에 대입
		}

		else // ans와 wordDB[choice] 비교했을 때 같지 않으면
		{
			printf("오답입니다. \n"); // "오답입니다."를 출력
			Sleep(100); // 딜레이를 준다
			score = score - 5; // score에 5를 감소하고 대입
		}
	}
}

void word_test() // void는 함수가 끝나고 반환되는 값이 없다.
{
	// 정적메모리
	char word[2428][11] = { "" }, game[5][11] = { "" }, ans[256] = ""; // 최대길이가 11개인 메모리 word를 2428개 만들고 최대길이가 11개인 메모리 game을 5개 만들고, 길이가 256인 ans를 만들어 모두 0으로 초기화
	int wordCnt = 0, i = 0, max = 0, len = 0, choice = 0, correct = 5, score = 0, cur = 0, avg = 0, st = 0, et = 0, totalCur = 0, inputCnt = 0;
	// 정수형 메모리 wordCnt, i , max, len , choice, score, cur, avg , st, et, totalCur, inputCnt 을 만들고 모두 0으로 초기화, correct를 만들어 5를 대입

	FILE* fp = fopen("word.txt", "rt"); // word.txt 파일을 read text모드로 열어서 fp에 대입
	if (fp == NULL) return; // fp가 비어있으면 리턴
	// printf("fp is %p \n", fp);
	// getch();

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		fscanf(fp, "%s", &word[wordCnt]); // fp에서 문자하나를 읽어서 word의 [wordCnt]번째 메모리로 배달
		// len = strlen(word);
		// if (len > max) max = len;
		wordCnt++; // wordCnt에 1을 증가
		if (feof(fp) == 1) break; // fp가 끝이라면 반복문 종료, (1을 넣으면 세이프티 코드)
	}

	/*
	printf("wordCnt is %d, max length is %d \n", wordCnt, max);
	for (i = 0;i < wordCnt; i++)
	printf("%s \n", word[i]);
	*/

	// 5개의 단어를 선택해서 game메모리로 이동
	srand(time(NULL)); // 1970년 1월 1일 0시 0분 부터 현재까지의 시간(초)을 대입
	for (i = 0; i < 5; i++) // i에 0을 대입하고 1을 증가하며 4까지 반복
	{
		choice = rand() % wordCnt; // 0부터 2428까지의 랜덤숫자를 choice에 대입
		strcpy(game[i], word[choice]); // word[choice] 하나 선택해서 game[i]에 복사
	}

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		system("cls"); // 화면 지우기
		printf("----------------------------------------- \n"); // "----------------------------------------- " 출력
		printf("한글 단어 연습 프로그램 (종료를 입력하면 종료가 됩니다.) \ n"); // "한글 단어 연습 프로그램 (종료를 입력하면 종료가 됩니다.)"을 출력
		printf("----------------------------------------- \n"); // "----------------------------------------- " 출력
		printf("현재 점수 : %d, 현재 타수 : %d, 평균 타수 : %d \n", score, cur, avg); // "현재 점수 : %d, 현재 타수 : %d, 평균 타수 : %d"를 출력
		printf("----------------------------------------- \n"); // "----------------------------------------- " 출력
		for (i = 0; i < 5; i++) // i에 0을 대입하고 1을 증가하며 4까지 반복
			printf("%s ", game[i]); // game[i] 출력 (타자연습 단어)
		printf("%d/5 \n", correct); // correct 출력 (남은단어 갯수)

		// 타이핑 치는 시간 측정
		st = time(NULL); // 시작 시간
		gets(ans); // 입력
		et = time(NULL); // 종료 시간
		// printf("time is %d \n", et - st);
		// Sleep(500);

		len = strlen(ans); // ans의 길이를 측정해서 len에 대입
		cur = (len * 60) / (et - st); // 현재 타수 구하기
		// 평균 타수 구하기
		totalCur += cur; // 현재 타수의 총합 구하기
		inputCnt++; // 입력한 단어길이 구하기
		avg = totalCur / inputCnt; // 평균 타수

		if (strcmp(ans, "종료") == 0) break; // 종료가 입력되면 종료

		int flag = 5; // 정수형 메모리 flag를 만들고 5를 대입

		for (i = 0; i < 5; i++) // i에 0을 대입하고 1을 증가하며 4까지 반복
		{
			if (strcmp(ans, game[i]) == 0) // ans와 game[i]이 같은 단어이면
			{
				// 정답
				strcpy(game[i], ""); // 게임메모리 지우기 (공백넣으면 지워진다.)
				correct = correct - 1; // correct에 1을 감소
				flag--; // flag에 1을 감소
			}
		}

		if (flag == 5) score = score - 5; // flag가 5 라면 5씩 감소 (맞춘것이 없다.)
		if (flag < 5) score = score + 5; // flag가 5보다 작다면 5씩 증가 (하나라도 맞춘것이 있다.)

		if (correct == 0) // correct가 0과 같다면
		{
			correct = 5; // correct에 5를 대입
			for (i = 0; i < 5; i++) // i에 0을 대입하고 1을 증가하며 4까지 반복
			{
				choice = rand() % wordCnt; // 0부터 2428까지의 랜덤숫자를 choice에 대입 strcpy(game[i], word[choice]); // word[choice] 하나 선택해서 game[i]에 복사
			}
		}
	}
}

void error() // void는 함수가 끝나고 반환되는 값이 없다.
{
	printf("잘못 입력 하셨습니다. 1번 ~ 5번의 메뉴를 선택하세요. \ n"); // "잘못 입력 하셨습니다. 1번 ~ 5번의 메뉴를 선택하세요."를 출력
}

void main() // 프로그램 시작 점
{
	int no = 0; // 정수형 메모리 no를 만들고 0으로 초기화
	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		no = menu(); // menu() 함수 호출하여 결과값을 no에 대입
		// printf("선택된 값은 : %d \n", no); 

		switch (no) // 어떤 변수의 값이 상수로 만들어 질 때 사용
		{
		case 1: encrypt(); break; // no가 1과 일치하면 encrypt() 함수 호출
		case 2: decrypt(); break; // no가 2와 일치하면 decrypt() 함수 호출
		case 3: short_test(); break; // no가 3과 일치하면 short_test() 함수 호출
		case 4: word_test(); break; // no가 4와 일치하면 word_test() 함수 호출
		case 5: exit(1); break; // no가 5와 일치하면 프로그램 종료
		default: error(); break; // no가 일치한게 없다면 error() 함수 호출
			// 스위치 안에서 break를 만나면 스위치 문을 나간다.
		}
	}
}
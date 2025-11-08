// 다음 프로그램은 화면에 정상적인 값이 출력되지 않는다. 그 이유를 설명하고, 정상적으로 printf() 함수의 값이 출력되기 위해서는 어떻게 해야 하는지 설명하시오.

/*
#include <stdio.h>

{

	char str[10] = “hello”;

	char* ptr = “hello”;

	str[0] = ‘H’;

	*ptr = ‘H’:

	printf(”str = % s \n”, str);

	printf(”ptr = % s \n”, ptr);

}
*/

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	// 컴퓨터에서 모든 상수는 데이터 섹션(read/only)으로 간다. 지역변수는 스택(read/write) 에 만들어진다
	char str[6] = "hello"; // 0번부터 5번까지 str 문자열 만들어지고 "hello" 가 들어간다.
	char* ptr = "hello"; // 데이터 섹션에 있는 hello가 스택으로 복사가 이루어진다. (주소형 변수 *ptr은 컴파일 옵션에 따라서 4바이트 혹은 6바이트이다.)

	// 바뀐 값이 출력 되기 위하여 행을 추가
	ptr = &str[0]; // ptr은 str의 0번째 주소를 가진다.
	str[0] = 'H'; // str의 0번째 주소를 H로 바꾼다. read/write 메모리어서 printf()가 작동한다.
	*(ptr) = 'H'; // ptr의 주소를 가지는 값을 H로 바꾼다. 하지만 read/only 메모리어서 printf()가 작동하지 않는다.

	printf("str:%s, ptr:%s \n", &str[0], ptr);
	printf("str:%p, ptr:%p \n", &str[0], ptr);
}
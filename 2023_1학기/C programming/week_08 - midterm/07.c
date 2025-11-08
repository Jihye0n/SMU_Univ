// 다음 프로그램은 정상 종료가 되지 않고 무한 반복을 진행한다. 그 이유를 설명하시오.

/*
#include <stdio.h>

void main()

{

	char i = 0, sum = 0;

	for (i = 0; i < 128; i++)

		sum = sum + i;

	printf(”sum = % d \n”, sum)

}
*/

// char i는 -128부터 +127까지이기 때문에 정상 종료 되지 않고 무한 반복한다.
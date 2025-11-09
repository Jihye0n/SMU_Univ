#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_DIGITS 50 // 소수 최대 자리 수 : 50
char buffer[1024]; // 데이터 저장할 버퍼
int i, j = 0;

struct public_key_class { // 공개 키 클래스
	long long modulus; // 모듈러스
	long long exponent; // 지수
};

struct private_key_class { // 개인 키 클래스
	long long modulus; // 모듈러스
	long long exponent; // 지수
};

// 최대공약수 계산
long long gcd(long long a, long long b) {
	long long c;
	while (a != 0) { // a가 0이 아닐 때까지 반복
		c = a; a = b % a; b = c;
	}
	return b; // 나머지가 0이 되었을 때 b가 최대공약수
}

// 모듈러 역수 계산
long long ExtEuclid(long long a, long long b) {
	long long x = 0, y = 1, u = 1, v = 0, gcd = b, m, n, q, r;
	while (a != 0) { // a가 0이 아닐 때까지 반복
		q = gcd / a; r = gcd % a;
		m = x - u * q; n = y - v * q;
		gcd = a; a = r; x = u; y = v; u = m; v = n;
	}
	return y; // 모듈러 역수인 y를 반환
}

// 모듈러 곱셈 연산
static inline long long modmult(long long a, long long b, long long mod) {

	if (a == 0) { // a가 0인 경우
		return 0; // 0을 반환
	}
	register long long product = a * b;

	if (product / a == b) { // 곱셈이 오버플로우 되지 않은 경우
		return product % mod; // 결과를 반환
	}

	if (a & 1) { // a가 홀수이 경우
		product = modmult((a >> 1), b, mod);
		if ((product << 1) > product) {
			return (((product << 1) % mod) + b) % mod;
		}
	}

	product = modmult((a >> 1), b, mod); // a가 짝수인 경우
	if ((product << 1) > product) {
		return (product << 1) % mod;
	}

	// 위의 방법으로 처리할 수 없는 경우
	long long sum;
	sum = 0;
	while (b > 0)
	{
		if (b & 1)
			sum = (sum + a) % mod;
		a = (2 * a) % mod;
		b >>= 1;
	}
	return sum;
}

// 모듈러 지수 연산
long long rsa_modExp(long long b, long long e, long long m) {
	long long product;
	product = 1;
	if (b < 0 || e < 0 || m <= 0) { // 음수 또는 0인 경우
		return -1; // -1을 반환
	}
	b = b % m; // b를 m 이하의 값으로 설정

	// 모듈러 지수 연산 수행
	while (e > 0) {
		if (e & 1) {
			product = modmult(product, b, m);
		}
		b = modmult(b, b, m);
		e >>= 1;
	}
	return product; // 결과 반환
}

// 공개키, 개인키 생성
void rsa_gen_keys(struct public_key_class* pub, struct private_key_class* priv, char* PRIME_SOURCE_FILE)
{
	FILE* primes_list;
	// 소수 목록을 읽어오기 위해 파일을 오픈
	if (!(primes_list = fopen(PRIME_SOURCE_FILE, "r"))) { // 오픈이 안되면
		fprintf(stderr, "Problem reading %s\n", PRIME_SOURCE_FILE); // 에러 메시지 출력
		exit(1);
	}

	long long prime_count = 0; // 리스트에 있는 소수의 개수를 세어 저장
	do {
		int bytes_read = fread(buffer, 1, sizeof(buffer) - 1, primes_list);
		buffer[bytes_read] = '\0';
		for (i = 0; buffer[i]; i++) {
			if (buffer[i] == '\n') {
				prime_count++;
			}
		}
	} while (feof(primes_list) == 0); // 파일이 끝이 날 때 까지

	// 소수 목록에서 랜덤으로 소수 p와 q를 선택
	long long p = 0;
	long long q = 0;

	long long e = (2 << 16) + 1;
	long long d = 0;
	char prime_buffer[MAX_DIGITS];
	long long max = 0;
	long long phi_max = 0;

	srand(time(NULL)); // 랜덤 값

	do {
		// p와 q의 위치 a와 b를 랜덤으로 선택
		int a = (double)rand() * (prime_count + 1) / (RAND_MAX + 1.0);
		int b = (double)rand() * (prime_count + 1) / (RAND_MAX + 1.0);

		rewind(primes_list); // p를 리스트에서 찾아 저장
		for (i = 0; i < a + 1; i++) {
			//  for(j=0; j < MAX_DIGITS; j++){
			//  prime_buffer[j] = 0;
			//  }
			fgets(prime_buffer, sizeof(prime_buffer) - 1, primes_list);
		}
		p = atol(prime_buffer);

		rewind(primes_list); // q를 리스트에서 찾아 저장
		for (i = 0; i < b + 1; i++) {
			for (j = 0; j < MAX_DIGITS; j++) {
				prime_buffer[j] = 0;
			}
			fgets(prime_buffer, sizeof(prime_buffer) - 1, primes_list);
		}
		q = atol(prime_buffer);

		max = p * q; // p와 q를 곱해 N을 구한다.
		phi_max = (p - 1) * (q - 1); // (p-1)*(q-1)을 하여 L을 구한다.
	} while (!(p && q) || (p == q) || (gcd(phi_max, e) != 1)); // L의 값과 서로소인 E를 찾는다.

	d = ExtEuclid(phi_max, e); // D를 구하는 과정
	while (d < 0) {
		d = d + phi_max;
	}

	// 공개키와 개인키를 구조체에 저장
	pub->modulus = max;
	pub->exponent = e;

	priv->modulus = max;
	priv->exponent = d;
}

// 공개키를 암호화
long long* rsa_encrypt(const char* message, const unsigned long message_size, const struct public_key_class* pub)
{
	long long* encrypted = malloc(sizeof(long long) * message_size); // 암호화된 메시지 저장할 배열을 동적으로 할당
	if (encrypted == NULL) { // 할당이 실패한 경우
		fprintf(stderr,
			"Error: Heap allocation failed.\n"); // 에러 메시지 출력
		return NULL;
	}
	long long i = 0;
	for (i = 0; i < message_size; i++) {
		if ((encrypted[i] = rsa_modExp(message[i], pub->exponent, pub->modulus)) == -1) // 메시지를 공개키로 암호화
			return NULL;
	}
	return encrypted; // 암호화된 메시지를 반환
}

// 개인키를 사용하여 복호화
char* rsa_decrypt(const long long* message, const unsigned long message_size, const struct private_key_class* priv)
{
	if (message_size % sizeof(long long) != 0) { // 메시지 크기가 long long 타입의 크기로 나누어 떨어지지 않는 경우
		fprintf(stderr, "Error: message_size is not divisible by %d, so cannot be output of rsa_encrypt\n", (int)sizeof(long long)); // 에러 메시지 출력
		return NULL;
	}

	char* decrypted = malloc(message_size / sizeof(long long)); // 복호화된 메시지를 저장할 배열을 동적으로 할당
	char* temp = malloc(message_size); // 복화화를 위한 임시 배열을 동적으로 할당
	if ((decrypted == NULL) || (temp == NULL)) { // 할당에 실패한 경우
		fprintf(stderr, "Error: Heap allocation failed.\n"); // 에러 메시지 출력
		return NULL;
	}

	long long i = 0;
	for (i = 0; i < message_size / 8; i++) {
		if ((temp[i] = rsa_modExp(message[i], priv->exponent, priv->modulus)) == -1)
		{ // 암호문을 개인키로 복호화
			free(temp); // 메모리 해제
			return NULL;
		}
	}

	for (i = 0; i < message_size / 8; i++) { // 복호화된 결과를 decrypted에 저장
		decrypted[i] = temp[i];
	}
	free(temp); // 임시 배엘 메모리 해제
	return decrypted; // 복호화된 메시지 반환
}
#include <stdio.h>
#include "rsa.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	struct public_key_class pub[1]; // 공개키를 저장할 구조체 선언
	struct private_key_class priv[1]; // 개인키를 저장할 구조체 선언
	rsa_gen_keys(pub, priv, PRIME_SOURCE_FILE); // 공개키와 개인키 생성

	printf("Private Key:\n Modulus: %lld\n Exponent: %lld\n\n", (long long)priv->modulus, (long long)priv->exponent); // 개인키 출력
	printf("Public Key:\n Modulus: %lld\n Exponent: %lld\n\n", (long long)pub->modulus, (long long)pub->exponent); // 공개키 출력

	char message[] = "123abc"; // 평문 생성
	int i;

	printf("Original:\n"); // 평문 출력
	for (i = 0; i < strlen(message); i++) {
		printf("%c", (char)message[i]);
	}

	// 메시지를 암호화
	long long* encrypted = rsa_encrypt(message, sizeof(message), pub);
	if (!encrypted) { // 에러가 발생한 경우
		fprintf(stderr, "Error in encryption!\n"); // 에러 메시지 출력
		return 1;
	}

	// 암호화된 메시지 출력
	printf("\n\nEncrypted:\n");
	for (i = 0; i < strlen(message); i++) {
		printf("%lld\t", (long long)encrypted[i]);
	}

	// 암호문을 복호화
	char* decrypted = rsa_decrypt(encrypted, 8 * sizeof(message), priv);
	if (!decrypted) { // 에러가 발생한 경우
		fprintf(stderr, "Error in decryption!\n"); // 에러 메시지 출력
		return 1;
	}

	// 복호화된 메시지 출력
	printf("\n\nDecrypted:\n");
	for (i = 0; i < strlen(message); i++) {
		printf("%c", (char)decrypted[i]);
	}

	printf("\n");
	free(encrypted); // 암호화 메모리 해제
	free(decrypted); // 복호화 메모리 해제
	return 0;
}
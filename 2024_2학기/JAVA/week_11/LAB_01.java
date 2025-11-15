import java.io.*;
import java.nio.file.*;

public class Main {

    // XOR 복호화
    public static byte[] xorDecrypt(byte[] data, char key) {
        byte[] decryptedData = new byte[data.length];
        int keyValue = key;

        // 각 바이트에 대해 XOR 연산을 수행
        for (int i = 0; i < data.length; i++) {
            decryptedData[i] = (byte) (data[i] ^ keyValue); // XOR 연산
        }
        return decryptedData;
    }

    // 바이트 이동
    public static byte[] shiftDecrypt(byte[] data) {
        byte[] decryptedData = new byte[data.length];

        // 각 인덱스에 대해, 이동값을 계산
        for (int i = 0; i < data.length; i++) {
            int shiftValue = (i % 7) + 5; // 인덱스에 따른 이동값
            decryptedData[i] = (byte) (data[i] - shiftValue); // 이동값을 빼서 복호화
        }
        return decryptedData;
    }

    // 복호화된 파일 내용이 정상적인지 확인
    public static boolean isValidDecryptedData(byte[] decryptedData) {
        String result = new String(decryptedData);
        return result.contains("Decryption"); // "Decryption" 문자열이 포함되어 있으면 값을 리턴
    }

    // 파일 복호화, 키 추측
    public static void tryAllKeys(String inputFile, String outputFile) throws IOException {
        // 키 대문자 A-Z에 대해 복호화
        for (char key = 'A'; key <= 'Z'; key++) {
            System.out.println("키 : " + key);
            // 각 키에 대해 복호화 시도
            byte[] encryptedData = Files.readAllBytes(Paths.get(inputFile));
            byte[] shiftDecryptedData = shiftDecrypt(encryptedData); // 바이트 이동
            byte[] decryptedData = xorDecrypt(shiftDecryptedData, key); // XOR

            // 복호화된 데이터에 "Decryption" 문자열이 포함된 경우
            if (isValidDecryptedData(decryptedData)) {
                // 복호화된 파일이 정상적인 경우
                String decryptedText = new String(decryptedData); // 복호화된 문장을 문자열로 변환
                Files.write(Paths.get(outputFile), decryptedData);
                System.out.println("복호화 키: " + key);
                System.out.println("복호화된 문장: " + decryptedText); // 복호화된 문장 출력
                return;
            }
        }

        // 키 소문자 a-z에 대해 복호화
        for (char key = 'a'; key <= 'z'; key++) {
            System.out.println("키 시도: " + key);
            // 각 키에 대해 복호화 시도
            byte[] encryptedData = Files.readAllBytes(Paths.get(inputFile));
            byte[] shiftDecryptedData = shiftDecrypt(encryptedData); // 2단계 바이트 이동 복호화
            byte[] decryptedData = xorDecrypt(shiftDecryptedData, key); // 1단계 XOR 복호화

            // 복호화된 데이터에 "Decryption" 문자열이 포함된 경우
            if (isValidDecryptedData(decryptedData)) {
                // 복호화된 파일이 정상적인 경우
                String decryptedText = new String(decryptedData); // 복호화된 문장을 문자열로 변환
                Files.write(Paths.get(outputFile), decryptedData);
                System.out.println("복호화 성공! 키: " + key);
                System.out.println("복호화된 문장: " + decryptedText); // 복호화된 문장 출력
                return;
            }
        }

        System.out.println("키를 찾아 복호화할 수 없습니다.");
    }

    public static void main(String[] args) {
        String inputFile = "password.enc";  // 암호화된 파일 경로
        String outputFile = "decrypted.txt"; // 복호화된 파일 경로

        try {
            tryAllKeys(inputFile, outputFile); // 모든 키에 대해 복호화 시도
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
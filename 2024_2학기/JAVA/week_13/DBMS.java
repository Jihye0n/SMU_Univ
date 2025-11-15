import java.io.*;
import java.util.*;

public class DBMS {
    private String filename;

    public DBMS(String filename) {
        this.filename = filename;
    }

    // Create
    public boolean create(String userId, String name, String email, String phone) {
        List<String[]> users = readAll();

        // ID가 이미 존재하는지 확인
        for (String[] user : users) {
            if (user[0].equals(userId)) {
                System.out.println("동일한 ID가 이미 존재합니다.");
                return false;
            }
        }

        // 새로운 사용자 파일에 추가
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.write(userId + "," + name + "," + email + "," + phone);
            writer.newLine();
            System.out.println("등록되었습니다.");
            return true;
        } catch (IOException e) {
            System.out.println("오류 발생");
            return false;
        }
    }

    // Read
    public List<String[]> readAll() {
        List<String[]> users = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] user = line.split(",");
                users.add(user);
            }
        } catch (FileNotFoundException e) {
            // 파일이 없으면 빈 리스트 반환
            return users;
        } catch (IOException e) {
            System.out.println("오류발생");
        }
        return users;
    }

    // Read : 특정 값으로 사용자 검색
    public void read(String searchType, String searchValue) {
        List<String[]> users = readAll(); // 모든 사용자 목록 읽기
        boolean found = false;

        for (String[] user : users) {
            if ((searchType.equals("id") && user[0].equals(searchValue)) ||
                    (searchType.equals("name") && user[1].equals(searchValue)) ||
                    (searchType.equals("email") && user[2].equals(searchValue)) ||
                    (searchType.equals("phone") && user[3].equals(searchValue))) {

                System.out.println("아이디: " + user[0] + ", 이름: " + user[1] + ", 이메일: " + user[2] + ", 전화번호: " + user[3]);
                found = true;
            }
        }

        if (!found) {
            System.out.println("사용자가 없습니다.");
        }
    }

    // Update
    public void update(String userId, String field, String newValue) {
        List<String[]> users = readAll();
        boolean updated = false;

        // ID가 일치하는 사용자를 찾아서 수정
        for (String[] user : users) {
            if (user[0].equals(userId)) {
                switch (field) {
                    case "name":
                        user[1] = newValue;
                        break;
                    case "email":
                        user[2] = newValue;
                        break;
                    case "phone":
                        user[3] = newValue;
                        break;
                    default:
                        System.out.println("오류 발생");
                        return;
                }
                updated = true;
                break;
            }
        }

        // 파일에 다시 쓰기
        if (updated) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                for (String[] user : users) {
                    writer.write(String.join(",", user));
                    writer.newLine();
                }
                System.out.println("정보가 수정되었습니다.");
            } catch (IOException e) {
                System.out.println("오류발생");
            }
        } else {
            System.out.println("사용자 정보를 찾을 수 없습니다.");
        }
    }

    // Delete
    public void delete(String searchType, String searchValue) {
        List<String[]> users = readAll();
        List<String[]> usersToDelete = new ArrayList<>();

        // 삭제할 사용자 찾기
        for (String[] user : users) {
            if ((searchType.equals("id") && user[0].equals(searchValue)) ||
                    (searchType.equals("name") && user[1].equals(searchValue)) ||
                    (searchType.equals("email") && user[2].equals(searchValue)) ||
                    (searchType.equals("phone") && user[3].equals(searchValue))) {
                usersToDelete.add(user);
            }
        }

        // 삭제할 사용자가 있으면
        if (!usersToDelete.isEmpty()) {
            // 삭제할 사용자 제외한 리스트로 갱신
            users.removeAll(usersToDelete);

            // 파일을 다시 쓰기
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
                for (String[] user : users) {
                    writer.write(String.join(",", user));
                    writer.newLine();
                }
                System.out.println("삭제되었습니다.");
            } catch (IOException e) {
                System.out.println("오류발생");
            }
        } else {
            System.out.println("사용자를 찾을 수 없습니다.");

        }
    }

    // 사용자 입력
    public static void userInput(DBMS dbms) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("선택하시오  (c: create, r: read, u: update, d: delete, q: quit) : ");
            String action = scanner.nextLine().trim().toLowerCase();


            if (action.equals("c")) {
                System.out.print("아이디 : ");
                String userId = scanner.nextLine().trim();
                System.out.print("이름 : ");
                String name = scanner.nextLine().trim();
                System.out.print("이메일 : ");
                String email = scanner.nextLine().trim();
                System.out.print("전화번호 : ");
                String phone = scanner.nextLine().trim();
                dbms.create(userId, name, email, phone);

            } else if (action.equals("r")) {
                System.out.print("검색 기준 선택 (id, name, email, phone) : ");
                String searchType = scanner.nextLine().trim().toLowerCase();
                System.out.print(searchType + " : ");
                String searchValue = scanner.nextLine().trim();
                dbms.read(searchType, searchValue);

            } else if (action.equals("u")) {
                System.out.print("수정할 아이디 :  ");
                String userId = scanner.nextLine().trim();
                System.out.print("수정할 항목 선택 (name, email, phone) : ");
                String field = scanner.nextLine().trim().toLowerCase();
                System.out.print(field + " : ");
                String newValue = scanner.nextLine().trim();
                dbms.update(userId, field, newValue);

            } else if (action.equals("d")) {
                System.out.print("삭제할 기준을 입력 (id, name, email, phone) : ");
                String searchType = scanner.nextLine().trim().toLowerCase();
                System.out.print(searchType + " : ");
                String searchValue = scanner.nextLine().trim();
                dbms.delete(searchType, searchValue);

            } else if (action.equals("q")) {
                System.out.println("프로그램 종료");
                break;

            } else {
                System.out.println("오류 발생");
            }
        }

        scanner.close();
    }

    public static void main(String[] args) {
        DBMS dbms = new DBMS("사용자.txt");
        userInput(dbms);
    }
}

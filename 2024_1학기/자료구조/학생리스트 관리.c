#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 구조체 생성
typedef struct student {
    char student_id[20];
    int department_id;
    char department_name[20];
    int grade;
    char name[20];
    char birthday[20];
} student;

// 노드 구조체 생성
typedef struct Node {
    student data;
    struct Node* next;
} Node;

int menu() {
    int n = 0;
    printf("-------------------------------- \n");
    printf("1. 추가 \n");
    printf("2. 삭제 \n");
    printf("3. 검색 \n");
    printf("4. 정렬 \n");
    printf("5. 저장 및 출력 \n");
    printf("6. 프로그램 종료 \n");
    printf("-------------------------------- \n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &n);
    getchar();
    return n;
}

// 노드 생성
Node* creatNode(student data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    // 예외 처리
    if (newNode == NULL) {
        printf("메모리 할당에 실패하였습니다.");
        exit(1);
    }
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

// 1. 추가 - 완성
void addNode(Node** phead, Node* p, Node* newNode) {

    // 리스트가 비어있을 경우
    if (*phead == NULL) {
        newNode->next = NULL;
        *phead = newNode;
    }

    // 노드가 하나 이상 있는 경우
    else {
        Node* tail = *phead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = NULL;
    }
}

// 2. 삭제 - 완성
void delNode(Node** phead, unsigned char* student_id, int department_id, char* department_name, int grade, char* name, char* birthday) {
    // 삭제할 노드를 가리키는 포인터
    Node* old = *phead;
    // 삭제할 이전노드를 가리키는 포인터
    Node* pre = NULL;
    
    while (old != NULL) {
        // 학과코드, 학과명, 학년이 일치하면 일치하는 사람들 포함 모두 삭제
        if (old->data.department_id == department_id || strcmp(old->data.department_name, department_name) == 0 || old->data.grade == grade) {
            // 삭제할 노드가 첫번째 노드일 경우
            if (pre == NULL) {
                *phead = old->next;
                free(old);
                old = *phead;
            }
            else {
                pre->next = old->next;
                free(old);
                old = pre->next;
            }
        }

        // 삭제할 노드를 찾는다.
        else {
            pre = old;
            old = old->next;
        }
    }

    system("cls");
    printf("삭제되었습니다. \n");
}

// 3. 검색 - 완성
void searchNode(Node* L, unsigned char* student_id, int department_id, char* department_name, int grade, char* name, char* birthday) {
    Node* p = L;

    while (p != NULL) {
        // 학과코드, 학과명, 학년이 같은 사람 포함해서 출력
        if (p->data.department_id == department_id && p->data.grade == grade) {
            printf("%s %d %s %d %s %s\n", p->data.student_id, p->data.department_id, p->data.department_name, p->data.grade, p->data.name, p->data.birthday);
        }
        p = p->next;
    }
}
// 4. 정렬 - 완성
void sortList(Node* head) {
    Node* p, * q;
    student tmp;

    // 학과 이름별로 정렬
    for (p = head; p != NULL; p = p->next) {
        for (q = p; q != NULL; q = q->next) {
            if (strcmp(q->data.department_name, p->data.department_name) > 0) { 
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

// 5. 저장 및 출력 - 완성
void saveList(Node* L, unsigned char* filename) {
    // 파일 열어서 저장
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 리스트안의 노드들을 student_list 파일에 저장
    Node* p = L;
    while (p != NULL) {
        fprintf(fp, "%s %d %s %d %s %s\n", p->data.student_id, p->data.department_id, p->data.department_name, p->data.grade, p->data.name, p->data.birthday);
        p = p->next;
    }
    fclose(fp);
}
// 출력
void dispList(Node* L) {
    Node* p = L;
    while (p != NULL) {
        printf("%s %d %s %d %s %s\n", p->data.student_id, p->data.department_id, p->data.department_name, p->data.grade, p->data.name, p->data.birthday);
        p = p->next;
    } 
    printf("\n");
}

// 예외 처리
void error() {
    printf("잘못 입력 하셨습니다. 1 ~ 6의 메뉴를 선택하세요. \n");
}

int main() {
    FILE* fp = NULL;
    Node* L = NULL;
    student tmp;
    int choice = 0;
    char student_id[20];
    int department_id;
    char department_name[20];
    int grade;
    char name[20];
    char birthday[20];

    // 파일 읽어오기
    fp = fopen("student_list.txt", "rt");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다. \n");
        return 0;
    }

    // 파일안의 내용들을 읽어와서 노드로 생성
    while (fscanf(fp, "%s %d %s %d %s %s", tmp.student_id, &tmp.department_id, tmp.department_name, &tmp.grade, tmp.name, tmp.birthday) != EOF) {
        addNode(&L, NULL, creatNode(tmp, NULL));
    }
    fclose(fp);

    while (1) {
        choice = menu();

        switch (choice) {
        case 1:
            printf("학번 입력 : ");
            scanf("%s", tmp.student_id);
            printf("학과번호 입력 : ");
            scanf("%d", &tmp.department_id);
            printf("학과이름 입력 : ");
            scanf("%s", tmp.department_name);
            printf("학년 입력 : ");
            scanf("%d", &tmp.grade);
            printf("이름 입력 : ");
            scanf("%s", tmp.name);
            printf("생년월일 입력 : ");
            scanf("%s", tmp.birthday);
            addNode(&L, NULL, creatNode(tmp, NULL));
            system("cls");
            printf("추가 되었습니다. \n");
            break;
        case 2:
            printf("학번 입력 : ");
            scanf("%s", student_id);
            printf("학과번호 입력 : ");
            scanf("%d", &department_id);
            printf("학과이름 입력 : ");
            scanf("%s", department_name);
            printf("학년 입력 : ");
            scanf("%d", &grade);
            printf("이름 입력 : ");
            scanf("%s", name);
            printf("생년월일 입력 : ");
            scanf("%s", birthday);
            delNode(&L, student_id, department_id, department_name, grade, name, birthday);
            break;
        case 3:
            printf("학번 입력 : ");
            scanf("%s", student_id);
            printf("학과번호 입력 : ");
            scanf("%d", &department_id);
            printf("학과이름 입력 : ");
            scanf("%s", department_name);
            printf("학년 입력 : ");
            scanf("%d", &grade);
            printf("이름 입력 : ");
            scanf("%s", name);
            printf("생년월일 입력 : ");
            scanf("%s", birthday);
            searchNode(L, student_id, department_id, department_name, grade, name, birthday);
            break;
        case 4:
            sortList(L);
            printf("학과이름 별로 정렬되었습니다. \n");
            dispList(L);
            break;
        case 5:
            saveList(L, "student_list.txt");
            dispList(L);
            break;
        case 6:
            free(L);
            exit(0);
            break;
        default: error(); break;
        }
    }
    return 0;
}

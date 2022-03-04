//
//  main.c
//  c_project_0215_002
//
//  Created by Junhyuek Kim on 2022/02/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define SUBJECT 3

typedef struct STUDENT_INFO{
    char name[10];
    int gender;
    int studentId;
    int c;
    int java;
    int reactNative;
    int total;
    double average;
    char grade;
}student_t;

char calGrade(double average);
void inputScore(student_t *p);
void defaultSorting(student_t *p);
void printResult(student_t *p, int count);
void sorting(student_t *p);
void searchStudent(student_t *p);
void swap(student_t *p, student_t *studentTemp, int i, int j);
void deleteStudent(student_t *p);
void update(student_t *p);
void addStudent(student_t *p);

int numOfStudents = 0;

int main(int argc, const char * argv[]) {
    
    int flag = 0;
    int menu = 0;
    
    student_t students[MAX_SIZE] = {{"", 0, 0, 0, 0, 0, 0, 0.0, 0},};
    
    system("clear");

    printf("\n몇 명의 학생 정보를 입력하시겠습니까 ? ");
    scanf("%d", &numOfStudents);
    
    
    while (!flag) {
        system("clear");
        printf("1.성적 입력\n");
        printf("2.성적 출력\n");
        printf("3.정렬\n");
        printf("4.학생 정보 검색\n");
        printf("5.학생 정보 삭제\n");
        printf("6.학생 성적 수정\n");
        printf("7.학생 정보 추가\n");
        printf("8.프로그램 종료\n");
        printf("\n메뉴를 선택하세요. ");
        scanf("%d", &menu);
        
        switch (menu) {
            case 1:
                inputScore(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 2:
                printResult(students, numOfStudents);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 3:
                sorting(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 4:
                searchStudent(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 5:
                deleteStudent(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 6:
                update(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 7:
                addStudent(students);
                printf("\n메뉴로 돌아가려면 엔터를 누르세요.\n");
                getchar();
                getchar();
                break;
            case 8:
                flag = 1;
                printf("\n프로그램을 종료합니다.\n");
                break;
        }
    }
    return 0;
}

void inputScore(student_t *p){
    
    for (int i = 0; i < numOfStudents; i++){
        p[i].name[0] = rand() % 26 + 'A';
        p[i].name[1] = rand() % 26 + 'A';
        p[i].name[2] = rand() % 26 + 'A';
        
        p[i].gender = rand() % 2;
        
        p[i].studentId = rand() % 9000 + 1000;
        
        p[i].c = rand() % 101;
        p[i].java = rand() % 101;
        p[i].reactNative = rand() % 101;
        
        p[i].total = p[i].c + p[i].java + p[i].reactNative;
        p[i].average = p[i].total / (double)SUBJECT;
        p[i].grade = calGrade(p[i].average);
    }
    
    defaultSorting(p);
    printf("\n입력을 완료하였습니다.\n");
    
    return;
}

char calGrade(double average){
    
    char grade = 0;
    
    switch((int)average / 10){
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }
    return grade;
}

void swap(student_t *p, student_t *studentTemp, int i, int j){
    memcpy(&studentTemp[0], &p[i], sizeof(student_t));
    memcpy(&p[i], &p[j], sizeof(student_t));
    memcpy(&p[j], &studentTemp[0], sizeof(student_t));
    return;
}

void defaultSorting(student_t *p){
    
    student_t studentTemp = {0,};
    for (int i = 0; i < numOfStudents - 1; i++) {
        for (int j = i + 1; j < numOfStudents; j++) {
            if (p[i].studentId > p[j].studentId) {
                swap(p, &studentTemp, i, j);
            }
        }
    }
    return;
}

void printResult(student_t *p, int count){
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("     이름\t 성별\t 학번\t C\t Java\t React Native\t 총점\t 평균\t 학점");
    printf("\n-------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-4d %s\t %s\t %d\t %d\t %d\t %d\t\t %d\t %.2lf\t %c", i + 1, p[i].name, (p[i].gender == 0) ? "여" : "남", p[i].studentId, p[i].c, p[i].java, p[i].reactNative, p[i].total, p[i].average, p[i].grade);
        printf("\n-------------------------------------------------------------------------------------\n");
        
    }
    
    return;
}

void sorting(student_t *p){
    
    student_t studentTemp = {0,};
    student_t studentCopy[numOfStudents];
    
    int select = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < numOfStudents; i++) {
        memcpy(&studentCopy[i], &p[i], sizeof(student_t));
    }
    
    printf("\n1. 내림차순\n");
    printf("2. 오름차순\n");
    printf("정렬 방법을 고르세요.");
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            for (i = 0; i < numOfStudents - 1; i++) {
                for (j = i + 1; j < numOfStudents; j++) {
                    if (studentCopy[i].total < studentCopy[j].total) {
                        swap(studentCopy, &studentTemp, i, j);
                    }
                }
            }
            break;
            
        case 2:
            for (i = 0; i < numOfStudents - 1; i++) {
                for (j = i + 1; j < numOfStudents; j++) {
                    if (studentCopy[i].total > studentCopy[j].total) {
                        swap(studentCopy, &studentTemp, i, j);
                    }
                }
            }
            break;
    }
    
    printf("\n");
    printResult(studentCopy, numOfStudents);
    
    return;
}

void searchStudent(student_t *p){
    char name[10] = "";
    int check = 0;
    
    printf("\n검색할 학생의 이름을 입력하세요.(알파벳 대문자 3자) : ");
    scanf("%s", name);
    
    for (int i = 0; i < numOfStudents; i++) {
        if(!strncmp(p[i].name, name, 3)){
            check = 1;
            printResult(&p[i], 1);
        }
    }
    if (check == 0){
        printf("\n%s 학생의 정보가 없습니다.\n", name);
    }
    
    return;
}

void deleteStudent(student_t *p){
    char name[10] = "";
    int check = 0;
    int i = 0;
    int j = 0;
    printf("\n삭제할 학생의 이름을 입력하세요.(알파벳 대문자 3자) : ");
    scanf("%s", name);
    
    for (i = 0; i < numOfStudents; i++) {
        if(!strncmp(p[i].name, name, 3)){
            check = 1;
            strcpy(p[i].name, "");
            p[i].gender = 0;
            p[i].studentId = 0;
            p[i].c = 0;
            p[i].java = 0;
            p[i].reactNative = 0;
            p[i].total = 0;
            p[i].average = 0.0;
            p[i].grade = 0;
            
            for (j = i; j < numOfStudents; j++) {
                memcpy(&p[j], &p[j + 1], sizeof(student_t));
            }
            numOfStudents--;
        }
    }
    
    if (check == 0){
        printf("\n%s 학생의 정보가 없습니다.\n", name);
    } else {
        printf("\n학생 성적 정보를 삭제하였습니다.\n");
    }
    
    return;
}

void update(student_t *p){
    char name[10] = "";
    int check = 0;
    
    printf("\n성적정보를 수정할 학생의 이름을 입력하세요.(알파벳 대문자 3자) : ");
    scanf("%s", name);
    
    for (int i = 0; i < numOfStudents; i++) {
        if(!strncmp(p[i].name, name, 3)){
            check = 1;
            
            printf("\n%s의 C 점수(%d) 수정할 점수 : ", p[i].name, p[i].c);
            scanf("%d", &p[i].c);
            printf("%s의 Java 점수(%d) 수정할 점수 : ", p[i].name, p[i].java);
            scanf("%d", &p[i].java);
            printf("%s의 React Native 점수(%d) 수정할 점수 : ", p[i].name, p[i].reactNative);
            scanf("%d", &p[i].reactNative);
            
            p[i].total = p[i].c + p[i].java + p[i].reactNative;
            p[i].average = p[i].total / (double)SUBJECT;
            p[i].grade = calGrade(p[i].average);
        }
    }
    
    if (check == 0){
        printf("\n%s 학생의 정보가 없습니다.\n", name);
    } else {
        printf("\n%s 학생의 정보 업데이트를 완료했습니다.\n", name);
    }
    
    return;
}

void addStudent(student_t *p){
    
    if (numOfStudents + 1 > MAX_SIZE){
        printf("\n더 이상 추가할 수 없습니다.\n");
        return;
    }
    
    numOfStudents++;
    
    printf("\n추가할 학생의 이름 : ");
    scanf("%s", p[numOfStudents - 1].name);
    printf("추가할 학생의 성별 (0 : 여, 1 : 남) : ");
    scanf("%d", &p[numOfStudents - 1].gender);
    printf("추가할 학생의 학번 (1000 ~ 9999) : ");
    scanf("%d", &p[numOfStudents - 1].studentId);
    printf("추가할 학생의 C 점수 (0~ 100) : ");
    scanf("%d", &p[numOfStudents - 1].c);
    printf("추가할 학생의 Java 점수 (0~ 100) : ");
    scanf("%d", &p[numOfStudents - 1].java);
    printf("추가할 학생의 React Native 점수 (0~ 100) : ");
    scanf("%d", &p[numOfStudents - 1].reactNative);
    
    p[numOfStudents - 1].total = p[numOfStudents - 1].c + p[numOfStudents - 1].java + p[numOfStudents - 1].reactNative;
    p[numOfStudents - 1].average = p[numOfStudents - 1].total / (double)SUBJECT;
    p[numOfStudents - 1].grade = calGrade(p[numOfStudents - 1].average);
    
    defaultSorting(p);
    
    printf("\n학생 성적 정보 추가를 완료하였습니다.\n");
    
    return;
}

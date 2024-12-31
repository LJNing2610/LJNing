#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义教师结构体
typedef struct Teacher {
    char name[50];//名字 
    int age;//年龄 
    char title[20];//职称 
    char education[20];//学历 
    char degree[20];//学位 
    int id;//职工号 
} Teacher;

//(8)保存教师信息到文件
void saveTeachersToFile(const char *filename, Teacher teachers[], int teacherCount) {
    int i;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开文件进行保存!\n");
        printf("---------------------\n");
        return;
    }

    for (i = 0; i < teacherCount; i++) {
        fprintf(fp, "%s %d %s %s %s %d\n", teachers[i].name, teachers[i].age, teachers[i].title, teachers[i].education, teachers[i].degree, teachers[i].id);
    }

    fclose(fp);
    printf("信息已保存，程序退出!\n");
    printf("---------------------\n");
}

// (1)录入教师信息
int inputTeacherInfo(Teacher *teachers, int teacherCount) {
    if (teacherCount >= 1000) {
        printf("教师数量已达上限\n");
        printf("---------------------\n");
        return teacherCount;
    }
    printf("请输入教师姓名: ");
    scanf("%s", teachers[teacherCount].name);
    printf("请输入教师年龄: ");
    scanf("%d", &teachers[teacherCount].age);
    printf("请输入教师职称(无职称、初级、中级、副高级、正高级): ");
    scanf("%s", teachers[teacherCount].title);
    printf("请输入教师学历(专科、大学本科、硕士研究生、博士研究生): ");
    scanf("%s", teachers[teacherCount].education);
    printf("请输入教师学位(学士学位、硕士学位、博士学位): ");
    scanf("%s", teachers[teacherCount].degree);
    printf("请输入教师职工号: ");
    scanf("%d", &teachers[teacherCount].id);
    printf("---------------------\n");

    return teacherCount + 1;
}

// (2)浏览教师信息
void browseTeacherInfo(Teacher *teachers, int teacherCount) {
    int i;
    if (teacherCount == 0) {
        printf("没有教师信息\n");
        printf("---------------------\n");
        return;
    }
    printf("姓名\t年龄\t职称\t学历\t学位\t职工号\n");
    for (i = 0; i < teacherCount; i++) {
        printf("%s\t%d\t%s\t%s\t%s\t%d\n", teachers[i].name, teachers[i].age, teachers[i].title, teachers[i].education, teachers[i].degree, teachers[i].id);
    }
    printf("---------------------\n");
}

// (3)按条件查询统计
void queryAndCount(Teacher *teachers, int teacherCount) {
    int ageRange[4] = {0};
    int titleCount[5] = {0};
    int educationCount[4] = {0};
    int degreeCount[3] = {0};
    int i;
    char input[20];
    printf("请输入查询条件(年龄/职称/学历/学位): ");
    scanf("%s", input);
    if (strcmp(input, "年龄") == 0) {
        for (i = 0; i < teacherCount; i++) {
            if (teachers[i].age <= 35) {
                ageRange[0]++;
            } else if (teachers[i].age <= 45) {
                ageRange[1]++;
            } else if (teachers[i].age <= 55) {
                ageRange[2]++;
            } else {
                ageRange[3]++;
            }
        }
        printf("<=35岁: %d人\n", ageRange[0]);
        printf("35 - 45岁: %d人\n", ageRange[1]);
        printf("45 - 55岁: %d人\n", ageRange[2]);
        printf(">55岁: %d人\n", ageRange[3]);
        printf("---------------------\n");
    } else if (strcmp(input, "职称") == 0) {
        for (i = 0; i < teacherCount; i++) {
            if (strcmp(teachers[i].title, "无职称") == 0) {
                titleCount[0]++;
            } else if (strcmp(teachers[i].title, "初级") == 0) {
                titleCount[1]++;
            } else if (strcmp(teachers[i].title, "中级") == 0) {
                titleCount[2]++;
            } else if (strcmp(teachers[i].title, "副高级") == 0) {
                titleCount[3]++;
            } else if (strcmp(teachers[i].title, "正高级") == 0) {
                titleCount[4]++;
            }
        }
        printf("无职称: %d人\n", titleCount[0]);
        printf("初级: %d人\n", titleCount[1]);
        printf("中级: %d人\n", titleCount[2]);
        printf("副高级: %d人\n", titleCount[3]);
        printf("正高级: %d人\n", titleCount[4]);
        printf("---------------------\n");
    } else if (strcmp(input, "学历") == 0) {
        for (i = 0; i < teacherCount; i++) {
            if (strcmp(teachers[i].education, "专科") == 0) {
                educationCount[0]++;
            } else if (strcmp(teachers[i].education, "大学本科") == 0) {
                educationCount[1]++;
            } else if (strcmp(teachers[i].education, "硕士研究生") == 0) {
                educationCount[2]++;
            } else if (strcmp(teachers[i].education, "博士研究生") == 0) {
                educationCount[3]++;
            }
        }
        printf("专科: %d人\n", educationCount[0]);
        printf("大学本科: %d人\n", educationCount[1]);
        printf("硕士研究生: %d人\n", educationCount[2]);
        printf("博士研究生: %d人\n", educationCount[3]);
        printf("---------------------\n");
    } else if (strcmp(input, "学位") == 0) {
        for (i = 0; i < teacherCount; i++) {
            if (strcmp(teachers[i].degree, "学士学位") == 0) {
                degreeCount[0]++;
            } else if (strcmp(teachers[i].degree, "硕士学位") == 0) {
                degreeCount[1]++;
            } else if (strcmp(teachers[i].degree, "博士学位") == 0) {
                degreeCount[2]++;
            }
        }
        printf("学士学位: %d人\n", degreeCount[0]);
        printf("硕士学位: %d人\n", degreeCount[1]);
        printf("博士学位: %d人\n", degreeCount[2]);
        printf("---------------------\n");
    } else {
        printf("无效的查询条件\n");
        printf("---------------------\n");
    }
}

// (4)删除教师信息
int deleteTeacherInfo(Teacher *teachers, int teacherCount) {
    char name[1000];
    int i, j;
    printf("请输入要删除的教师姓名: ");
    scanf("%s", name);
    int found = 0;
    for (i = 0; i < teacherCount; i++) {
        if (strcmp(teachers[i].name, name) == 0) {
            found = 1;
            printf("找到教师: %s, 职工号: %d\n", teachers[i].name, teachers[i].id);
            printf("是否删除该教师信息(y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                for (j = i; j < teacherCount - 1; j++) {
                    teachers[j] = teachers[j + 1];
                }
                teacherCount--;
                printf("教师信息删除成功\n");
                break;
            }
            printf("---------------------\n");
        }
    }
    if (!found) {
        printf("未找到名为 %s 的教师\n", name);
        printf("---------------------\n");
    }
    return teacherCount;
}

//(5)修改教师信息
void modifyTeacherInfo(Teacher *teachers, int teacherCount) {
    char name[1000];
    printf("请输入要修改的教师姓名: ");
    scanf("%s", name);
    int found = 0;
    int i;
    for (i = 0; i < teacherCount; i++) {
        if (strcmp(teachers[i].name, name) == 0) {
            found = 1;
            printf("请输入新的年龄: ");
            scanf("%d", &teachers[i].age);
            printf("请输入新的职称(无职称、初级、中级、副高级、正高级): ");
            scanf("%s", teachers[i].title);
            printf("请输入新的学历(专科、大学本科、硕士研究生、博士研究生): ");
            scanf("%s", teachers[i].education);
            printf("请输入新的学位(学士学位、硕士学位、博士学位): ");
            scanf("%s", teachers[i].degree);
            printf("教师信息修改成功\n");
            printf("---------------------\n");
            break;
        }
    }
    if (!found) {
        printf("未找到名为 %s 的教师\n", name);
        printf("---------------------\n");
    }
}

//(6.1)按年龄排序
void sortByAge(Teacher *teachers, int teacherCount) {
    Teacher temp[1000];
    memcpy(temp, teachers, teacherCount * sizeof(Teacher));
    int i, j;
    for (i = 0; i < teacherCount - 1; i++) {
        for (j = 0; j < teacherCount - i - 1; j++) {
            if (temp[j].age > temp[j + 1].age) {
                Teacher t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    printf("按年龄排序后的结果:\n");
    printf("姓名\t年龄\t职称\t学历\t学位\t职工号\n");
    for (i = 0; i < teacherCount; i++) {
        printf("%s\t%d\t%s\t%s\t%s\t%d\n", temp[i].name, temp[i].age, temp[i].title, temp[i].education, temp[i].degree, temp[i].id);
    }
    printf("---------------------\n");
}

//(6.2)按职称排序
void sortByTitle(Teacher *teachers, int teacherCount) {
    Teacher temp[1000];
    memcpy(temp, teachers, teacherCount * sizeof(Teacher));
    int i, j;
    for (i = 0; i < teacherCount - 1; i++) {
        for (j = 0; j < teacherCount - i - 1; j++) {
            if (strcmp(temp[j].title, temp[j + 1].title) > 0) {
                Teacher t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    printf("按职称排序后的结果:\n");
    printf("姓名\t年龄\t职称\t学历\t学位\t职工号\n");
    for (i = 0; i < teacherCount; i++) {
        printf("%s\t%d\t%s\t%s\t%s\t%d\n", temp[i].name, temp[i].age, temp[i].title, temp[i].education, temp[i].degree, temp[i].id);
    }
    printf("---------------------\n");
}

//主函数
int main() {
    Teacher teachers[1000];
    int teacherCount = 0;
    int choice;
    char wenjian[50];
    while (1) {
        printf("教师信息管理系统\n");
        printf("1. 录入教师信息\n");
        printf("2. 浏览教师信息\n");
        printf("3. 查询统计\n");
        printf("4. 删除教师信息\n");
        printf("5. 修改教师信息\n");
        printf("6. 按年龄排序\n");
        printf("7. 按职称排序\n");
        printf("8. 保存退出\n");
        printf("请选择操作: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                teacherCount = inputTeacherInfo(teachers, teacherCount);
                break;
            case 2:
                browseTeacherInfo(teachers, teacherCount);
                break;
            case 3:
                queryAndCount(teachers, teacherCount);
                break;
            case 4:
                teacherCount = deleteTeacherInfo(teachers, teacherCount);
                break;
            case 5:
                modifyTeacherInfo(teachers, teacherCount);
                break;
            case 6:
                sortByAge(teachers, teacherCount);
                break;
            case 7:
                sortByTitle(teachers, teacherCount);
                break;
            case 8:
                printf("请输入希望保存的文件名：");
				scanf("%s",wenjian); 
                saveTeachersToFile(wenjian, teachers, teacherCount);
                return 0;
            default:
                printf("无效的选择，请重新输入\n");
                printf("---------------------\n");
        }
    }
    return 0;
}
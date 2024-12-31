#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义教师结构体
typedef struct Teacher 
{
    char id[20];
    char name[50];
    double jichugz;
    double class_hours;
    double zengjia;
    double jianxiang;
    char year_month;
} Teacher;

// 计算教师应发工资
double gz(Teacher teacher) 
{
    return teacher.jichugz + teacher.class_hours * 60 + teacher.zengjia - teacher.jianxiang;
}

// 输入教师信息
void input_teacher_information(Teacher *teacher) 
{
    printf("请输入教师工号：");
    scanf("%s", teacher->id);
    printf("请输入教师姓名：");
    scanf("%s", teacher->name);
    printf("请输入年月："); 
    scanf("%s",&teacher->year_month);
    printf("请输入基本工资：");
    scanf("%lf", &teacher->jichugz);
    printf("请输入课时量：");
    scanf("%lf", &teacher->class_hours);
    printf("请输入奖金：");
    scanf("%lf", &teacher->zengjia);
    printf("请输入扣款：");
    scanf("%lf", &teacher->jianxiang);
}

// 显示教师信息
void display_teacher_information(Teacher teacher) 
{
    printf("工号:%s\n", teacher.id);
    printf("姓名：%s\n", teacher.name);
    printf("年月:%s\n",&teacher.year_month);
    printf("基本工资：%.2lf\n", teacher.jichugz);
    printf("课时量：%.2lf\n", teacher.class_hours);
    printf("奖金：%.2lf\n", teacher.zengjia);
    printf("扣款：%.2lf\n", teacher.jianxiang);
    printf("应发工资：%.2lf\n", gz(teacher));
}

// 教师信息录入功能
void add_teacher_information(Teacher teachers[], int *count) 
{
    if (*count >= 100) 
	{
        printf("教师信息已满，无法添加！\n");
        return;
    }
    input_teacher_information(&teachers[*count]);
    (*count)++;
    printf("教师信息添加成功！\n");
}

// 教师信息浏览功能
void through_teacher(Teacher teachers[], int count) 
{
    if (count == 0) 
	{
        printf("暂无教师信息！\n");
        return;
    }
    int i;
    for (i = 0; i < count; i++) 
	{
        display_teacher_information(teachers[i]);
        printf("\n");
    }
}

// 查询统计功能
void query_statistics(Teacher teachers[], int count) 
{
    int choice;
    printf("1. 按工号查询\n");
    printf("2. 按年统计教师工资\n");
    printf("请选择：");
    scanf("%d", &choice);
    if (choice == 1) {
        char id[20];
        printf("请输入教师工号：");
        scanf("%s", id);
        int i;
        for (i = 0; i < count; i++) 
		{
            if (strcmp(teachers[i].id, id) == 0) 
			{
                display_teacher_information(teachers[i]);
                return;
            }
        }
        printf("未找到该教师信息！\n");
    }
    else if (choice == 2) 
	{
        char id[20];
        printf("请输入教师工号:");
        scanf("%s", id);
        int i;
        for (i = 0; i < count; i++) {
            if (strcmp(teachers[i].id, id) == 0) 
			{
                double annual_salary = gz(teachers[i]) * 12;
                printf("教师 %s 的年工资为：%.2lf\n", teachers[i].name, annual_salary);
                return;
            }
        }
        printf("未找到该教师信息！\n");
    }
    else {
        printf("无效选择！\n");
    }
}

// 信息删除功能
void delete_teacher_information(Teacher teachers[], int *count) 
{
    char id[20];
    printf("请输入要删除的教师工号:");
    scanf("%s", id);
    int i;
    for (i = 0; i < *count; i++) 
	{
        if (strcmp(teachers[i].id, id) == 0) 
		{
            int j;
            for (j = i; j < *count - 1; j++) 
			{
                teachers[j] = teachers[j + 1];
            }
            (*count)--;
            printf("教师信息删除成功\n");
            return;
        }
    }
    printf("未找到该教师信息！\n");
}

// 信息修改功能
void modify_teacher(Teacher teachers[], int count) 
{
    char id[20];
    printf("请输入要修改的教师工号:");
    scanf("%s", id);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(teachers[i].id, id) == 0) 
		{
            input_teacher_information(&teachers[i]);
            printf("教师信息修改成功！\n");
            return;
        }
    }
    printf("未找到该教师信息！\n");
}

// 排序功能
void sort_teacher(Teacher teachers[], int count) 
{
    int choice;
    printf("1. 按教师工号排正序\n");
    printf("2. 按应发工资排正序\n");
    printf("请选择：");
    scanf("%d", &choice);
    if (choice == 1) 
	{
        int i;
        for (i = 0; i < count - 1; i++) 
		{
            int j;
            for (j = 0; j < count - i - 1; j++) 
			{
                if (strcmp(teachers[j].id, teachers[j + 1].id) > 0) 
				{
                    Teacher temp = teachers[j];
                    teachers[j] = teachers[j + 1];
                    teachers[j + 1] = temp;
                }
            }
        }
        printf("教师信息按工号排序成功！\n");
    }
    else if (choice == 2) 
	{
        int i;
        for (i = 0; i < count - 1; i++) 
		{
            int j;
            for (j = 0; j < count - i - 1; j++) 
			{
                if (gz(teachers[j]) > gz(teachers[j + 1])) 
				{
                    Teacher temp = teachers[j];
                    teachers[j] = teachers[j + 1];
                    teachers[j + 1] = temp;
                }
            }
        }
        printf("教师信息按应发工资排序成功！\n");
    }
    else {
        printf("无效选择！\n");
    }
}

// 保存教师信息到文件
void save_teacher_information(Teacher teachers[], int count) 
{
    FILE *fp = fopen("teacher_info.txt", "w");
    if (fp == NULL) 
	{
        perror("打开文件失败");
        return;
    }
    // 写入教师信息数量
    fprintf(fp, "%d\n", count);
    int i; 
    for (i = 0; i < count; i++) 
	{
        fprintf(fp, "%s %s %.2lf %.2lf %.2lf %.2lf\n", teachers[i].id, teachers[i].name,
                teachers[i].jichugz, teachers[i].class_hours, teachers[i].zengjia, teachers[i].jianxiang);
    }
    fclose(fp);
    printf("教师信息已保存到文件！\n");
}

// 从文件中读取教师信息初始化数组
void load_teacher_information(Teacher teachers[], int *count) 
{
    FILE *fp = fopen("teacher_info.txt", "r");
    if (fp == NULL) 
	{
        return;
    }
    fscanf(fp, "%d", count);
    int i;
    for (i = 0; i < *count; i++) 
	{
        fscanf(fp, "%s %s %lf %lf %lf %lf", teachers[i].id, teachers[i].name,
               &teachers[i].jichugz, &teachers[i].class_hours, &teachers[i].zengjia, &teachers[i].jianxiang);
    }
    fclose(fp);
    printf("从文件中加载教师信息成功！\n");
}

// 保存退出功能
void save_and_exit(Teacher teachers[], int count) 
{
    save_teacher_information(teachers, count);
    printf("教师信息已保存，退出系统！\n");
}

int main() 
{
    Teacher teachers[100];
    int count = 0;
    load_teacher_information(teachers, &count);
     printf("                    *******************************************\n");
        printf("                    |欢迎使用教师工资管理系统                 |\n");
        printf("                    |制作人：陈齐翔 曾俊峰 刘杰 李洪毅 贺昊宇 |\n");

    int choice;
    do {
        printf("                    *******************************************\n");
        printf("                    |1. 教师工资信息录入功能                  |\n");
        printf("                    |2. 教师工资信息浏览功能                  |\n");
        printf("                    |3. 查询统计功能                          |\n");
        printf("                    |4. 信息删除功能                          |\n");
        printf("                    |5. 信息修改功能                          |\n");
        printf("                    |6. 分别按教师工号和应发工资进行排序      |\n");
        printf("                    |7. 保存退出                              |\n");
        printf("                    *******************************************\n");
        printf("                    请选择：");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                add_teacher_information(teachers, &count);
                break;
            case 2:
                through_teacher(teachers, count);
                break;
            case 3:
                query_statistics(teachers, count);
                break;
            case 4:
                delete_teacher_information(teachers, &count);
                break;
            case 5:
                modify_teacher(teachers, count);
                break;
            case 6:
                sort_teacher(teachers, count);
                break;
            case 7:
                save_and_exit(teachers, count);
                break;
            default:
                printf("无效选择，请重新选择！\n");
        }
    } while (choice!= 7);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����ʦ�ṹ��
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

// �����ʦӦ������
double gz(Teacher teacher) 
{
    return teacher.jichugz + teacher.class_hours * 60 + teacher.zengjia - teacher.jianxiang;
}

// �����ʦ��Ϣ
void input_teacher_information(Teacher *teacher) 
{
    printf("�������ʦ���ţ�");
    scanf("%s", teacher->id);
    printf("�������ʦ������");
    scanf("%s", teacher->name);
    printf("���������£�"); 
    scanf("%s",&teacher->year_month);
    printf("������������ʣ�");
    scanf("%lf", &teacher->jichugz);
    printf("�������ʱ����");
    scanf("%lf", &teacher->class_hours);
    printf("�����뽱��");
    scanf("%lf", &teacher->zengjia);
    printf("������ۿ");
    scanf("%lf", &teacher->jianxiang);
}

// ��ʾ��ʦ��Ϣ
void display_teacher_information(Teacher teacher) 
{
    printf("����:%s\n", teacher.id);
    printf("������%s\n", teacher.name);
    printf("����:%s\n",&teacher.year_month);
    printf("�������ʣ�%.2lf\n", teacher.jichugz);
    printf("��ʱ����%.2lf\n", teacher.class_hours);
    printf("����%.2lf\n", teacher.zengjia);
    printf("�ۿ%.2lf\n", teacher.jianxiang);
    printf("Ӧ�����ʣ�%.2lf\n", gz(teacher));
}

// ��ʦ��Ϣ¼�빦��
void add_teacher_information(Teacher teachers[], int *count) 
{
    if (*count >= 100) 
	{
        printf("��ʦ��Ϣ�������޷���ӣ�\n");
        return;
    }
    input_teacher_information(&teachers[*count]);
    (*count)++;
    printf("��ʦ��Ϣ��ӳɹ���\n");
}

// ��ʦ��Ϣ�������
void through_teacher(Teacher teachers[], int count) 
{
    if (count == 0) 
	{
        printf("���޽�ʦ��Ϣ��\n");
        return;
    }
    int i;
    for (i = 0; i < count; i++) 
	{
        display_teacher_information(teachers[i]);
        printf("\n");
    }
}

// ��ѯͳ�ƹ���
void query_statistics(Teacher teachers[], int count) 
{
    int choice;
    printf("1. �����Ų�ѯ\n");
    printf("2. ����ͳ�ƽ�ʦ����\n");
    printf("��ѡ��");
    scanf("%d", &choice);
    if (choice == 1) {
        char id[20];
        printf("�������ʦ���ţ�");
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
        printf("δ�ҵ��ý�ʦ��Ϣ��\n");
    }
    else if (choice == 2) 
	{
        char id[20];
        printf("�������ʦ����:");
        scanf("%s", id);
        int i;
        for (i = 0; i < count; i++) {
            if (strcmp(teachers[i].id, id) == 0) 
			{
                double annual_salary = gz(teachers[i]) * 12;
                printf("��ʦ %s ���깤��Ϊ��%.2lf\n", teachers[i].name, annual_salary);
                return;
            }
        }
        printf("δ�ҵ��ý�ʦ��Ϣ��\n");
    }
    else {
        printf("��Чѡ��\n");
    }
}

// ��Ϣɾ������
void delete_teacher_information(Teacher teachers[], int *count) 
{
    char id[20];
    printf("������Ҫɾ���Ľ�ʦ����:");
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
            printf("��ʦ��Ϣɾ���ɹ�\n");
            return;
        }
    }
    printf("δ�ҵ��ý�ʦ��Ϣ��\n");
}

// ��Ϣ�޸Ĺ���
void modify_teacher(Teacher teachers[], int count) 
{
    char id[20];
    printf("������Ҫ�޸ĵĽ�ʦ����:");
    scanf("%s", id);
    int i;
    for (i = 0; i < count; i++) 
	{
        if (strcmp(teachers[i].id, id) == 0) 
		{
            input_teacher_information(&teachers[i]);
            printf("��ʦ��Ϣ�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ��ý�ʦ��Ϣ��\n");
}

// ������
void sort_teacher(Teacher teachers[], int count) 
{
    int choice;
    printf("1. ����ʦ����������\n");
    printf("2. ��Ӧ������������\n");
    printf("��ѡ��");
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
        printf("��ʦ��Ϣ����������ɹ���\n");
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
        printf("��ʦ��Ϣ��Ӧ����������ɹ���\n");
    }
    else {
        printf("��Чѡ��\n");
    }
}

// �����ʦ��Ϣ���ļ�
void save_teacher_information(Teacher teachers[], int count) 
{
    FILE *fp = fopen("teacher_info.txt", "w");
    if (fp == NULL) 
	{
        perror("���ļ�ʧ��");
        return;
    }
    // д���ʦ��Ϣ����
    fprintf(fp, "%d\n", count);
    int i; 
    for (i = 0; i < count; i++) 
	{
        fprintf(fp, "%s %s %.2lf %.2lf %.2lf %.2lf\n", teachers[i].id, teachers[i].name,
                teachers[i].jichugz, teachers[i].class_hours, teachers[i].zengjia, teachers[i].jianxiang);
    }
    fclose(fp);
    printf("��ʦ��Ϣ�ѱ��浽�ļ���\n");
}

// ���ļ��ж�ȡ��ʦ��Ϣ��ʼ������
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
    printf("���ļ��м��ؽ�ʦ��Ϣ�ɹ���\n");
}

// �����˳�����
void save_and_exit(Teacher teachers[], int count) 
{
    save_teacher_information(teachers, count);
    printf("��ʦ��Ϣ�ѱ��棬�˳�ϵͳ��\n");
}

int main() 
{
    Teacher teachers[100];
    int count = 0;
    load_teacher_information(teachers, &count);
     printf("                    *******************************************\n");
        printf("                    |��ӭʹ�ý�ʦ���ʹ���ϵͳ                 |\n");
        printf("                    |�����ˣ������� ������ ���� ����� ����� |\n");

    int choice;
    do {
        printf("                    *******************************************\n");
        printf("                    |1. ��ʦ������Ϣ¼�빦��                  |\n");
        printf("                    |2. ��ʦ������Ϣ�������                  |\n");
        printf("                    |3. ��ѯͳ�ƹ���                          |\n");
        printf("                    |4. ��Ϣɾ������                          |\n");
        printf("                    |5. ��Ϣ�޸Ĺ���                          |\n");
        printf("                    |6. �ֱ𰴽�ʦ���ź�Ӧ�����ʽ�������      |\n");
        printf("                    |7. �����˳�                              |\n");
        printf("                    *******************************************\n");
        printf("                    ��ѡ��");
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
                printf("��Чѡ��������ѡ��\n");
        }
    } while (choice!= 7);
    return 0;
}

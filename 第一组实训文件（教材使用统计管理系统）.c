#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// ����̲Ľṹ��
typedef struct textbook {
    char ISBN[14];    // ISBN���
    char name[50];    // �̲�����
    char publisher[50];    // ������
    char time[50];    // ����ʱ��
    double price;    // �۸�
    char major[50];    // �̲�ʹ��רҵ
    double term;    // �̲�ʹ��ѧ��
} textbook;

// (1)�̲�ʹ����Ϣ¼�빦��(�̲�ʹ����Ϣ���ļ�����)
void input_textbook_information(textbook *textbooks,int *count) {
	printf("������̲�����: \n");
    scanf("%d",count);
	int i;
    for (i=0;i<*count;i++) {
        printf("¼��� %d ���̲���Ϣ\n",i+1);
        printf("������ISBN: ");
        scanf("%s", textbooks[i].ISBN);
        printf("������name: ");
        scanf("%s", textbooks[i].name);
        printf("������publisher: ");
        scanf("%s", textbooks[i].publisher);
        printf("������time: ");
        scanf("%s", textbooks[i].time);
        printf("������price: ");
        scanf("%lf", &textbooks[i].price);
        printf("������major: ");
        scanf("%s", textbooks[i].major);
        printf("������term: ");
        scanf("%lf", &textbooks[i].term);
        printf("------------------------\n");
    }
}

// (2)�̲�ʹ����Ϣ�������
void browse(textbook *textbooks,int n) {
    int i;
    for (i=0;i<n;i++){
        printf("------------------------\n");
        printf("\n");
		printf("number.%d:\n",i+1);
        printf("ISBN: %s\n",textbooks[i].ISBN);
        printf("name: %s\n",textbooks[i].name);
        printf("publisher: %s\n",textbooks[i].publisher);
        printf("time: %s\n",textbooks[i].time);
        printf("price: %.2f\n",textbooks[i].price);
        printf("major: %s\n",textbooks[i].major);
        printf("term: %.2f\n",textbooks[i].term);
        printf("------------------------\n");
        printf("\n");
    }
}

// (3.1)��ѯĳ��רҵĳ��ѧ�ڽ̲�ʹ�����
void queryMajorTerm(textbook textbooks[],int count,char major[],int term) {
    printf("��ѯ�������:\n");
    int i;
    for (i=0;i<count;i++){
        if (strcmp(textbooks[i].major, major) == 0 && textbooks[i].term==term){
            printf("ISBN���:%s\n",textbooks[i].ISBN);
            printf("�̲�����:%s\n",textbooks[i].name);
            printf("�۸�:%.2f\n",textbooks[i].price);
            printf("----------\n");
        }
    }
}

// (3.2)��ѯĳ��רҵһ��ѧ������ķ���
void queryMajorPrice(textbook textbooks[],int count,char major[]){
    int i;
    double totalcost=0;
    for (i=0;i<count;i++){
        if (strcmp(textbooks[i].major,major)==0){
            totalcost+=textbooks[i].price;
        }
    }
    printf("��רҵһ��ѧ������ķ��ã�%.2f\n",totalcost);
}

// (4)��Ϣɾ������
void deleter(textbook textbooks[],int *count,char major[],int term) {
    int index=0;
    int found=0;
    int i;
    while(index<*count){
        if(strcmp(textbooks[index].major, major)==0&&textbooks[index].term==term){
            for (i=index;i<*count-1;i++) {
                textbooks[i]=textbooks[i+1];
            }
            (*count)--;
            found=1;
        }else{
        	index++;
        }
    }
    if (found==1){
        printf("��Ϣɾ���ɹ�\n");
    } else {
        printf("δ�ҵ���Ӧ��Ϣ���޷�ɾ��\n");
    }
}

// (5)��Ϣ�޸Ĺ���
void modify_textbook(textbook textbooks[],int count) {
    char name[100];
    printf("������Ҫ�޸ĵĽ̲���:");
    scanf("%s",name);
    int i;
    for (i=0;i<count;i++) {
        if (strcmp(textbooks[i].name, name)==0) {
           printf("¼��� %d ���̲���Ϣ\n",i+1);
        printf("������ISBN: ");
        scanf("%s", textbooks[i].ISBN);
        printf("������name: ");
        scanf("%s", textbooks[i].name);
        printf("������publisher: ");
        scanf("%s", textbooks[i].publisher);
        printf("������time: ");
        scanf("%s", textbooks[i].time);
        printf("������price: ");
        scanf("%lf", &textbooks[i].price);
        printf("������major: ");
        scanf("%s", textbooks[i].major);
        printf("������term: ");
        scanf("%lf", &textbooks[i].term);
        printf("------------------------\n");
            printf("�̲���Ϣ�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ��ý̲���Ϣ��\n");
}

// ������ͬ(6)ʹ��
void swap(textbook *a, textbook*b) {
    textbook temp = *a;
    *a = *b;
    *b = temp;
}

// (6)��ISBN��Ž������򣬿��Կ���ͬһ���̲ļ۸�����
void quick_sort(textbook *textbooks, int left, int right) {
    if (left >= right) {
        return;
    }
    char *sb = textbooks[left].ISBN;
    int i = left, j = right;
    while (i < j) {
        while (i < j && strcmp(textbooks[j].ISBN, sb) >= 0) {
            j--;
        }
        while (i < j && strcmp(textbooks[i].ISBN, sb) < 0) {
            i++;
        }
        if (i < j) {
            swap(&textbooks[i], &textbooks[j]);
        }
    }
    swap(&textbooks[left], &textbooks[i]);
    quick_sort(textbooks, left, i - 1);
    quick_sort(textbooks, i + 1, right);
}
//(6)�۸����� 
void analyze(textbook *textbooks,int count){
    if (count <= 1) {
        if (count == 1) {
            printf("ֻ��һ���̲ģ��޷������۸����ơ�\n");
        }
        return;
    }
    int i = 0;
    while (i < count) {
        int start = i;
        while (i < count - 1 && strcmp(textbooks[i].ISBN, textbooks[i + 1].ISBN) == 0) {
            i++;
        }
        if (i - start > 0) {
            printf("����ISBNΪ %s �Ľ̲ģ��۸�����Ϊ��", textbooks[start].ISBN);
            if (textbooks[start].price < textbooks[i].price) {
                printf("����\n");
            }
            else if (textbooks[start].price > textbooks[i].price) {
                printf("�½�\n");
            }
            else {
                printf("��ƽ\n");
            }
        }
        else {
            printf("����ISBNΪ %s �Ľ̲ģ�ֻ��һ�����޷������۸����ơ�\n", textbooks[i].ISBN);
        }
        i++;
    }
}

// (7)����
void save(textbook textbooks[], int count){
    int i;
    FILE *fp=fopen("textbooks.txt", "w");
    if (fp==NULL) {
        printf("�޷����ļ����б���!\n");
        return;
    }

    for(i=0;i<count;i++){
        fprintf(fp,"%s,%s,%s,%s,%lf,%s,%lf\n", textbooks[i].ISBN, textbooks[i].name, textbooks[i].publisher, textbooks[i].time, textbooks[i].price, textbooks[i].major, textbooks[i].term);
    }

    fclose(fp);
    printf("��Ϣ�ѱ���\n");
}
//8.�˳�
void exitProgram() 
{
    printf("�����˳�!\n");
}

// ����
int main() {
    int count=0;
    int *er=&count; 
    textbook textbooks[100];
    int choice=0;
    printf("This is our system.: \n");
    printf("\n");
    printf("----������ �޽��� ��˶ο----\n----ף��� ��Ӿ� ������----\n"); 
    printf("\n");
    printf("         -��ӭʹ�ý̲�ͳ�ƹ���ϵͳ-                     ");
        double x, y;
        for (y = 1.5; y > -1.5; y -= 0.2) {
          for (x = -1.5; x < 1.5; x += 0.07) {
            double f = pow((x * x + y * y - 1), 3) - x * x * y * y * y;
            if (f <= 0) {
                printf("@");
            } else {
                printf(" ");
            }
           // printf("������: ������ �޽���");
        }
        printf("\n");
    }
	do{
        printf("                        �̲Ĺ���ϵͳ���ܲ˵�                           \n");
        printf("|---------------------------------------------------------------------|\n");
        printf("| 1. �̲�ʹ����Ϣ¼�빦��                                             |\n");
        printf("| 2. �̲�ʹ����Ϣ�������                                             |\n");
        printf("| 3. ��ѯĳ��רҵĳ��ѧ�ڽ̲�ʹ�������ĳ��רҵһ��ѧ������Ľ̲ķ��� |\n");
        printf("| 4. ��Ϣɾ������                                                     |\n");
        printf("| 5. ��Ϣ�޸Ĺ���                                                     |\n");
        printf("| 6. ��ISBN��Ž������� ,�۸�����                                     |\n");
        printf("| 7. �˳�                                                             |\n");
        printf("|---------------------------------------------------------------------|\n");
        printf("\n");
		printf("���������ѡ��: ");
        scanf("%d", &choice);
        printf("\n");
        while (choice<1||choice>8) {
            printf("�����ѡ����Ч,����������(��Χ��1��7): ");
            scanf("%d",&choice);
        }

        switch (choice) {
        case 1:
            input_textbook_information(textbooks,er);
            save(textbooks,count);
            break;
        case 2:
            browse(textbooks,count);
            break;
        case 3: {
            char major[50];
            double term;
            printf("������רҵ��: ");
            scanf("%s",major);
            printf("������ѧ��: ");
            scanf("%lf",&term);
            queryMajorTerm(textbooks,count,major,term);
            queryMajorPrice(textbooks,count,major);
            break;
        }
        case 4:{
            char major_del[50];
            int term_del;
            printf("������Ҫɾ����Ϣ��Ӧ��רҵ��: ");
            scanf("%s", major_del);
            printf("������Ҫɾ����Ϣ��Ӧ��ѧ��: ");
            scanf("%d", &term_del);
            deleter(textbooks,&count,major_del,term_del);
            save(textbooks,count);
            break;
        }
        case 5:
            modify_textbook(textbooks,count);
            save(textbooks,count);
            break;
        case 6:
            quick_sort(textbooks,0,count-1);
            analyze(textbooks,count);
            break;
        case 7:
        	save(textbooks,count);
			exitProgram(); 
            break;
        }

    }while(choice!=7);

    return 0;
}

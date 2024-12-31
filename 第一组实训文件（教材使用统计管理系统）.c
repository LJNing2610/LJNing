#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// 定义教材结构体
typedef struct textbook {
    char ISBN[14];    // ISBN编号
    char name[50];    // 教材名称
    char publisher[50];    // 出版社
    char time[50];    // 出版时间
    double price;    // 价格
    char major[50];    // 教材使用专业
    double term;    // 教材使用学期
} textbook;

// (1)教材使用信息录入功能(教材使用信息用文件保存)
void input_textbook_information(textbook *textbooks,int *count) {
	printf("请输入教材数量: \n");
    scanf("%d",count);
	int i;
    for (i=0;i<*count;i++) {
        printf("录入第 %d 本教材信息\n",i+1);
        printf("请输入ISBN: ");
        scanf("%s", textbooks[i].ISBN);
        printf("请输入name: ");
        scanf("%s", textbooks[i].name);
        printf("请输入publisher: ");
        scanf("%s", textbooks[i].publisher);
        printf("请输入time: ");
        scanf("%s", textbooks[i].time);
        printf("请输入price: ");
        scanf("%lf", &textbooks[i].price);
        printf("请输入major: ");
        scanf("%s", textbooks[i].major);
        printf("请输入term: ");
        scanf("%lf", &textbooks[i].term);
        printf("------------------------\n");
    }
}

// (2)教材使用信息浏览功能
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

// (3.1)查询某个专业某个学期教材使用情况
void queryMajorTerm(textbook textbooks[],int count,char major[],int term) {
    printf("查询结果如下:\n");
    int i;
    for (i=0;i<count;i++){
        if (strcmp(textbooks[i].major, major) == 0 && textbooks[i].term==term){
            printf("ISBN编号:%s\n",textbooks[i].ISBN);
            printf("教材名称:%s\n",textbooks[i].name);
            printf("价格:%.2f\n",textbooks[i].price);
            printf("----------\n");
        }
    }
}

// (3.2)查询某个专业一个学生四年的费用
void queryMajorPrice(textbook textbooks[],int count,char major[]){
    int i;
    double totalcost=0;
    for (i=0;i<count;i++){
        if (strcmp(textbooks[i].major,major)==0){
            totalcost+=textbooks[i].price;
        }
    }
    printf("该专业一个学生四年的费用：%.2f\n",totalcost);
}

// (4)信息删除功能
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
        printf("信息删除成功\n");
    } else {
        printf("未找到对应信息，无法删除\n");
    }
}

// (5)信息修改功能
void modify_textbook(textbook textbooks[],int count) {
    char name[100];
    printf("请输入要修改的教材名:");
    scanf("%s",name);
    int i;
    for (i=0;i<count;i++) {
        if (strcmp(textbooks[i].name, name)==0) {
           printf("录入第 %d 本教材信息\n",i+1);
        printf("请输入ISBN: ");
        scanf("%s", textbooks[i].ISBN);
        printf("请输入name: ");
        scanf("%s", textbooks[i].name);
        printf("请输入publisher: ");
        scanf("%s", textbooks[i].publisher);
        printf("请输入time: ");
        scanf("%s", textbooks[i].time);
        printf("请输入price: ");
        scanf("%lf", &textbooks[i].price);
        printf("请输入major: ");
        scanf("%s", textbooks[i].major);
        printf("请输入term: ");
        scanf("%lf", &textbooks[i].term);
        printf("------------------------\n");
            printf("教材信息修改成功！\n");
            return;
        }
    }
    printf("未找到该教材信息！\n");
}

// 交换法同(6)使用
void swap(textbook *a, textbook*b) {
    textbook temp = *a;
    *a = *b;
    *b = temp;
}

// (6)按ISBN编号进行排序，可以看出同一本教材价格趋势
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
//(6)价格趋势 
void analyze(textbook *textbooks,int count){
    if (count <= 1) {
        if (count == 1) {
            printf("只有一本教材，无法分析价格趋势。\n");
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
            printf("对于ISBN为 %s 的教材，价格趋势为：", textbooks[start].ISBN);
            if (textbooks[start].price < textbooks[i].price) {
                printf("上升\n");
            }
            else if (textbooks[start].price > textbooks[i].price) {
                printf("下降\n");
            }
            else {
                printf("持平\n");
            }
        }
        else {
            printf("对于ISBN为 %s 的教材，只有一本，无法分析价格趋势。\n", textbooks[i].ISBN);
        }
        i++;
    }
}

// (7)保存
void save(textbook textbooks[], int count){
    int i;
    FILE *fp=fopen("textbooks.txt", "w");
    if (fp==NULL) {
        printf("无法打开文件进行保存!\n");
        return;
    }

    for(i=0;i<count;i++){
        fprintf(fp,"%s,%s,%s,%s,%lf,%s,%lf\n", textbooks[i].ISBN, textbooks[i].name, textbooks[i].publisher, textbooks[i].time, textbooks[i].price, textbooks[i].major, textbooks[i].term);
    }

    fclose(fp);
    printf("信息已保存\n");
}
//8.退出
void exitProgram() 
{
    printf("程序退出!\n");
}

// 主体
int main() {
    int count=0;
    int *er=&count; 
    textbook textbooks[100];
    int choice=0;
    printf("This is our system.: \n");
    printf("\n");
    printf("----王瑞瑶 罗健宁 杨硕慰----\n----祝锦楠 李灿娟 徐智勇----\n"); 
    printf("\n");
    printf("         -欢迎使用教材统计管理系统-                     ");
        double x, y;
        for (y = 1.5; y > -1.5; y -= 0.2) {
          for (x = -1.5; x < 1.5; x += 0.07) {
            double f = pow((x * x + y * y - 1), 3) - x * x * y * y * y;
            if (f <= 0) {
                printf("@");
            } else {
                printf(" ");
            }
           // printf("制作人: 王瑞瑶 罗健宁");
        }
        printf("\n");
    }
	do{
        printf("                        教材管理系统功能菜单                           \n");
        printf("|---------------------------------------------------------------------|\n");
        printf("| 1. 教材使用信息录入功能                                             |\n");
        printf("| 2. 教材使用信息浏览功能                                             |\n");
        printf("| 3. 查询某个专业某个学期教材使用情况和某个专业一个学生四年的教材费用 |\n");
        printf("| 4. 信息删除功能                                                     |\n");
        printf("| 5. 信息修改功能                                                     |\n");
        printf("| 6. 按ISBN编号进行排序 ,价格趋势                                     |\n");
        printf("| 7. 退出                                                             |\n");
        printf("|---------------------------------------------------------------------|\n");
        printf("\n");
		printf("请输入你的选择: ");
        scanf("%d", &choice);
        printf("\n");
        while (choice<1||choice>8) {
            printf("输入的选项无效,请重新输入(范围是1到7): ");
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
            printf("请输入专业名: ");
            scanf("%s",major);
            printf("请输入学期: ");
            scanf("%lf",&term);
            queryMajorTerm(textbooks,count,major,term);
            queryMajorPrice(textbooks,count,major);
            break;
        }
        case 4:{
            char major_del[50];
            int term_del;
            printf("请输入要删除信息对应的专业名: ");
            scanf("%s", major_del);
            printf("请输入要删除信息对应的学期: ");
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

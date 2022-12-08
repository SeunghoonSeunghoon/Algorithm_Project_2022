#include<iostream>
#include<string.h>
#include<windows.h>

#define MAX_Q_SIZE 21

using namespace std;

string food[50];
int food_length[50];
int food_sales[50];
int num;
int ma_num;

typedef int element;
typedef struct {
    int rear;
    int front;
    element data[MAX_Q_SIZE];
    int cnt;
} Queue;

void initQueue(Queue* q)
{
    //front, rear 초기화
    q->front = q->rear = q->cnt = 0;
    
}

int isEmpty(Queue* q)
{
    // front가 가리키는 위치와 rear가 가리키는 위치가 같을 경우
    return q->front == q->rear;
}

int isFull(Queue* q)
{
    // rear의 다음 위치(rear + 1)의 값이 front와 같을 경우
    return (q->rear + 1) % MAX_Q_SIZE == q->front;
}

void enQueue(Queue* q, element item)
{
    // Queue를 추가하기 전에 Queue가 가득 찼는지 검사를 진행합니다.
    if (isFull(q))
        printf("앉을 수 있는 테이블이 없으므로, 손님에게 퇴장 요청을 보냈습니다.\n\n\n");
    else {
        cout << "손님을 추가했습니다." << endl << endl << endl;
        q->rear++;
        q->data[q->rear % MAX_Q_SIZE] = item;
        q->cnt++;
    }
}

element deQueue(Queue* q)
{
    // Queue를 제거하기 전에 Queue가 비었는지 검사를 진행합니다.
    if (isEmpty(q))
        printf("테이블이 모두 비었습니다.\n\n\n");
    else {
        printf("손님을 삭제하였습니다.\n\n\n");
        q->front++;
        q->cnt--;
        return q->data[q->front % MAX_Q_SIZE];
    }
}


void insert_sort(int arr[50]) {
    int i, j, key;
    string key1;
    for (i = 1; i < num; i++)
    {
        key = food_length[i];
        key1 = food[i];
        for (j = i - 1; j >= 0 && food_length[j] > key; j--)
        {
            food_length[j + 1] = food_length[j];
            food[j + 1] = food[j];
        }
        food_length[j + 1] = key;
        food[j + 1] = key1;
    }
}

void sales(int arr[]) {
    for (int i = 0; i < num; i++) {
        food_sales[i] = food_length[i] * 5;
    }
}
int main() {
    Queue q;
    element item =  0;
    initQueue(&q);

    printf("입력할 음식의 수를 입력해 주세요 : ");
    scanf_s("%d", &num);
    for (int i = 0; i < num; i++) {
        cout << "음식을 입력해주세요 : ";
        cin >> food[i];
        food_length[i] = food[i].size() / 2;
        cout << "입력한 음식 : " << food[i] << endl;

    }
    insert_sort(food_length);
    for (int i = 0; i < num; i++) {
        printf("%d", food_length[i]);
    }
    sales(food_sales);

    while (1) {
        cout << "     == 원하는 기능을 선택해 주세요 ==      " << endl  << "1. 테이블 보기" << endl << "2. 손님 추가" << endl << "3. 손님 삭제" << endl << "4. 음식 할인율 열람" << endl << "5. 프로그램 종료" << endl << endl;
        cin >> ma_num;
        switch (ma_num) {
        case 1: 
            system("cls");
            cout << "총 " << q.cnt << "개의 테이블이 사용되고 있습니다." << endl << endl << endl;
            break;

        case 2:
            system("cls");
            enQueue(&q, item);
            item++;
            break;

        case 3: 
            system("cls");
            deQueue(&q);
            
            break;

        case 4:
            system("cls");
            for (int i = 0; i < num; i++) {
                cout << food[i] << ":" << food_sales[i] << "%" << endl << endl << endl;
            }
            break;

        case 5:
            cout << "프로그램을 종료합니다.";
            exit(0);
        }
    }

    return 0;
}






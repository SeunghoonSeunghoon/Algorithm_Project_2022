#include<iostream>
#include<string.h>
#include<windows.h>

using namespace std;
string food[50];
int food_length[50];
int food_sales[50];
int num;
int ma_num;
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
        cout << "     == 원하는 기능을 선택해 주세요 ==      " << endl  << "1. 테이블 보기" << endl << "2. 손님 추가" << endl << "3. 손님 삭제" << "4. 음식 할인율 열람" << endl << "5. 프로그램 종료" << endl << endl;
        cin >> ma_num;
        switch (ma_num) {
        case 1: 
            cout << "총 " << "[사용되고 있는 테이블 개수]" << "개의 테이블이 사용되고 있습니다." << endl << endl << endl;

        case 2:
            system("cls");
            cout << "테이블 꽉 안찼으면 손님 추가, 찼으면 제일 오래 있었던 손님 빼내고 손님 추가 " << endl << endl << endl;
            break;

        case 3: 
            system("cls");
            cout << "손님을 삭제했습니다." << endl << endl << endl;
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






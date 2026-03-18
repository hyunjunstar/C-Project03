// Main.cpp

#include <iostream>
#include "Item.h"
#include "Inventory.h"

int main(void)
{
    Inventory<Item>* itemInventory = new Inventory<Item>(); // 객체 생성(힙 메모리)

    int menu;

    while (true)
    {
        std::cout << "\n===== 인벤토리 메뉴 =====\n";
        std::cout << "1. 아이템 추가\n";
        std::cout << "2. 마지막 아이템 삭제\n";
        std::cout << "3. 인벤토리 출력\n";
        std::cout << "0. 종료\n";
        std::cout << "선택 : ";

        std::cin >> menu;

        if (menu == 0)
            break;

        if (menu == 1)  // 아이템 추가
        {
            std::string name;
            int price;

            std::cout << "아이템 이름 : ";
            std::cin >> name;

            std::cout << "아이템 가격 : ";
            std::cin >> price;

            itemInventory->AddItem(Item(name, price));
        }

        else if (menu == 2) // 아이템 삭제
        {
            itemInventory->RemoveLastItem();
        }

        else if (menu == 3) // 인벤토리 목록 출력
        {
            itemInventory->PrintAllItems();
        }
    }

    delete itemInventory;
    itemInventory = nullptr;

    return 0;
}
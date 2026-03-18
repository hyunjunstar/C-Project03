// Item.cpp

#include "Item.h"

Item::Item()    // 기본 생성자
{
    name_ = "";
    price_ = 0;
}

Item::Item(const std::string& name, int price)  // 아이템 생성자
{
    name_ = name;
    price_ = price;
}

const std::string& Item::GetName() const    // 아이템 이름 반환
{
    return name_;
}

int Item::GetPrice() const  // 아이템 가격 반환
{
    return price_;
}

void Item::Clear()  // 아이템 초기화
{
    name_ = "";
    price_ = 0;
}

void Item::PrintInfo() const    // 정보 출력 함수
{
    std::cout << "이름 : " << name_ << ", 가격 : " << price_ << "원" << std::endl;
}
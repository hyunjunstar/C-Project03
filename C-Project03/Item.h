// Item.h

#pragma once

#include <string>
#include <iostream>

class Item
{
public:
	Item(); // 기본 생성자 추가

	Item(const std::string& name, int price); // 아이템 생성자

	const std::string& GetName() const; // 아이템 이름 반환

	int GetPrice() const; // 아이템 가격 반환

	void Clear(); // 아이템 초기화(이름, 가격)

	void PrintInfo() const; // 아이템 정보 출력

private:
	std::string name_; // 아이템 이름
	int price_;        // 아이템 가격
};
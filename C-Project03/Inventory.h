// Inventory.h

#pragma once

#include <iostream>

// 데이터 보관함 : Inventory<T> 템플릿 클래스 정의
template<typename T>
class Inventory
{
public:
    Inventory(int capacity = 10); // 생성자(동적 배열 메모리 할당)
    ~Inventory(); // 소멸자(동적 배열 메모리 해제)

    void AddItem(const T& item); // 아이템 추가 기능
    void RemoveLastItem(); // 마지막 아이템 제거 기능

    int GetSize() const; // 현재 아이템 개수 반환 기능
    int GetCapacity() const; // 현재 인벤토리 최대 용량 반환 기능

    void PrintAllItems() const; // 현재 인벤토리 내 모든 아이템 정보 출력 기능

private:
    T* pItems_; // 아이템 객체들을 저장할 동적 배열을 가르키는 포인터
    int capacity_; // 인벤토리의 최대 크기
    int size_; // 현재 인벤토리 내 모든 아이템 실제 개수
};

// Inventory 생성자
template<typename T>
Inventory<T>::Inventory(int capacity)
{
    if (capacity <= 0)	// capacity가 0 이하일 경우 최소 1로 보정
        capacity_ = 1;
    else
        capacity_ = capacity;

    size_ = 0;	// 현재 아이테 ㅁ개수 초기화
    pItems_ = new T[capacity_];	// 아이템을 저장할 동적 배열 생성
}

// Inventory 소멸자
template<typename T>
Inventory<T>::~Inventory()
{
    delete[] pItems_; // 동적 배열 메모리 해제

    pItems_ = nullptr; // 포인터 초기화
}

// 아이템 추가
template<typename T>
void Inventory<T>::AddItem(const T& item)
{

    if (size_ >= capacity_)    // 인벤토리가 가득 찼는지 확인
    {
        std::cout << "인벤토리가 꽉 찼습니다" << std::endl;
        return;
    }

    pItems_[size_] = item; // 현재 위치에 아이템 저장

    size_++; // 아이템 개수 증가
}

// 마지막 아이템 제거
template<typename T>
void Inventory<T>::RemoveLastItem()
{

    if (size_ <= 0)    // 인벤토리가 비어있는지 확인
    {
        std::cout << "인벤토리가 비어있습니다." << std::endl;
        return;
    }

    size_--; // 마지막 아이템 제거 (논리적 삭제)

    pItems_[size_].Clear(); // 마지막 아이템 초기화
}

// 현재 아이템 개수 반환
template<typename T>
int Inventory<T>::GetSize() const
{
    return size_; // 현재 아이템 개수 반환
}

// 인벤토리 최대 용량 반환
template<typename T>
int Inventory<T>::GetCapacity() const
{
    return capacity_; // 최대 저장 가능 개수 반환
}

// 인벤토리 전체 아이템 출력
template<typename T>
void Inventory<T>::PrintAllItems() const
{

    if (size_ == 0)    // 인벤토리가 비어있을 경우
    {
        std::cout << "비어있음" << std::endl;
        return;
    }


    for (int i = 0; i < size_; ++i)    // 저장된 아이템 개수만큼 반복
    {
        pItems_[i].PrintInfo(); // 각 아이템 정보 출력
    }
}
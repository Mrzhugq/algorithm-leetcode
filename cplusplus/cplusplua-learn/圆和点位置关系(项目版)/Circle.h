#pragma once
#include<iostream>
#include"Point.h"
using namespace std;


//Բ�� 
class Circle
{
private:
	int m_R; //�뾶 
	Point m_Center; //Բ��     ->  �����п�������һ���࣬��Ϊ����ĳ�Ա 
public:
	void SetR(int R);

	int GetR();
	
	void SetCenter(Point center);

	Point GetCenter();

};

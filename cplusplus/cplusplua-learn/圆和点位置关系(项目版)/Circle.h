#pragma once
#include<iostream>
#include"Point.h"
using namespace std;


//圆类 
class Circle
{
private:
	int m_R; //半径 
	Point m_Center; //圆心     ->  在类中可以让另一个类，作为本类的成员 
public:
	void SetR(int R);

	int GetR();
	
	void SetCenter(Point center);

	Point GetCenter();

};

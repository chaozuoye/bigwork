#pragma once
#include "Obstacle.h"
#include<deque>
class SandDobstacle {
private:
	int index = 0;
	int temp = 0;
public:
	std::deque<Obstacle*>obstacle;	//��������
	SandDobstacle() = default;
	void add(int i);// ��һ������������1�����ϰ�DownObstacle.png��2�����ϰ�LeftObstacle.png��3����RightObstaclepng
	void drawLine();
	int onKey(int key);
};
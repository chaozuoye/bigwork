#pragma once
class Obstacle
{
private:
	int dx = 4;
	int shape = 0;
	int level = 0;
public:
	int x = 1280, y = 430;
	void draw();/*���²������ϰ�*/
	Obstacle(const int shape);//��һ������������1�����ϰ�DownObstacle.png��2�����ϰ�LeftObstacle.png��3����RightObstaclepng
	int onKey(int key);
	bool getJudged();
};
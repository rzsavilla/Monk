#ifndef MOVEABLE_H
#define MOVEABLE_H



class Moveable
{
private:
	float fSpeed;
	float fMaxSpeed;
	float fAccel;
public:
	Moveable();
	float GetAngle();
	float GetSpeed();
	float GetMaxSpeed();

};

#endif
//ball.h
class Ball
{
private:
	double _x;
	double _y;
	double _z;
	double _r;
public:
	Ball(double x, double y, double z, double r);
	~Ball();

	double getCenterX();
	double getCenterY();
	double getCenterZ();
	double getRadius();

	void move(double x,double y,double z);
	void scale(double k);
	double calculateArea();
};
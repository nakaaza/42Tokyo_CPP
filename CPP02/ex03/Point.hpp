#ifndef POINT_HPP
# define POINT_HPP

class Point {

private:
	const Fixed	x;
	const Fixed	y;

public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point &src);
	Point &operator=(const Point &rhs);
	~Point();

	void	setX(const Fixed y);
	void	setY(const Fixed y);
};

#endif // POINT_HPP

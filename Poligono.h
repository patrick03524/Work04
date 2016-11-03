#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

class Point
{
private:
    int x, y;
public:
    Point(int x1 = 0, int y1 = 0);
    Point(Point &o);
    int getX() const;
    int getY() const;
    void setX(const int &x2);
    void setY(const int &y2);
};

class PointArray
{
private:
    void resize(const int &newLen);
    Point* firstPoint;
    int len;
public:
    PointArray();
    PointArray(const Point points[], const int &Size);
    PointArray(const PointArray &pv);
    ~PointArray();
    void showPoint(const int &pos);
    void pushBack(const Point &p);
    void insert(const int &position, const Point &p);
    void remove(const int &position);
    const int getSize() const;
    void clear();
    Point* get(const int &position);
    const Point* get(const int &position) const;
    
class Poligono {
private:
    static int numPoli;
    PointArray Points;
public:
    Poligono(const PointArray &pa);
    Poligono(const Point points[],const int numPoints);
    virtual double area() const = 0;
    static int getNumPoli();
    int getNumSides() const ;
    const PointArray *getPoints() const ; 
    ~Poligono();
};

class Rectangle : public Poligono {
public:
    Rectangle(const Point &a, const Point &b);
    Rectangle(const int a, const int b, const int c, const int d);
    virtual double area() const;
};

class Triangle : public Poligono{
public:
    Triangle(const Point &a, const Point &b, const Point &c);
    virtual double area () const;
};
#endif // POLIGONO_H_INCLUDED

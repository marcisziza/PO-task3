#include <iostream>
 
using namespace std;

class Rectangle;

class Point {
private:
  friend void show_info(Rectangle rec1);
  friend class Rectangle;
  double x_value, y_value;
  friend void setXY(Point &p1, double x, double y);
public:
  double get_x() {
    return x_value;
  }
  double get_y() {
    return y_value;
  }
  void set_x(double x) {
    x_value = x;
  }
  void set_y(double y) {
    y_value = y;
  }  
  void print() { //metoda wyswietlajaca na ekranie pola klasy
    cout << "x: " << get_x() << " y: " << get_y() << endl;
  }
  Point() {
    x_value = 0;
    y_value = 0;
  }
  bool is_common(Rectangle rec1);
};

class Rectangle {
private:
  friend void show_info(Rectangle rec1);
  friend class Point;
  Point bottom_left;
  double width, height;
public:
  Rectangle() {
    bottom_left.set_x(-6); bottom_left.set_y(-8);
    width = 13;
    height = 10;
  }
  Point get_apex() {
    return bottom_left;
  }
  double get_width() {
    return width;
  }
  double get_height() {
    return height;
  }  
};

class Circle {
private:
  Point center;
  int radius;
public:
  Circle() {
    center.set_x(0); center.set_y(0);
    radius = 10;
  }
  Point get_center() {
    return center;
  }
  int get_radius() {
    return radius;
  }
  bool is_tangent(Circle circle) {
    return true;
    return false;
  }
};

void setXY(Point &p1, double x, double y) { //funkcja globalna umoliwiajaca zmiane wartosci pol obiektu klasy Point
  // p1.set_x(x);
  // p1.set_y(y);
  p1.x_value = x;
  p1.y_value = y;
}

void show_info(Rectangle rec1) {
  Point apex = rec1.get_apex();

  cout << "Bottom left: (" << apex.get_x() << ", " << apex.get_y() << ")" << endl;
  cout << "Bottom right: (" << (apex.get_x() + rec1.get_width() ) << ", " << apex.get_y() << ")" << endl;
  cout << "Top right: (" << (apex.get_x() + rec1.get_width() ) << ", " << (apex.get_y() + rec1.get_height() ) << ")" << endl;
  cout << "Top left: (" << apex.get_x() << ", " << (apex.get_y() + rec1.get_height() ) << ")" << endl;
}

void show_info(Circle circle) {
  Point center = circle.get_center();

  cout << "center: (" << center.get_x() << ", " << center.get_y() << ")" << endl;
  cout << "radius: " << circle.get_radius();
}
 
int main() {
  Point p1, p2, p3;

  // cout << "p1: "; p1.print(); //utworzenie testowego punktu konstruktorem domyslnym i wypisanie go na ekranie

  setXY(p1, 5, 2); cout << "p1 after using 'setXY' function: "; p1.print();
  setXY(p2, -7, -7); cout << "p2 after using 'setXY' function: "; p2.print();
  setXY(p3, 1.25, 2.5); cout << "p3 after using 'setXY' function: "; p3.print(); 
  cout << endl;   

  Rectangle rec1;

  cout << "if p1 is placed in rec1 print '1' if not print '0': " << p1.is_common(rec1) << endl;
  cout << "if p2 is placed in rec1 print '1' if not print '0': " << p2.is_common(rec1) << endl;
  cout << "if p3 is placed in rec1 print '1' if not print '0': " << p3.is_common(rec1) << endl << endl;

  show_info(rec1); cout << endl;

  Circle circle;

  show_info(circle);
}

bool Point::is_common(Rectangle rec1) {
  Point apex = rec1.get_apex();

  if ( (get_x() >= apex.x_value && get_x() <= (apex.x_value + rec1.get_width() ) ) && (get_y() >= apex.y_value && get_y() <= (apex.y_value + rec1.get_height() ) ) )
    return true;
  return false;
}
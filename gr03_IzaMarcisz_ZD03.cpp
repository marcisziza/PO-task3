#include <iostream>
#include <cstdlib>
#include <math.h>
 
using namespace std;

class Rectangle;

class Point {
private:
  double x_value, y_value;
  friend void setXY(Point &p1, double x, double y); //deklaracja przyjazni funkcji ustawXY() z klasa Punkt
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
  bool is_common(Rectangle rec1); //deklaracja funkcji czyWspolne()
};

class Rectangle {
private:
  Point bottom_left;
  double width, height;
public:
  Rectangle(double x, double y, double w, double h) { //konstruktor parametryzujacy
    bottom_left.set_x(x); bottom_left.set_y(y);
    width = w;
    height = h;
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
  Circle(double x = 0, double y = 0 , int r = 0) { //konstruktor parametryzujacy
    center.set_x(x); center.set_y(y);
    radius = r;
  //nice
  }
  Point get_center() {
    return center;
  }
  int get_radius() {
    return radius;
  }
  void set_params(double x = 0, double y = 0 , int r = 0) { //konstruktor parametryzujacy z wartosciami domyslnymi
    center.set_x(x); center.set_y(y);
    radius = r;
  }
  double distance(Circle &cir1) { //metoda zwracajaca odleglosc miedzy srodkami dwoch okregow
    return sqrt(pow((center.get_x() - cir1.get_center().get_x()), 2) + pow(center.get_y() - cir1.get_center().get_y(), 2));
  }
  bool is_tangent(Circle circle) { //metoda czyStyczne()
    double tolerance = 10e-5;
    double dist = distance(circle); 
    if((fabs(dist - (radius + circle.get_radius())) < tolerance) || (fabs(dist - fabs(radius - circle.get_radius())) < tolerance)) {
      return true;
    }
    return false;
  }
};

void setXY(Point &p1, double x, double y) { //funkcja globalna umoliwiajaca zmiane wartosci pol obiektu klasy Point
  // p1.set_x(x);
  // p1.set_y(y);
  p1.x_value = x;
  p1.y_value = y;
}

void show_info(Rectangle& rec1) { //przeciazenie funkcji pokazInfo() dla prostokata
  Point apex = rec1.get_apex();
  
  cout << "About rectangle 'rec1': " << endl;
  cout << "Bottom left: (" << apex.get_x() << ", " << apex.get_y() << ")" << endl;
  cout << "Bottom right: (" << (apex.get_x() + rec1.get_width() ) << ", " << apex.get_y() << ")" << endl;
  cout << "Top right: (" << (apex.get_x() + rec1.get_width() ) << ", " << (apex.get_y() + rec1.get_height() ) << ")" << endl;
  cout << "Top left: (" << apex.get_x() << ", " << (apex.get_y() + rec1.get_height() ) << ")" << endl;
}

void show_info(Circle& circle) { //przeciazenie funkcji pokazInfo() dla kola
  Point center = circle.get_center();

  cout << "Showing info about circle 'circle': " << endl;
  cout << "center: (" << center.get_x() << ", " << center.get_y() << ")" << endl;
  cout << "radius: " << circle.get_radius() << endl;
}
 
int main() {
  srand(time(NULL));

  Point p1, p2, p3;

  // cout << "p1: "; p1.print(); //utworzenie testowego punktu konstruktorem domyslnym i wypisanie go na ekranie

  setXY(p1, 5, 2); cout << "p1 after using 'setXY' function: "; p1.print();
  setXY(p2, -7, -7); cout << "p2 after using 'setXY' function: "; p2.print();
  setXY(p3, 1.25, 2.5); cout << "p3 after using 'setXY' function: "; p3.print(); 
  cout << endl;   

  Rectangle rec1(-8, -6, 13, 10);

  cout << "if p1 is placed in rec1 print '1' if not print '0': " << p1.is_common(rec1) << endl;
  cout << "if p2 is placed in rec1 print '1' if not print '0': " << p2.is_common(rec1) << endl;
  cout << "if p3 is placed in rec1 print '1' if not print '0': " << p3.is_common(rec1) << endl << endl;

  show_info(rec1); cout << endl;

  Circle circle(0, 0, 10);

  show_info(circle); cout << endl;

  Circle* array = new Circle[1000]; //utworzenie dynamicznej tablicy 

  for(int i = 0; i < 1000; i++){ //przypisanie wartosci pseudolosowych wspolrzednym srodkow kol
    array[i].set_params((rand() % 41 - 20), (rand() % 41 - 20), (rand() % 20 + 1));
    if(circle.is_tangent(array[i])) {
      cout << "Circle 'circle1' and cirle " << i << " are tangent to each other" << endl;
    }
  }
}

bool Point::is_common(Rectangle rec1) { //definicja funkcji czyWspolne()
  Point apex = rec1.get_apex();

  if ( (get_x() >= apex.x_value && get_x() <= (apex.x_value + rec1.get_width() ) ) && (get_y() >= apex.y_value && get_y() <= (apex.y_value + rec1.get_height() ) ) )
    return true;
  return false;
}

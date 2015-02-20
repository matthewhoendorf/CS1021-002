#include <iostream>
using namespace std;

// Complex ADT: class description

class Complex {
 public: // member functions
  // constructors
  Complex();
  Complex(double real);
  Complex(double real, double imag);
  Complex(const Complex &c1);
  // some arithmetic and stream facilitators
  Complex add(const Complex &c1) const;
  Complex multiply(const Complex &c1) const;
  Complex subtract(const Complex &c1) const;
  Complex divide(const Complex &c1) const;
  void Insert(ostream &sout) const;

  // inspectors (get value)
  double getReal() const;
  double getImag() const;
  // mutators (set value)
  void setReal(double real);
  void setImag(double imag);
 private:
  // data members
  double realVal;
  double imagVal;
};

// Complex ADT: auxiliary operator description
Complex operator+(const Complex &c1,
		   const Complex &c2);
Complex operator*(const Complex &c1,
		   const Complex &c2);
Complex operator-(const Complex &c1,
		   const Complex &c2);
Complex operator/(const Complex &c1,
		   const Complex &c2);
Complex operator^(const Complex &c1,
		   int n);
ostream& operator<<(ostream &sout, const Complex &c2);

//IMPLEMENTATION OF THE COMPLEX CLASS

// default constructor
Complex::Complex() {
  realVal=imagVal=0;
}
// (real, imag=0) constructor
Complex::Complex(double real) {
  setReal(real);
  setImag(0);
}
// (real, imag) constructor
Complex::Complex(double real, double imag) {
  setReal(real);
  setImag(imag);
}
// get the real component
double Complex::getReal() const {
  return realVal;
}
// get the imaginary component
double Complex::getImag() const {
  return imagVal;
}
// set the real component
void Complex::setReal(double r) {
  realVal = r;
}
// set the imaginary component
void Complex::setImag(double i) {
  imagVal = i;
}
// adding Complex
Complex Complex::add(const Complex &c1) const {
  Complex sum;
  double a = getReal();
  double b = getImag();
  double c = c1.getReal();
  double d = c1.getImag();
  sum.realVal = a + c;
  sum.imagVal = b + d;
  return sum;
}
// multiplying Complex
Complex Complex::multiply(const Complex &c1) const {
  Complex mult;
  double a = getReal();
  double b = getImag();
  double c = c1.getReal();
  double d = c1.getImag();
  mult.realVal = a*c - b*d;
  mult.imagVal = a*d + c*b;
  return mult;
}
// subtracting Complex
Complex Complex::subtract(const Complex &c1) const {
  Complex sub;
  double a = getReal();
  double b = getImag();
  double c = c1.getReal();
  double d = c1.getImag();
  sub.realVal = a - c;
  sub.imagVal = b - d;
  return sub;
}
// dividing Complex
Complex Complex::divide(const Complex &c1) const {
  Complex div;
  double a = getReal();
  double b = getImag();
  double c = c1.getReal();
  double d = c1.getImag();
  div.realVal = (a*c+b*d)/(c*c+d*d);
  div.imagVal = (b*c-a*d)/(c*c+d*d);
  return div;
}
// insert function
void Complex::Insert(ostream &sout) const{
 sout << "(" << realVal << " + " << imagVal << "i)";
 return;
}
// assigning operators (+,*,-,/)
Complex operator+(const Complex &c1,
		   const Complex &c2) {
  return c1.add(c2);
}
Complex operator*(const Complex &c1,
		   const Complex &c2) {
  return c1.multiply(c2);
}
Complex operator-(const Complex &c1,
		   const Complex &c2) {
  return c1.subtract(c2);
}
Complex operator/(const Complex &c1,
		   const Complex &c2) {
  return c1.divide(c2);
}
Complex operator^(const Complex &c1,
		   int n) {
	Complex exp = c1.multiply(c1);
	for(int i = 2; i < n; i++)
		exp = exp.multiply(c1);
  return exp;
}
// inserting a Complex (i.e. printing in proper form)
ostream& operator<<(ostream &sout, const Complex &c1) {
  c1.Insert(sout);
  return sout;
}
//main program
int main(){
  cout << "\nEnter real and imaginary components of c1 followed by space: ";
  double r1,i1;
  cin >> r1 >> i1;
  Complex c1(r1,i1);
  
  cout << "Enter real and imaginary components of c2 followed by space: ";
  double r2,i2;
  cin >> r2 >> i2;
  Complex c2(r2,i2);
  
  Complex Sum = c1 + c2;
  Complex Product = c1 * c2;
  Complex Subtract = c1 - c2;
  Complex Divide = c1 / c2;
//test add, multiply, subtract and divide functions
  cout << "\nADD: " << c1 << " + " << c2 << " = " << Sum << endl;
  cout << "MULTIPLY: " << c1 << " * " << c2 << " = " << Product << endl;
  cout << "SUBTRACT: " << c1 << " - " << c2 << " = " << Subtract << endl;
  cout << "DIVIDE: " << c1 << " / " << c2 << " = " << Divide << endl;
//test Euler's formula using Complex ADT
  cout << "\nTESTING EULER'S FORMULA e^z +1 = 0: " << endl;
  cout << "USING 10th TERM TAYLOR SERIES FOR e^z..." << endl;
  Complex z(0,3.14159265359);
  Complex e_z;
  Complex euler;
  e_z = 1+z+(z^2)/2+(z^3)/6+(z^4)/24+(z^5)/120+(z^6)/720+(z^7)/5040+(z^8)/40320+(z^9)/362880+(z^8)/3628800;
  euler = e_z + 1;
  cout << e_z << " + 1 = " << euler << "\n" << endl;
  
  return 0;
}

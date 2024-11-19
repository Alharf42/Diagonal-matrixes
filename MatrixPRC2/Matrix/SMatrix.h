#pragma once
//#ifndef MATRIX_H
//#define MATRIX_H
//comment block shift alt a
//comment // ctrl k c
//uncomment // ctrl k u
#include <vector>
using std::vector;
//symmetrical matrix with two keys
//value of the matrix with its indeces
class Value
{
    const int i;
    const int j;
    double value;
public:
    Value(int i, int j, double value)
        :i(i), j(j), value(value) {}
    ~Value() {}

    int getI() const { return i; }
    int getJ() const { return j; }
    double getValue() { return value; }
    void setValue(double value) { this->value = value; }
};

class SymmetricalMatrix
{
    //symmetrical matrix is square    
    const int rows;
    //vector of pointers pointing to Value
    vector<Value*>values;
public:
    //null matrix
    SymmetricalMatrix(int rows);
    ~SymmetricalMatrix();
    //copy constructor
    SymmetricalMatrix(const SymmetricalMatrix& m);
    //deep copy assign

    double getByIndex(int i, int j) const;
    Value* getByValueIndex(int i, int j)const;
    void setByIndex(int i, int j, double value);
    void print();
    int size()const{ return rows; }
    vector<Value> operator[](int i);
    SymmetricalMatrix& operator=(const SymmetricalMatrix& m);
};

//#endif // !MATRIX_H
#include "SMatrix.h"
#include <stdexcept>
#include <iostream>
#include <vector>
//using std::cout;
using namespace std;
using std::vector;


SymmetricalMatrix::SymmetricalMatrix(int rows)
    : rows(rows)
{
    //poradi j i nezalezi; ij ji maji stejnou hodnotu
    //array of values
    
    //size of values is a factorial of rows
    //initalize empty values with it
    //Value** values=nullptr;
    //vector<Value*>values;

    for (int ii = 0; ii <= rows-1; ii++)
    {
        //j index starts at i
        //thus avoids two same combinations of j and i
         //no need to check if a combination of ii jj was already used
        for (int jj = ii; jj <= rows-1; jj++)
        {
            Value* v = nullptr;
              v = new Value(ii, jj, 0);
                //values[ii] = v;
                this->values.push_back(v);
            
        }
    }


}
SymmetricalMatrix::~SymmetricalMatrix()
{
    for (Value* valuePtr : this->values)
    {
        delete valuePtr;  
    }
    this->values.clear();


}
//returns double value for Value at inde
double SymmetricalMatrix::getByIndex(int i,int j) const
{
    for(Value* valuePtr: this->values)
    {
        Value value = *valuePtr;
        if ((value.getI() == i && value.getJ() == j) || (value.getI() == j && value.getJ() == i))
        {
            
            return valuePtr->getValue();
        }
        else
        {
            continue;
        }
    }
   //throw invalid_argument("No value at selected indeces");
    return 0;
    
}
//returns whole Value
Value* SymmetricalMatrix::getByValueIndex(int i, int j) const 
{
    for (Value* valuePtr : this->values)
    {
        if (valuePtr == nullptr) { return nullptr; }
        else {

            Value value = *valuePtr;
            if ((value.getI() == i && value.getJ() == j) || (value.getI() == j && value.getJ() == i))
            {
                
                return valuePtr;
            }
            else
            {
                continue;
            }
            
        }

    }
    //throw invalid_argument("No value at selected indeces");
    return nullptr;

}

//changes double value for Value at index numbers
void SymmetricalMatrix::setByIndex(int i,int j,double value)
{
    if (i < this->rows && j < this->rows)
    {
        this->getByValueIndex(i, j)->setValue(value);
        this->getByValueIndex(j, i)->setValue(value);
    }
    else return;
}

void SymmetricalMatrix::print()
{
    for (int i = 0; i <= this->rows-1; i++)
    {
        for (int j = 0; j <= rows-1; j++)
        {
            if ((double)this->getByIndex(i, j))
            {
                cout << this->getByIndex(i, j)<<" ";
            }
            else if (this->getByIndex(i, j) == 0)
            {
                cout << 0<<" ";
            }
            /*else if(this->getByIndex(j,i))
            {
                cout << this->getByIndex(j, i)<<" ";

            }*/
        }
        cout << endl;
    }
    cout << endl;

}
//returns all vallues where index for rows is equal to i
vector<Value> SymmetricalMatrix::operator[](int i)
{
    vector<Value>row;
    for (int j = 0; j < this->rows; j++)
    {
        for (Value* valuePtr : this->values)
        {
            if (valuePtr->getI() == i && valuePtr->getJ() == j)
            {
                row.push_back(*valuePtr);
            }
        }
    }
    return row;
}
SymmetricalMatrix& SymmetricalMatrix::operator=(const SymmetricalMatrix& m)
{
    if (this != &m)
    {
        if (m.rows == this->rows)
        {
            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->rows; j++)
                {
                    double val = m.getByIndex(i, j);
                    this->setByIndex(i, j, val);
                }
            }
        }
        else
        {
            //throw invl
        }
    }
    return *this;
}
//deep copy constructor
SymmetricalMatrix::SymmetricalMatrix(const SymmetricalMatrix& m)
    :rows(m.rows)
{
    for (int ii = 0; ii <= rows - 1; ii++)
    {
        for (int jj = ii; jj <= rows - 1; jj++)
        {
            //v = new Value(ii, jj, 0);
            // shallow copy
            //v = m.getByValueIndex(ii, jj);
            //deep copy newly constructed
            Value* mv = m.getByValueIndex(ii, jj);
            Value* v = new Value(mv->getI(), mv->getJ(), mv->getValue());
            this->values.push_back(v);

        }
    }
}
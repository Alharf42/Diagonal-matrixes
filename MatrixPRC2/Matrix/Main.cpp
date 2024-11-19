#include<iostream>
#include "SMatrix.h"
#include "Ops.h"
#include <vector>
using namespace std;


void printVector(vector<vector<double>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	SymmetricalMatrix m = SymmetricalMatrix(3);
	m.print();
	m.setByIndex(0, 1, 1);
	m.setByIndex(2,3,5);
	m.setByIndex(0, 3, 4);
	m.setByIndex(0, 0, 6);

	m.print();
	
	
	SymmetricalMatrix n = SymmetricalMatrix(3);
	n.setByIndex(0, 1, 2);
	n.setByIndex(2, 3, 8);
	n.setByIndex(0, 3, 10);
	n.setByIndex(0, 0, 3);
	n.print();

	vector < vector<double >> commonM  =
	{ 
		{1, 2, 3},
		{1, 2, 2},
		{2, 2, 3}
	};
	printVector(commonM);
	vector < vector<double >> comM =
	{
		{1, 2, 3},
		{1, 2, 2},
		{2, 2, 3}
	};
	//struct for handling vectors in generic template functions
	matrix::vec ns;
vector<vector<double>>add=	addition<vector<vector<double>>>(comM,commonM, ns);
printVector(add);
vector<vector<double>>mult = multiplyScalar<vector<vector<double>>,double>(comM, 5, ns);
printVector(mult);
matrix::sMatrix nss;
SymmetricalMatrix addS = SymmetricalMatrix(m.size());
addS = addition<SymmetricalMatrix>(m,n,nss);
addS.print();
cout << "1"<<endl;
SymmetricalMatrix multS = SymmetricalMatrix(m.size());
cout << "2"<<endl;
multS = multiplyScalar<SymmetricalMatrix,double>(m,5,nss);
cout << "3" << endl;
multS.print();
cout << "4" << endl;
SymmetricalMatrix test = SymmetricalMatrix(m.size());
for (int i = 0; i < m.size(); i++)
{
	for (int j = 0; j < m[0].size(); j++)
	{
		test.setByIndex(i, j, m.getByIndex(i, j) * 5);
	}
}
test.print();
SymmetricalMatrix test2 = SymmetricalMatrix(m.size());
test2 = m;
test2.print();
return 0;
}

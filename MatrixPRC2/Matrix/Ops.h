#pragma once
#include "SMatrix.h"
#include <vector>

//namespace of structures->can be passed to funtion
//creates generic overloaded functions for vector<vector> and SymmetricalMatrix
//to be used in generic template funtion
namespace matrix{
	//namespace
	struct sMatrix
	{
		double get(int i, int j, const SymmetricalMatrix& m) {return m.getByIndex(i, j); }
		void set(int i, int j, double value, SymmetricalMatrix& m) { m.setByIndex(i, j, value); }
		SymmetricalMatrix matrix(int rows, int args...) { return SymmetricalMatrix(rows); }
	};
	//namespace
	struct vec
	{
		double get(int i, int j, vector<vector<double>> v) { return v[i][j]; }
		void set(const int i, const int j,const  double value, vector<vector<double>>&v) {v[i][j] = value; }
		vector<vector<double>> matrix(int i, int j) { return vector<vector<double>>(i, vector<double>(j));
		}
	};
}




//generic template funtions 
//typename Ns represents the required structure in matrix namespace
// to handle each type of matrix
// 
//matrix addition
template<typename matrix, typename Ns>
matrix addition( matrix A, matrix B, Ns ns)
{
	//using namespace ns;
	//matrix c (A.size(), typename matrix::value_type(A[0].size()));
	matrix c = ns.matrix(A.size(),A[0].size());
	if (A.size() == B.size() && A[0].size() == B[0].size())
	{
		//std::cout << "size of columns A " << A[0].size() << std::endl;
		int col = A[0].size();
		for (int i = 0; i < A.size(); i++)
		{
			//std::cout << "index i " << i << std::endl;
			
			for (int j = 0; j < col; j++)
			{
				//std::cout << " before val "<<std::endl;
				//c[i][j] = A[i][j] + B[i][j];
				double val = ns.get(i, j, A) + ns.get(i, j, B);

				//std::cout << "Setting value at (" << i << ", " << j << ") to " << val << std::endl;
				ns.set(i, j, val,c);
				//std::cout << "Setting value at (" << ns.get(i,j,c) << ") to " << val << std::endl;
			}
		}
		return c;
	}
	else
	{
		throw std::invalid_argument("Matrices do not have same size");
	}

}
//scalar multiplication
template<typename matrix, typename T,typename Ns>
matrix multiplyScalar(matrix A, T scalar, Ns ns)
{
	matrix b = ns.matrix(A.size(), A[0].size());
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			T val = scalar * ns.get(i, j, A);
			ns.set(i, j, val, b);
		}
	}
	return b;
}

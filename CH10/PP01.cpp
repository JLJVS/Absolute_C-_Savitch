#include <iostream>
using namespace  std;

typedef int* DoubleArrayPtr;

class TwoD{
    private:
        double* arrPointer;
        int MaxRows;
        int MaxCols;
    public:
        TwoD(); // defaults to a 10x10 matrix
        TwoD(int rows, int cols);
        ~TwoD();
        TwoD(const TwoD& twoDObject);
};

TwoD::TwoD(int rows, int cols){
    arrPointer = new double[rows*cols];
    MaxRows = rows;
    MaxCols = cols;
}

TwoD::TwoD() : TwoD(10,10){}

TwoD::~TwoD(){
    delete [] arrPointer;
}

TwoD::TwoD(const TwoD& twoDObject) : TwoD(twoDObject.MaxRows, twoDObject.MaxCols){
    for (int i {}; i < MaxRows*MaxCols; i++){
        *(arrPointer+i) = *(twoDObject.arrPointer+i);
    }
}
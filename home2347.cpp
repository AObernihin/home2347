#include <iostream>
using namespace std;

void addColumn(int**& array, int rows, int cols, int position, int* newColumn) {
    
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArray[i] = new int[cols + 1];
    }

    
    for (int i = 0; i < rows; i++) {
        int newColIndex = 0; // индекс для нового массива
        for (int j = 0; j <= cols; j++) {
            if (j == position) {
              
                newArray[i][j] = newColumn[i];
            }
            else {
                
                newArray[i][j] = array[i][newColIndex];
                newColIndex++;
            }
        }
    }

   
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

   
    array = newArray;
}

void removeColumn(int**& array, int rows, int cols, int position) {

    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArray[i] = new int[cols - 1];
    }


    for (int i = 0; i < rows; i++) {
        int newColIndex = 0;
        for (int j = 0; j < cols; j++) {
            if (j != position) {
                newArray[i][newColIndex] = array[i][j];
                newColIndex++;
            }
        }
    }


    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;


    array = newArray;
}

void shiftRow(int* row, int cols, int shift, bool direction) {
    int* temp = new int[cols];

    for (int i = 0; i < cols; i++) {
        int newIndex = direction ? (i + shift) % cols : (i - shift + cols) % cols;
        temp[newIndex] = row[i];
    }

    for (int i = 0; i < cols; i++) {
        row[i] = temp[i];
    }

    delete[] temp;
}

void shiftColumn(int** array, int rows, int colIndex, int shift, bool direction) {
    int* temp = new int[rows];

    for (int i = 0; i < rows; i++) {
        int newIndex = direction ? (i + shift) % rows : (i - shift + rows) % rows;
        temp[newIndex] = array[i][colIndex];
    }

    for (int i = 0; i < rows; i++) {
        array[i][colIndex] = temp[i];
    }

    delete[] temp;
}

int main() {
    int rows = 3, cols = 3;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols] { i* cols + 1, i* cols + 2, i* cols + 3 };
    }

    
    int newColumn[] = { 10, 20, 30 };
    int position = 1; 

    addColumn(array, rows, cols, position, newColumn);

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols + 1; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    cout << "===========================" << endl;
//=====================================
    int rows1 = 3, cols1 = 4;
    int** array1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        array1[i] = new int[cols1] { i* cols1 + 1, i* cols1 + 2, i* cols1 + 3, i* cols1 + 4 };
    }

    int position1 = 1;

    removeColumn(array1, rows1, cols1, position1);

    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1 - 1; j++) {
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows1; i++) {
        delete[] array1[i];
    }
    delete[] array1;
    cout << "============================" << endl;
    //===========================
    int rows2 = 3, cols2 = 4;
    int** array2 = new int* [rows2];
    for (int i = 0; i < rows; i++) {
        array2[i] = new int[cols2] { i* cols2 + 1, i* cols2 + 2, i* cols2 + 3, i* cols2 + 4 };
    }

    int shift = 1;
    bool direction = true; 

    
    for (int i = 0; i < rows2; i++) {
        shiftRow(array2[i], cols2, shift, direction);
    }

    
    int columnToShift = 2;
    shiftColumn(array2, rows2, columnToShift, shift, direction);

    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows2; i++) {
        delete[] array2[i];
    }
    delete[] array2;
}




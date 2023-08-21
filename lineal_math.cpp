#include <iostream>
#include <vector>
#include <cmath>
using matrix = std::vector<std::vector<int>>;

matrix get_minor(int a, int b, matrix mtrx) {
    matrix new_mtrx(mtrx.size() - 1, std::vector<int>(mtrx.size() - 1));
    for (int i = 0, r = 0; i < mtrx.size(); i++)
    {
        if (i != a) {
            for (int j = 0, c = 0; j < mtrx.size(); j++)
            {
                if (j != b) {
                    new_mtrx[r][c] = mtrx[i][j];
                    c++;
                }
            }
            r++;
        }
    }
    return new_mtrx;
}

int get_determinant(matrix mtrx) {
    if ((int)mtrx.size() == 2){
        return mtrx[0][0] * mtrx[1][1] - mtrx[0][1] * mtrx[1][0];
    }
    int res = 0;
    for (int i = 0; i < (int)mtrx.size(); i++)
    {
        res += mtrx[0][i] * (int)std::pow(-1, i) * get_determinant(get_minor(0, i, mtrx));
    }
    return res;
}

int main(){
        matrix arr = {{1, 3, 8, 9, 12, 15}, {1, 3, 2, 2, 3, 4}, {2, 5, 6, 3, 2, 1}, {12, 124, 12, 54, 23, 76}, {11, 1234, 1245, 45, 67, 87}, {34534, 23432, 2345435, 234, 234, 25}};
        int res = get_determinant(arr);
        std::cout << res << std::endl;
        return 0;
}
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        int length = matrix.size() * matrix[0].size(), 
            mSize = matrix.size(),
            lSize = matrix[0].size();

        for (int layer = 0; ans.size() < length; layer++){
            //top
            for (int j = layer; j < lSize - layer; ++j){
                ans.push_back(matrix[layer][j]);
            }

            if (layer + 1 >= mSize - layer) break;

            //right
            for (int j = layer + 1; j < mSize - layer; ++j){
                ans.push_back(matrix[j][lSize - layer - 1]);
            }

            if (lSize - layer < layer + 2) break;
            //bottom
            for (int j = lSize - layer - 2; j >= layer; --j){
                ans.push_back((matrix[mSize - layer - 1][j]));
            }


            for (int j = mSize - layer - 2; j > layer; --j){
                ans.push_back(matrix[j][layer]);
            }
        }

        return ans;
    }
};

int main(){
    int row, col, count;
    row = 4;
    col = 4;
    count = 0;

    cout << "Orgin:\n";

    vector<vector<int> > matrix(row);
    for (int i = 0; i < row; ++i){
        vector<int> line(col);
        for (int j = 0; j < col; ++j){
           line[j] = (++count);
           cout << count << " ";
        }
        matrix[i] = line;
        cout << endl;
    }

    Solution s;
    vector<int> ans = s.printMatrix(matrix);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n ";

    return 0;
}


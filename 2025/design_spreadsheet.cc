class Spreadsheet {
    vector<vector<int>> sheet;
    int getRowIndex(const string& cell) {
        return stoi(cell.substr(1)) - 1;
    }
    int getColIndex(const string& cell) {
        return cell[0] - 'A';
    }
public:
    Spreadsheet(int rows) {
        sheet.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int row = getRowIndex(cell);
        int col = getColIndex(cell);
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = getRowIndex(cell);
        int col = getColIndex(cell);
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        int splitIndex = formula.find('+');
        string part0 = formula.substr(1, splitIndex - 1);
        string part1 = formula.substr(splitIndex + 1);

        int row0 = -1;
        int col0 = -1;
        int val0 = -1;
        int row1 = -1;
        int col1 = -1;
        int val1 = 0;

        if (part0[0] >= 'A' && part0[0] <= 'Z') {
            row0 = getRowIndex(part0);
            col0 = getColIndex(part0);
            val0 = sheet[row0][col0];
        } else {
            val0 = stoi(part0);
        }

        if (part1[0] >= 'A' && part1[0] <= 'Z') {
            row1 = getRowIndex(part1);
            col1 = getColIndex(part1);
            val1 = sheet[row1][col1];
        } else {
            val1 = stoi(part1);
        }

        return val0 + val1;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
 // 112 ms
 // 192.51 MB
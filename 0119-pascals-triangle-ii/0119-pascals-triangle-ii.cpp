class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pt;
        
        /*
        Pascal's triangle can be expressed through combinations.
        If rowIndex = 2, [2C0, 2C1, 2C2] = [1, 2, 1]
        
        nCr-1   = n(n-1)(n-2)...(n-r-1)      / 1(2)(3)...(r-1)
        nCr     = n(n-1)(n-2)...(n-r-1)(n-r) / 1(2)(3)...(r-1)(r)
        nCr     = nCr-1 * (n-r / r)
        */
        
        long k = 1; //k = rowIndex C 0
        for(int i = 0; i <= rowIndex; i++)
        {
            pt.push_back(k);
            k = k * (rowIndex - i) / (i + 1);
        }
        
        return pt;
    }
};
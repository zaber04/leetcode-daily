class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        // look ahead -- suggest upto 3 products with matching prefix dictionary style
        vector<vector<string>> matches; // [i][0-2]
        // matches.resize(3);
        
        // sort the input array to make fuzzy matching easier
        sort(products.begin(), products.end());
        
        // to be used to generate suggestion array in each step
        vector<string> temp;
        
        string current = ""; // hold each character
        int len = products.size(); // get prduct count
        int cLen = 0;
        int pushed = 0;
        
        // matches.resize(len);
    
        // loop through the search word
        for (auto it: search) {
            current += it; // append another character
            // reset temp everytime
            temp.clear();
            // cLen++;
            // pushed = 0;
            
            // now search
            for (int i = 0; i < len; i++) {
                string newProduct = products[i];
                
                // is our current string a substring (at beginning) of this product?
                if (newProduct.substr(0, current.length()) == current) {
                    temp.push_back(newProduct);
                }

                if (temp.size() == 3) {
                    break;
                }
            }
            

            matches.push_back(temp);
        }
        
        return matches;
    }

    
};
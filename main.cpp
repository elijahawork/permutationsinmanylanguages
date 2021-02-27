#include <iostream>
#include <vector>

using namespace std;

// utility function
template <class T>
void printVector(vector<T> vec) {
    for (T e : vec) cout << e << endl;
}

// actual permutation function
vector<string>* permute(string s) {
    // if there are only two letters, then we know there are only two combinations
    // AB and BA, where A and B represent the characters at position 1 and 2
    if (s.size() == 2) {
        vector<string> *permutations = new vector<string>(2);

        // to the vector we add both of the two base permutations        
        (*permutations)[0] = string(1,s[0])+s[1];
        (*permutations)[1] = string(1,s[1]) + s[0];
        // return the result
        return permutations;
    } else {
        // there are an unknown amount of permutations
        vector<string> *permutations = new vector<string>();
        
        for (int i = 0; i < s.size(); i++) {
            // this is our pivot character
            // this is the character to whom everything else will change
            char pivotCharacter = s[i];
            // we get the entire string sans the pivot character
            string stringSansPivot = s.substr(0,i) + s.substr(i+1);
            // we find all the permutations of the string sans pivot
            vector<string> *sansPivotPermutations = permute(stringSansPivot);
            for (string permutation : *sansPivotPermutations) {
                // we add the pivot character to the beginning of every permutation 
                // sans the pivot
                string form = pivotCharacter + permutation;
                (*permutations).push_back(form);
            }
        }

        return permutations;
    }
}

// entry point
int main() {
    // take in the value to permute
    string strToPermute;
    cin >> strToPermute;

    // permute
    vector<string> *res = permute(strToPermute);

    // print   
    printVector(*res);

}

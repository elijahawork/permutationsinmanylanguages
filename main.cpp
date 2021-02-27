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
    // if there are no characters, return an empty vector
    if (s.size() == 0) {
        return new vector<string>(0);
    // if there is only one character, return that one character
    // there is a choice to make the base case 2, and that would decrease the stack size
    // during recursion but would also be more to type as there would be both a case for 1
    // in the case that someone only passes one char, and one for two
    // so the second one would be redunant
    } else if (s.size() == 1) {
        vector<string> *permutations = new vector<string>(1);
        (*permutations)[0] = s;
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

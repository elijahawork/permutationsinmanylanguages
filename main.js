// actual permute function
function permute(str) {
    // if there are no characters, return an empty vector
    if (str.length == 0) return [];
    // if there is only one character, return that one character
    // there is a choice to make the base case 2, and that would decrease the stack size
    // during recursion but would also be more to type as there would be both a case for 1
    // in the case that someone only passes one char, and one for two
    // so the second one would be redunant
    else if (str.length == 1) return [str];
    else {
        // there are an unknown amount of permutations
        const permutations = [];
      
        for (let i = 0; i < str.length; i++) {
            // this is our pivot character
            // this is the character to whom everything else will change
            const pivotChar = str[i];
          
            // we get the entire string sans the pivot character
            const sansChar = str.substring(0,i) + str.substring(i + 1);
            const sansPermutations = permute(sansChar);
            for (const permutation of sansPermutations) 
                // we add the pivot character to the beginning of every permutation 
                // sans the pivot
              permutations.push(pivotChar + permutation);
        }
        return permutations;
    }
}

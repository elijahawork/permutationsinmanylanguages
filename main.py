# actual permutation function
def permute(s):
    # if s is empty return empty list
    if len(s) == 0:
        return []
    # if s is only one letter return the only permutation i.e. the one letter in a list
    elif len(s) == 1:
        return [s]
    else:
        # create list to hold permutations
        permutations = []
        
        # iterate through every char
        for i in range(len(s)):
            # get pivot (still character)
            pivotChar = s[i]
            # get every char but the pivot
            strSansPivot = s[0:i] + s[i+1:]
            # get the permutations for everything without the pivot
            sansPermutations = permute(strSansPivot)

            # add the pivot to all the permutations that were without it
            for permutation in sansPermutations:
                permutations.append(pivotChar + permutation)

        # return :)
        return permutations

# print out the permutations of the input
print(permute(input()))

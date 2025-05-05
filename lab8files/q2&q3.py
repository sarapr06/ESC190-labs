##q2.a: basically, you need 1+min(OPT(n-1), ... OPT(n-n))
##for all denominations

##q2.b
#initialize an array OPT of size n+1 initilaized with a large number
#want the minimum
#opt[0]=0
#iterate over all amounts from 1 to n to get OPT[i]
def compute_opt(denom, money):
    OPT = [float('inf')] * (money + 1) # initialize OPT array with infinity
    OPT[0] = 0  # Base case: 0 coins needed for amount 0
    for amount in range(1, money + 1): #from 1, up to and INCLUDING money
        for coin in denom: #for each coin
            if amount >= coin:  ##checks if we can actually use the coin (e.g. how many 4's fit into 8?)
                OPT[amount] = min(OPT[amount], 1 + OPT[amount - coin]) #this represents 
    return OPT 


##q2.c
#need to backtrack to find the actual coins used
#start from n, pick first coin that minimizes 1+OPT(n-denom) and subtract form n
#repeat until n==0
#store answers in a list
def get_coins(denom, money, OPT):
    coins = []
    while money > 0: #while valid
        for coin in sorted(denom):  # if list is NOT already sorted
            if (money >= coin) and (OPT[money] == 1 + OPT[money - coin]):#if the target amount WORKS (same algo as in compute_opt)
                coins.append(coin)
                money -= coin #checks coin amount
                break  #  to the next coin selection

    return coins
OPT=compute_opt([1,4,5,10], 8)
print(OPT)
print(get_coins([1,4,5,10], 8,OPT)) #gives 2 for 8, which is correct


#q3
#need to check if a given string s can be broken into words
#if a word in wordDict is a rpefix of s, then we should check fi the rEAMING part of s can be
#segmented too

#framework:
#define dp[i] as true if s[:i] (first i characters) CAN be segemented
#START with dp[0]=True
#check all postiitons i and see if any word in wordDict ends at i and allows segmentation
def can_seg(s, wordDict):
    n = len(s)
    dp = [False] * (n + 1) #first off ALL false
    dp[0] = True  # base case: empty string is always segmentable
    for i in range(1, n + 1):  #over the length of hte string
        for word in wordDict:  
            if i >= len(word) and dp[i - len(word)] and s[i - len(word):i] == word:
                #if i is GREATER than the length of the word
                #if dp at i minus length of the word is TRUE (meaning the length of the string is valid)
                #if the string from i-len(word) UP to i is the word
                dp[i] = True #it passes all cases, now true
                break
    return dp[n]  # the last value tells us if the entire string is segmentable

print(can_seg("catsandog", ["cats", "dog", "sand", "and", "cat"]))
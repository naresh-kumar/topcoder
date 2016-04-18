// https://www.codechef.com/MARCH13/status/TOTR,nemausus
// https://www.codechef.com/viewplaintext/1890676
import string

a,b = raw_input().split()
t = int(a)
translation = str(b)
dictionary = {'_':' '}
allTheLetters = string.lowercase
for i in range(26):
    dictionary[allTheLetters[i]] = translation[i]
    dictionary[allTheLetters[i].upper()] = translation[i].upper()

for i in range(t):
    inp = list(str(raw_input()))
    length = len(inp)
    for i in range(length):
        try:
            inp[i] = dictionary[inp[i]]
        except KeyError:
            dictionary[inp[i]] = inp[i]
    print "".join(inp)




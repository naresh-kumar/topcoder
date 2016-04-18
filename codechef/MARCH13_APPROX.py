// https://www.codechef.com/MARCH13/status/APPROX,nemausus
// https://www.codechef.com/viewplaintext/1892170
import sys

ans = "415926530119026040722614947737296840070086399613316"
length = len(ans)

t = int(raw_input())
while t > 0:
    k = int(raw_input())
    if k > 1:
        sys.stdout.write("3.1")
        k = k - 1
        while k > 0:
            if k > length:
                sys.stdout.write(ans)
            else:
                sys.stdout.write(ans[0:k])
            k = k - length
    elif k == 1:
        print "3.1"
    else:
        print "3"
    t =  t - 1


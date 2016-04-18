import os
import sys
import urllib2
import re
import HTMLParser

f = open('codechef.txt')
url_base = 'https://www.codechef.com'
username = 'nemausus'
for line in f.readlines():
    url = ""
    try:
        url = url_base + line.rstrip()
        parts = re.split('(/|,)', line)
        filename = parts[4] if parts[2] == 'status' else parts[2] + "_" + parts[6]
        text = urllib2.urlopen(url).read()
        match = re.search('>(\d{5,7})<', text)
        sol_url = url_base + '/viewplaintext/' + match.group(1)
        code = urllib2.urlopen(sol_url).read()
        code = code[5:-6]
        code = HTMLParser.HTMLParser().unescape(code)
        out = open(filename + '.cpp', 'w')
        out.write('// ' + url + '\n')
        out.write('// ' + sol_url + '\n')
        out.write(code)
        out.close()
    except:
        print "ERROR", url
f.close()

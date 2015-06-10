import os
import sys
import re
import filecmp

walk_dir = sys.argv[1]
target = sys.argv[2]

print('walk_dir ' + os.path.abspath(walk_dir))
print('target ' + os.path.abspath(target))
pattern1 = re.compile('.*\.jpg', re.IGNORECASE)
pattern2 = re.compile('.*\.jpeg', re.IGNORECASE)

def isImage(filename):
    return pattern1.match(filename) or pattern2.match(filename)

targets = []
for root, subdirs, files in os.walk(target):
    for filename in files:
        if (isImage(filename)):
            file_path = os.path.join(root, filename)
            targets.append(file_path)

for root, subdirs, files in os.walk(walk_dir):
    for filename in files:
        if (isImage(filename)):
            file_path = os.path.join(root, filename)
            for f in targets:
                if (filecmp.cmp(f, file_path)):
                    print('\t- %s == %s' % (f, file_path))

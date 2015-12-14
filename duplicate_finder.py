import os
import sys
import re
import filecmp
import numpy as np
import cv2

if len(sys.argv) < 3:
    print("Usage: duplicate_finder.py <source> <target> [--skip_stat] [--delete]")
    print("  Check if all image files in <source> are present in <target> or not.")
    sys.exit()

source_dir = sys.argv[1]
target_dir = sys.argv[2]
skip_stat = False
delete = False
if "--skip_stat" in sys.argv:
    skip_stat = True
if "--delete" in sys.argv:
    delete = True

print('Source directory: ' + os.path.abspath(source_dir))
print('Target directory: ' + os.path.abspath(target_dir))

pattern1 = re.compile('.*\.jpg', re.IGNORECASE)
pattern2 = re.compile('.*\.jpeg', re.IGNORECASE)
pattern3 = re.compile('.*\.png', re.IGNORECASE)

def isImage(filename):
    return pattern1.match(filename) or pattern2.match(filename) or pattern3.match(filename)

def mse(imageA, imageB):
    # the 'Mean Squared Error' between the two images is the
    # sum of the squared difference between the two images;
    # NOTE: the two images must have the same dimension
    err = np.sum((imageA.astype("float") - imageB.astype("float")) ** 2)
    err /= float(imageA.shape[0] * imageA.shape[1])

    # return the MSE, the lower the error, the more "similar"
    # the two images are
    return err

source_files = []
for root, subdirs, files in os.walk(source_dir):
    for filename in files:
        if (isImage(filename)):
            file_path = os.path.join(root, filename)
            source_files.append(file_path)

target_files = []
for root, subdirs, files in os.walk(target_dir):
    for filename in files:
        if (isImage(filename)):
            file_path = os.path.join(root, filename)
            target_files.append(file_path)

print("Source files: %d" % len(source_files))
print("Target files: %d" % len(target_files))
match = 0
mismatch = 0
for source_file in source_files:
    nomatch = True
    for target_file in target_files:
        if (skip_stat or filecmp.cmp(source_file, target_file)):
            simage = cv2.imread(source_file)
            timage = cv2.imread(target_file)
            if simage.shape == timage.shape and mse(simage, timage) == 0.0:
                match = match + 1
                print('\t- %s == %s' % (source_file, target_file))
                nomatch = False
                if delete:
                    os.remove(source_file)
                break;
            elif not skip_stat:
                mismatch = mismatch + 1
                print('\t- %s == %s' % (source_file, target_file))
                nomatch = False
    if nomatch:
        print('\t- %s is not found' % (source_file))

print("Source files: %d" % len(source_files))
print("Target files: %d" % len(target_files))
print("Total matches: %d" % match)
print("Total mismatches: %d" % mismatch)

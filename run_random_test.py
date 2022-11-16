import os
import sys

args = sys.argv

os.system('cd B06204039' + ' && make')
for i in range(1, 2000):
    input_file = "./random_test/random" + str(i) + ".dat"
    out_file = "./random_test/random" + str(i) + "_myans.dat"
    print('./B06204039/bst ' + input_file + " " + out_file)
    os.system('./B06204039/bst ' + input_file + " " + out_file)

from binarytree import bst
import random
import numpy as np
import struct

for tc in range(1, 2000):
    data_q = ""
    data_a = ""
    nt = random.choice(range(1, 11))
    data_q += (str(nt) + "\n")
    for ntn in range(nt):
        h = random.choice(range(0, 10))
        root = bst(height = h)
        num = len([i for i in root.values if i is not None])
        rn = random.sample(range(-500, 1001), num)
        random.shuffle(rn)

        count = 0
        for i in root:
            i.value -= 500
            count += 1

        height = root.height + 1
        size = root.size
        data_q += (str(size) + "\n")
        
        postorder = root.postorder
        postorder = [str(i.value) for i in postorder]
        postorder = ' '.join(postorder)
        data_q += (str(postorder) + "\n")
        
        preorder = root.preorder
        preorder = [str(i.value) for i in preorder]
        preorder = ' '.join(preorder)
        data_a += (str(preorder) + "\n")
        data_a += (str(height) + "\n")
        
        level_max = []
        for l in root.levels:
            l = [i.value for i in l]
            level_max.append(str(max(l)) + "\n")
        
        level_max = ''.join(level_max)
        data_a += (str(level_max))
    
    with open('./random_test/random' + str(tc) + '.dat', 'wt') as file:  
        file.write(data_q)
    
    with open('./random_test/random' + str(tc) + '_ans' + '.dat', 'wt') as file:  
        file.write(data_a)
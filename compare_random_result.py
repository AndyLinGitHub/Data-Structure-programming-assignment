import os
ans = []
myans = []
path = "./random_test/"
for filename in os.listdir(path):
    if "_ans" in filename:
        ans.append(filename)
        
    if "_myans" in filename:
        myans.append(filename)

for i, j in zip(ans, myans):
    print(i, j)
    with open(os.path.join(path + i), 'rt') as file:  
        a = file.readlines()
        
    with open(os.path.join(path + j), 'rt') as file:  
        m = file.readlines()
    
    if not (len(a) == len(m)):
        raise ValueError("Output Length Error")
        
    
    for h, q in zip(a, m):
        #print(h.strip(), q.strip())
        if not h.strip() == q.strip():
            raise ValueError("Output Value Error")

    print("Correct")
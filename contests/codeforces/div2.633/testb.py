import sys

infile = sys.argv[1]
with open(infile, 'r') as fr:
    lines = fr.readlines()

assert len(lines) == 1, "WHOOPS"

s = [int(i) for i in lines[0].split()]
d = []
for i in range(len(s) - 1):
    d.append(abs(s[i] - s[i + 1]))

#print(d)
good = True
currd = 0
for i in range(len(d)):
    if i == 0: 
        currd = d[i]
        continue

    if d[i] < currd:
        good = False
        print(f"NOPE at {i}")
        break

    curr = d[i]

if good:
    print("YAY")


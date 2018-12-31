import sys

ifilename = sys.argv[1]
ifile = open(ifilename, "r")

lines = []
for line in ifile:
    lines.append(line)
ifile.close()

hexstr = []
for line in lines:
    if line[0] != ':':
        print("expected RECORD MARK ':' not found")
        continue
    RECLEN = int(line[1:3], 16)
    DATA = line[9:(9+2*RECLEN)]
    for i in range(0, len(DATA), 2):
        hexstr.append(int(DATA[i:(i+2)], 16))
hexstr = hexstr[2:]

string = ""
for c in hexstr:
    if c == 0:
        break
    string += chr(c)

ofile = open("log.txt", "w")
ofile.write(string)
ofile.close()

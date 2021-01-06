from collections import OrderedDict

no_lines = int(input())
words = OrderedDict()

for i in range(no_lines):
    key = input()
    if key in words.keys():
        words[key] += 1
    else:
        words[key] = 1

print(len(words.keys()))

for k in words:
    print(str(words[k]) + " ", end="")

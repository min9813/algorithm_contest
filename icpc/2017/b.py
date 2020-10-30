answers = []
while True:
    s1 = input()
    if s1 == ".":
        break
    s2 = input()
    splitted1 = s1.split('\"')
    splitted2 = s2.split('\"')

    skip = False
    if(len(splitted1) == len(splitted2)):
        num_diff = 0
        for idx, content1 in enumerate(splitted1):
            content2 = splitted2[idx]
            if idx % 2 > 0:
                if(content1 == content2):
                    continue
                else:
                    num_diff += 1
                    if(num_diff > 1):
                        answers.append("DIFFERENT")
                        skip = True
                        break
            else:
                if content1 != content2:
                    answers.append("DIFFERENT")
                    skip = True
                    break
        if skip:
            continue
        else:
            if num_diff == 1:
                answers.append("CLOSE")
            else:
                answers.append("IDENTICAL")
    else:
        answers.append("DIFFERENT")

for ans in answers:
    print(ans)
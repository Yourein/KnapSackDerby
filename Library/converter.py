import json

f = json.load(open("normalspeed.json", mode = 'r', encoding='utf-8'))

output = open("cnormalspeed.json", mode = 'w', encoding='utf-8')

motherdic = {"Skill":[]}

for i in f:
    skill = dict()
    skill["name"] = i
    skill["score"] = f[i]
    motherdic["Skill"].append(skill)

print(motherdic)

json.dump(motherdic, output, ensure_ascii=False, indent=4, sort_keys=True, separators=(',', ': '))
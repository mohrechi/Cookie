import os

lang_file = {}
lang_line = {}
exp_map = {
    'cpp': 'C++',
    'c': 'C',
    'java': 'Java',
    'py': 'Python',
    'rb': 'Ruby',
    'scala': 'Scala',
    'sh': 'Shell',
    'sql': 'SQL',
    'go': 'Go',
    'pas': 'Pascal',
    'php': 'PHP',
    'hs': 'Haskell',
}

def count_num(path):
    global lang_file
    global lang_line
    file_num = 0
    line_num = 0
    for dir_name in os.listdir(path):
        file_path = os.path.join(path, dir_name)
        if os.path.isdir(file_path):
            dir_file_num, dir_line_num = count_num(file_path)
            file_num += dir_file_num
            line_num += dir_line_num
        else:
            with open(file_path) as file_handle:
                current_line_num = len(file_handle.readlines())
                file_num += 1
                line_num += current_line_num
                ext = exp_map[file_path.split('.')[-1]]
                if ext in lang_file.keys():
                    lang_file[ext] += 1
                    lang_line[ext] += current_line_num
                else:
                    lang_file[ext] = 1
                    lang_line[ext] = current_line_num
    return file_num, line_num


def leading_space(str, num):
    while len(str) < num:
        str = ' ' + str
    return str


def tailing_space(str, num):
    while len(str) < num:
        str += ' '
    return str

names = []
file_nums = []
line_nums = []
for name in os.listdir('.'):
    if name[0] != '.' and os.path.isdir(name):
        names.append(name)
        file_nums.append(0)
        line_nums.append(0)
        file_nums[-1], line_nums[-1] = count_num(name)
for i in range(len(names)):
    for j in range(i + 1, len(names)):
        if line_nums[i] < line_nums[j]:
            names[i], names[j] = names[j], names[i]
            file_nums[i], file_nums[j] = file_nums[j], file_nums[i]
            line_nums[i], line_nums[j] = line_nums[j], line_nums[i]
    
lang_names = []
lang_file_nums = []
lang_line_nums = []
for ext in lang_file.keys():
    lang_names.append(ext)
    lang_file_nums.append(lang_file[ext])
    lang_line_nums.append(lang_line[ext])
for i in range(len(lang_names)):
    for j in range(i + 1, len(lang_names)):
        if lang_line_nums[i] < lang_line_nums[j]:
            lang_names[i], lang_names[j] = lang_names[j], lang_names[i]
            lang_file_nums[i], lang_file_nums[j] = lang_file_nums[j], lang_file_nums[i]
            lang_line_nums[i], lang_line_nums[j] = lang_line_nums[j], lang_line_nums[i]

print('|    Language     |  File Count  |  Line Count  |  Percentage  |')
print('|:---------------:|-------------:|-------------:|-------------:|')
for i in range(len(lang_names)):
    print('|    ' + tailing_space(lang_names[i], 13) +
          '|     ' + leading_space(str(lang_file_nums[i]), 5) + 
          '    |   ' + leading_space(str(lang_line_nums[i]), 7) +
          '    |   ' + leading_space(str('%.2f%%' % (100.0 * lang_line_nums[i] / sum(lang_line_nums))), 7) + 
          '    |')
print('|    ' + tailing_space('Total', 13) + 
      '|     ' + leading_space(str(sum(file_nums)), 5) + 
      '    |   ' + leading_space(str(sum(line_nums)), 7) +
      '    |   ' + leading_space(str('%.2f%%' % 100.0), 7) + 
      '    |')
print('')

print('|   Online Judge  |  File Count  |  Line Count  |  Percentage  |')
print('|:---------------:|-------------:|-------------:|-------------:|')
for i in range(len(names)):
    print('|    ' + tailing_space(names[i], 13) + 
          '|     ' + leading_space(str(file_nums[i]), 5) + 
          '    |   ' + leading_space(str(line_nums[i]), 7) +
          '    |   ' + leading_space(str('%.2f%%' % (100.0 * line_nums[i] / sum(line_nums))), 7) + 
          '    |')
print('|    ' + tailing_space('Total', 13) + 
      '|     ' + leading_space(str(sum(file_nums)), 5) + 
      '    |   ' + leading_space(str(sum(line_nums)), 7) +
      '    |   ' + leading_space(str('%.2f%%' % 100.0), 7) + 
      '    |')

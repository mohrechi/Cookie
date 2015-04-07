import os

lang_file = {}
lang_line = {}

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
                ext = file_path.split('.')[-1]
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

print('Languages')
print('=' * 52)
for ext in lang_file.keys():
    print(tailing_space(ext, 20) + 
          'File:' + leading_space(str(lang_file[ext]), 5) + 
          '\t\tLine:' + leading_space(str(lang_line[ext]), 7))
print('=' * 52)
print('')

print('Online Judges')
print('=' * 52)
for i in range(len(names)):
    print(tailing_space(names[i], 20) + 
          'File:' + leading_space(str(file_nums[i]), 5) + 
          '\t\tLine:' + leading_space(str(line_nums[i]), 7))
print('=' * 52)
print(tailing_space('Total', 20) + 
      'File:' + leading_space(str(sum(file_nums)), 5) + 
      '\t\tLine:' + leading_space(str(sum(line_nums)), 7))

import os
import codecs

def count_num(path):
    file_num = 0
    line_num = 0
    for dir_name in os.listdir(path):
        file_path = os.path.join(path, dir_name)
        if os.path.isdir(file_path):
            dir_file_num, dir_line_num = count_num(file_path)
            file_num = file_num + dir_file_num
            line_num = line_num + dir_line_num
        else:
            with open(file_path) as file_handle:
                file_num = file_num + 1
                line_num = line_num + len(file_handle.readlines())
    return file_num, line_num

names = []
file_nums = []
line_nums = []
for name in os.listdir('.'):
    if name[0] == '.' or name == 'summary.py':
        continue
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
names.append('Total')
file_nums.append(sum(file_nums))
line_nums.append(sum(line_nums))
for i in range(len(names)):
    space = ''.join([' ' for j in range(24 - len(names[i]))])
    print(names[i] + space + 'File: ' + str(file_nums[i]) + '\t\tLine: ' + str(line_nums[i]))
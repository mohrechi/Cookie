import os
import codecs
from urllib import parse

def write(out, level, path):
    for name in os.listdir(path):
        if name[0] != '.':
            if os.path.isdir(path + '/' + name):
                out.write('\n' + ('#'*level) + ' ' + name + '\n\n')
                if path == '.':
                    write(out, level + 1, name)
                else:
                    write(out, level + 1, path + '/' + name)
            elif level > 1:
                url = 'https://github.com/CyberZHG/Cookie/blob/master/' + parse.quote(path + '/' + name)
                out.write('* [' + name + '](' + url + ')\n')

with codecs.open('README.md', 'w', 'utf8') as out:
    write(out, 1, '.')

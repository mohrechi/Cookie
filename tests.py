#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys

if __name__ == '__main__':
    success = True
    os.system('python summary.py')
    for file_path in os.popen('git diff --name-only HEAD~10..HEAD').readlines():
        file_path = file_path.strip()
        if not os.path.exists(file_path):
            continue
        print('=' * 10 + ' ' + file_path)
        if file_path[-3:] == '.py':
            if os.system('pep8 --max-line-length=120 "%s"' % file_path) != 0:
                success = False
        elif file_path[-3:] == '.hs':
            if os.system('hlint "%s"' % file_path) != 0:
                success = False
        print('')
    if not success:
        sys.exit(1)

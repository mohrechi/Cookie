conversion = {'M' : 1000,
              'D' : 500,
              'C' : 100,
              'L' : 50,
              'X' : 10,
              'V' : 5,
              'I' : 1}

valid_combo = {'CM' : 900,
              'CD' : 400,
              'XC' : 90,
              'XL' : 40,
              'IX' : 9,
              'IV' : 4}

def convert_num(roman):
    output = 0
    temp = roman
    for key in valid_combo.iterkeys():
        vCount = temp.count(key)
        output += vCount * valid_combo[key]
        if vCount > 0:
            temp = temp.replace(key,'')
    for letter in temp:
        output += conversion[letter]
    return output

def minimal_form(num):
    output = ''
    temp = num
    if temp >= 1000:
        numM = temp / 1000
        output += numM * 'M'
        temp  = temp % 1000
    if temp >= 900:
        output += 'CM'
        temp = temp % 900
    if temp >= 500:
        output += 'D'
        temp = temp % 500
    if temp >= 400:
        output += 'CD'
        temp = temp % 400
    if temp >= 100:
        numC = temp / 100
        output += numC * 'C'
        temp = temp % 100
    if temp >= 90:
        output += 'XC'
        temp = temp % 90
    if temp >= 50:
        output += 'L'
        temp = temp % 50
    if temp >= 40:
        output += 'XL'
        temp = temp % 40
    if temp >= 10:
        numX = temp / 10
        output += numX * 'X'
        temp = temp % 10
    if temp == 9:
        output += 'IX'
        return output
    if temp >= 5:
        output += 'V'
        temp = temp % 5
    if temp == 4:
        output += 'IV'
        return output
    output += temp * 'I'
    return output        

n = input()

while n > 0:
    n -= 1
    s = raw_input()
    a = convert_num(s)
    b = minimal_form(a)
    print b

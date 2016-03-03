function isVowel(c) {
    return ['a', 'e', 'i', 'o', 'u'].indexOf(c) >= 0;
}

function vowelsAndConsonants(s) {
    var a = s.split('');
    a.forEach(function (c) {
        if (isVowel(c)) {
            console.log(c);
        }
    });
    a.forEach(function (c) {
        if (!isVowel(c)) {
            console.log(c);
        }
    });
}

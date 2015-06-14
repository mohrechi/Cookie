var a = readline();
var b = readline();
var c = readline();

function charCount(s) {
  var cnt = {};
  for (var i = 0; i < s.length; ++i) {
    if (s[i] in cnt) {
      cnt[s[i]] += 1;
    } else {
      cnt[s[i]] = 1;
    }
  }
  return cnt;
}

function divide(a, b) {
  var ret = 1e100;
  for (k in b) {
    if (k in a) {
      ret = Math.min(ret, Math.floor(a[k] / b[k]));
    } else {
      return 0;
    }
  }
  return ret;
}

function subtract(a, b, n) {
  var c = {};
  for (k in a) {
    c[k] = a[k];
  }
  for (k in b) {
    c[k] -= b[k] * n;
  }
  return c;
}
var ca = charCount(a);
var cb = charCount(b);
var cc = charCount(c);
var nb = divide(ca, cb);
var fb = 0, fc = 0;
for (var i = 0; i <= nb; ++i) {
  var j = divide(subtract(ca, cb, i), cc);
  if (i + j > fb + fc) {
    fb = i;
    fc = j;
  }
}
nb = fb;
nc = fc;
ans = '';
for (var i = 0; i < nb; ++i) {
  ans += b;
}
ca = subtract(ca, cb, nb);
nc = divide(ca, cc);
for (var i = 0; i < nc; ++i) {
  ans += c;
}
ca = subtract(ca, cc, nc);
for (k in ca) {
  for (var i = 0; i < ca[k]; ++i) {
    ans += k;
  }
}
print(ans);
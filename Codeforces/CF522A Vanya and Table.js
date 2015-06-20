var n = parseInt(readline());
var ans = 0;
while (n--) {
    var nums = readline().split(' ').map(Number);
    ans += (nums[2] - nums[0] + 1) * (nums[3] - nums[1] + 1);
}
print(ans);

func wiggleMaxLength(nums []int) int {
    n := len(nums)
    if n <= 1 {
        return n
    }
    sign := 0;
    cnt := 1;
    for i := 1; i < n; i++ {
        curr := getSign(nums[i], nums[i - 1]);
        if curr != 0 && curr != sign {
            cnt++;
            sign = curr;
        }
    }
    return cnt;
}

func getSign(a, b int) int {
    if (a > b) {
        return 1;
    }
    if (a < b) {
        return -1;
    }
    return 0;
}

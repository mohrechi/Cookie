def word_pattern(pattern, str)
    charMap = {}
    wordMap = {}
    strs = str.split
    return false if pattern.length != strs.length
    strs.length.times do |i|
        if wordMap.has_key? strs[i] then
            return false if wordMap[strs[i]] != pattern[i]
        else
            wordMap[strs[i]] = pattern[i]
        end
        if charMap.has_key? pattern[i] then
            return false if charMap[pattern[i]] != strs[i]
        else
            charMap[pattern[i]] = strs[i]
        end
    end
    true
end

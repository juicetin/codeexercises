def compress_str(string):
    compressed = ""
    cur_char = string[0]
    cur_count = 0

    # Iterate over all chars
    for char in string:
        # Increment count if char hasn't changed
        if char == cur_char:
            cur_count += 1

        # If char has changed, implement necessary checks
        else:
            compressed += str(cur_char)
            compressed += str(cur_count)
            cur_char = char
            cur_count = 1

    # Deal with final char/set of chars
    compressed += str(cur_char)
    compressed += str(cur_count)

    if len(compressed) >= len(string):
        return string
    else:
        return compressed

assert (compress_str("aabcccccaaa") == "a2b1c5a3"), "should equal a2b1c5a3"
assert (compress_str("aabccccca") == "a2b1c5a1"), "should equal a2b1c5a1" 
assert (compress_str("abcdef") == "abcdef"), "should equal abcdef" 

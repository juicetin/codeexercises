def insert_or_remove_check(short_str, long_str):
    check = False
    short_i = 0
    long_i = 0
    while short_i != len(short_str):
        if short_str[short_i] != long_str[long_i]:
            if not check:
                check = True
                long_i += 1
            else:
                return False
        short_i += 1
        long_i += 1
    return True

def edit_check(str1, str2):
    check = False
    str1_i = 0
    str2_i = 0
    while str1_i != len(str1):
        if str1[str1_i] != str2[str2_i]:
            if not check:
                check = True
            else:
                return False
        str1_i += 1
        str2_i += 1
    return True

def editable(str1, str2):
    str1len = len(str1)
    str2len = len(str2)
    if str1len > str2len:
        return insert_or_remove_check(str2, str1)
    elif str2len > str1len:
        return insert_or_remove_check(str1, str2)
    else:
        return edit_check(str1, str2)

def editable_improved(str1, str2):
    str1_i = 0
    str2_i = 0
    check = False

    # Check until end of both strings
    while str1_i != len(str1) and str2_i != len(str2):

        # Verification when char mismatch
        if str1[str1_i] != str2[str2_i]:

            # Ensure this is the first difference found
            if not check:
                check = True
                if len(str1) > len(str2):
                    str1_i += 1
                elif len(str2) > len(str1):
                    str2_i += 1
            else:
                return False

        # Increment accessor along both strings
        str1_i += 1
        str2_i += 1

    return True

assert (editable_improved("pale", "bake") == False), "pale, bake not 1 edit apart!"
assert (editable_improved("pale", "ple") == True), "pale, ple 1 edit apart!"
assert (editable_improved("pales", "pale") == True), "pales, pale 1 edit apart!"
assert (editable_improved("pale", "bale") == True), "pale, bale 1 edit apart!"

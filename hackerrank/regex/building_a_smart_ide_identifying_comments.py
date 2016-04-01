import sys

# Returns and '//' style single line comments for a line
def single_line_comment(string):
    last_string_quote_index = string.rfind("\"")
    last_single_comment_index = string.rfind("//")
    if last_single_comment_index > last_string_quote_index:
        return string[last_single_comment_index:].strip() + "\n"
    return ""

# Returns any '/**/' style single line comments for a line
def single_line_multi_comments(string):
    in_string = False
    comments = ""
    for char in string:

    pass

# Sets flags and gets comments as needed when entering multi line comment block
def entering_multi_block(string, in_multi_block):
    pass

# Main block
in_multi_block = False
comments_only = ""
for line in sys.stdin:
    comments_only += single_line_comment(line)

print(comments_only)

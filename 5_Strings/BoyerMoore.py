def generate_shift_table(pattern):
    skip_list = {} # creating a dictionary for i in range(0, Len(pattern)):
    for i in range(len(pattern)):
        skip_list[pattern[i]] = max(1, len(pattern) - i - 1)
    return skip_list

def boyer_moore_search(source, pattern):
    bad_char  = generate_shift_table(pattern) 
    i = len(pattern) - 1
    answer = []
    while i <= len(source) - 1: 
        j = 0 
        while j < len(pattern) and pattern [len(pattern) - j - 1] == source[i - j]:
            j += 1
        if j == len(pattern):
            answer.append(i - len(pattern) + 1) 
            i += 1; continue
        else:
            try:   
                shift = bad_char.get(source[i + j], len(pattern))
            except:
                return -1
            if shift == 0:
                shift = len(pattern) - 1
            skips = shift - j
            i += skips
    return answer 

print(boyer_moore_search("Hello World", "world"))
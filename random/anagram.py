def is_anagram(s1, s2):
	if len(s1) != len(s2):
		return False

	list_one = list(s1);
	list_two = list(s2)
	
	for char in s1:
		if char in list_two:
			list_two.remove(char)

	if len(list_two) != 0:
		return False

	return True

a = input()
b = input()
print (is_anagram(a,b))

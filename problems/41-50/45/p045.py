occurences = {}
pentagonal = 0
i = 1

while pentagonal <= 40755:
	for value in (i * (i + 1) // 2, i * (3 * i - 1) // 2, i * (2 * i - 1)):
		if value not in occurences:
			occurences[value] = 0

		occurences[value] += 1

		if occurences[value] == 3:
			pentagonal = value

	i += 1

print(pentagonal)

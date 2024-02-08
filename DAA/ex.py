import random

# Generate random numbers
random_numbers = [random.randint(1, 9999999999) for _ in range(10000)]

# Save random numbers to file
with open("random.txt", "w") as file:
    for num in random_numbers:
        file.write(str(num) + "\n")

# Sort numbers
sorted_numbers = sorted(random_numbers)

# Save sorted numbers to file
with open("sorted.txt", "w") as file:
    for num in sorted_numbers:
        file.write(str(num) + "\n")

# Introduce clumps
clumps_numbers = sorted_numbers.copy()
for i in range(10):
    clump_start = random.randint(0, len(clumps_numbers) - 100)
    clump_end = clump_start + random.randint(50, 100)
    clump = clumps_numbers[clump_start:clump_end]
    random.shuffle(clump)
    clumps_numbers[clump_start:clump_end] = clump

# Save clumped numbers to file
with open("clumps.txt", "w") as file:
    for num in clumps_numbers:
        file.write(str(num) + "\n")

# Sort numbers in reverse order
reverse_numbers = sorted_numbers[::-1]

# Save reverse sorted numbers to file
with open("reverse.txt", "w") as file:
    for num in reverse_numbers:
        file.write(str(num) + "\n")

print("Files generated successfully.")
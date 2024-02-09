a=input("Enter a String:")
b="aeiou"
count =0
for i in a.lower():
    if i in b:
        count +=1
print("No .of Vowels is ",count)
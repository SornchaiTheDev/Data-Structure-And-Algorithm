x = int(input("Enter first positive integer: "))
while x < 0:
  print("Your number isn't positive integer!")
  x = int(input("Enter first positive integer: "))

y = int(input("Enter second positive integer: "))
while y < 0:
  print("Your number isn't positive integer!")
  y = int(input("Enter second positive integer: "))
mean = (x+y)/2
print(f"{mean:.2f}")

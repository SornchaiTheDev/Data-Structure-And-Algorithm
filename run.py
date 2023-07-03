num1 = int(input("Enter First Number : "))
while num1 < 0 :
  num1 = int(input("Enter First Number : "))

num2 = int(input("Enter Second Number : "))
while num2 < 0 :
  num2 = int(input("Enter Second Number : "))

avg = (num1 + num2) / 2

print(f"The Average is {avg:.2f}")
import math

class Request():
 def __init__(self, amount):
  print("Requested: ${}".format(amount))
  self.amount = amount

 def get(self, bill):
  count = math.floor(self.amount/bill)
  self.amount -= count * bill
  print("Dispense {} ${} bills".format(count,bill))
  return self

def main():
	req = Request(378)
	req.get(100).get(50).get(20).get(10).get(5).get(1)


if __name__ == '__main__':
	main()

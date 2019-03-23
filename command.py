class Receiver_3:
	def __init__(self):
		pass

	def command(self):
		print("Command is triggered!")

class Receiver:
	def __init__(self, rec_2):
		self.rec_2 = rec_2

	def command(self):
		self.rec_2.command()

class Invoker:
	def __init__(self, rec):
		self.rec = rec

	def concretecommand(self):
		self.rec.command()

def main():
	rec_3 = Receiver_3()
	rec_2 = Receiver(rec_3)
	rec = Receiver(rec_2)
	inv = Invoker(rec)
	inv.concretecommand()

if __name__ == '__main__':
	main()

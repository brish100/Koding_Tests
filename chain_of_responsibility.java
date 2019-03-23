class chain_of_responsibility {
    static class Request {
        private int amount = 0;

        Request(int amount) {
            System.out.println("Requested: $" + amount);
            this.amount = amount;
        }

        public Request get(int bill) {
            int count = (int) Math.floor(this.amount/bill);
            this.amount -= count * bill;
            System.out.println(String.format("Dispense %d $%d bill",count,bill));
            return this;
        }
    }

    public static void main(String[] args) {
        Request request = new Request(378);
        request.get(100).get(50).get(20).get(10).get(5).get(1);
    }
}


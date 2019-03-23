let Request = function (amount) {
    this.amount = amount;
    console.log("Requested: $" + amount)
};

Request.prototype = {
    get: function(bill) {
        let count = Math.floor(this.amount / bill);
        this.amount -= count * bill;
        console.log("Dispense " + count + " $" + bill + " bills");
        return this;
    }
};

let main = () => {
	let request = new Request(378);
	request.get(100).get(50).get(20).get(10).get(5).get(1);
}

main()

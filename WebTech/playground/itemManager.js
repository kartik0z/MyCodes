export class ItemManager {
    constructor() {
        this.items = this.loadItems();
    }

    loadItems() {
        const storedItems = localStorage.getItem('items');
        return storedItems ? JSON.parse(storedItems) : [];
    }

    addItem(name, price, quantity) {
        this.items.push({ name, price: parseFloat(price), quantity: parseInt(quantity) });
        this.saveItems();
    }

    updateItem(index, newQuantity) {
        if (index >= 0 && index < this.items.length) {
            this.items[index].quantity = parseInt(newQuantity);
            this.saveItems();
        }
    }

    removeItem(index) {
        if (index >= 0 && index < this.items.length) {
            this.items.splice(index, 1);
            this.saveItems();
        }
    }

    getItems() {
        return this.items;
    }

    calculateTotal() {
        return this.items.reduce((total, item) => total + item.price * item.quantity, 0);
    }

    saveItems() {
        localStorage.setItem('items', JSON.stringify(this.items));
    }
}
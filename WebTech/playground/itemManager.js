export class ItemManager {
    constructor() {
        this.items = JSON.parse(localStorage.getItem('items')) || [];
    }

    addItem(name, price, quantity) {
        this.items.push({ name, price, quantity });
        this.saveItems();
    }

    updateItem(index, newQuantity) {
        if (index >= 0 && index < this.items.length) {
            this.items[index].quantity = newQuantity;
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
export class ItemManager {
    constructor() {
        this.items = this.loadItems();
    }

    loadItems() {
        const storedItems = localStorage.getItem('items');
        return storedItems ? JSON.parse(storedItems) : [];
    }

    addItem(name, price, quantity) {
        this.items.push({ name, price, quantity });
        this.saveItems();
        alert(`Item '${name}' added successfully.`);
    }

    updateItem(index, newQuantity) {
        if (index >= 0 && index < this.items.length) {
            this.items[index].quantity = newQuantity;
            this.saveItems();
            alert('Item updated successfully.');
        }
    }

    removeItem(index) {
        if (index >= 0 && index < this.items.length) {
            this.items.splice(index, 1);
            this.saveItems();
            alert('Item removed successfully.');
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
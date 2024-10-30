import { ItemManager } from './itemManager.js';
import { InvoiceGenerator } from './invoiceGenerator.js';

const itemManager = new ItemManager();
const invoiceGenerator = new InvoiceGenerator();

document.addEventListener('DOMContentLoaded', () => {
    const addItemForm = document.getElementById('add-item-form');
    const generateInvoiceButton = document.getElementById('generate-invoice');

    addItemForm.addEventListener('submit', handleAddItem);
    generateInvoiceButton.addEventListener('click', handleGenerateInvoice);

    updateUI();
});

function handleAddItem(event) {
    event.preventDefault();
    const name = document.getElementById('item-name').value;
    const price = parseFloat(document.getElementById('item-price').value);
    const quantity = parseInt(document.getElementById('item-quantity').value);

    itemManager.addItem(name, price, quantity);
    updateUI();
    event.target.reset();
}

function handleUpdateItem(index) {
    const newQuantity = parseInt(document.getElementById(`item-quantity-${index}`).value);
    itemManager.updateItem(index, newQuantity);
    updateUI();
}

function handleRemoveItem(index) {
    itemManager.removeItem(index);
    updateUI();
}

function handleGenerateInvoice() {
    const items = itemManager.getItems();
    const total = itemManager.calculateTotal();
    invoiceGenerator.generatePDF(items, total);
}

function updateUI() {
    renderItems();
    updateTotal();
}

function renderItems() {
    const itemTable = document.getElementById('item-table');
    const tbody = itemTable.getElementsByTagName('tbody')[0];
    tbody.innerHTML = '';

    itemManager.getItems().forEach((item, index) => {
        const row = tbody.insertRow();
        row.innerHTML = `
            <td>${item.name}</td>
            <td><input type="number" id="item-quantity-${index}" value="${item.quantity}" min="1"></td>
            <td>$${item.price.toFixed(2)}</td>
            <td>$${(item.price * item.quantity).toFixed(2)}</td>
            <td>
                <button onclick="window.handleUpdateItem(${index})">Update</button>
                <button onclick="window.handleRemoveItem(${index})">Remove</button>
            </td>
        `;
    });
}

function updateTotal() {
    const totalPrice = itemManager.calculateTotal();
    document.getElementById('total-price').textContent = `$${totalPrice.toFixed(2)}`;
}

// Make functions globally accessible
window.handleUpdateItem = handleUpdateItem;
window.handleRemoveItem = handleRemoveItem;
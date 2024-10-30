import { ItemManager } from './itemManager.js';
import { InvoiceGenerator } from './invoiceGenerator.js';

const itemManager = new ItemManager();
const invoiceGenerator = new InvoiceGenerator();

document.addEventListener('DOMContentLoaded', () => {
    const addItemForm = document.getElementById('add-item-form');
    const generateInvoiceButton = document.getElementById('generate-invoice');
    const customerInfoModal = document.getElementById('customer-info-modal');
    const customerInfoForm = document.getElementById('customer-info-form');

    addItemForm.addEventListener('submit', handleAddItem);
    generateInvoiceButton.addEventListener('click', showCustomerInfoModal);
    customerInfoForm.addEventListener('submit', handleGenerateInvoice);

    updateUI();
});

function handleAddItem(event) {
    event.preventDefault();
    const itemName = document.getElementById('item-name').value;
    const itemPrice = document.getElementById('item-price').value;
    const itemQuantity = document.getElementById('item-quantity').value;
    itemManager.addItem(itemName, itemPrice, itemQuantity);
    updateUI();
    event.target.reset();
}

function updateUI() {
    const items = itemManager.getItems();
    const total = itemManager.calculateTotal();
    const itemsTable = document.getElementById('items-table');
    itemsTable.innerHTML = '';
    items.forEach((item, index) => {
        const row = itemsTable.insertRow();
        row.innerHTML = `
            <td>${item.name}</td>
            <td>$${item.price.toFixed(2)}</td>
            <td>${item.quantity}</td>
            <td>$${(item.price * item.quantity).toFixed(2)}</td>
            <td>
                <button class="update-button" data-index="${index}">Update</button>
                <button class="remove-button" data-index="${index}">Remove</button>
            </td>
        `;
    });
    document.getElementById('total-price').textContent = `$${total.toFixed(2)}`;
    attachEventListeners();
}

function attachEventListeners() {
    document.querySelectorAll('.update-button').forEach((button) => {
        button.addEventListener('click', handleUpdateItem);
    });
    document.querySelectorAll('.remove-button').forEach((button) => {
        button.addEventListener('click', handleRemoveItem);
    });
}

function handleUpdateItem(event) {
    const index = parseInt(event.target.dataset.index);
    const newQuantity = prompt('Enter new quantity:', itemManager.getItems()[index].quantity);
    if (newQuantity !== null) {
        itemManager.updateItem(index, newQuantity);
        updateUI();
    }
}

function handleRemoveItem(event) {
    const index = parseInt(event.target.dataset.index);
    itemManager.removeItem(index);
    updateUI();
}

function showCustomerInfoModal() {
    document.getElementById('customer-info-modal').style.display = 'block';
}

function handleGenerateInvoice(event) {
    event.preventDefault();
    const customerInfo = {
        name: document.getElementById('customer-name').value,
        phone: document.getElementById('customer-phone').value,
        address: document.getElementById('customer-address').value,
        city: document.getElementById('customer-city').value,
        state: document.getElementById('customer-state').value,
        zip: document.getElementById('customer-zip').value,
    };
    const items = itemManager.getItems();
    const total = itemManager.calculateTotal();
    invoiceGenerator.generatePDF(items, total, customerInfo);
    document.getElementById('customer-info-modal').style.display = 'none';
    document.getElementById('customer-info-form').reset();
}
let items = [];

function addItem() {
    const itemName = document.getElementById("item-name").value;
    const itemPrice = parseFloat(document.getElementById("item-price").value);
    const itemQuantity = parseInt(document.getElementById("item-quantity").value);

    if (itemName && !isNaN(itemPrice) && !isNaN(itemQuantity)) {
        const item = {
            name: itemName,
            price : itemPrice,
            quantity: itemQuantity
        };

        items.push(item);

        renderItems();

        document.getElementById("item-name").value = "";
        document.getElementById("item-price").value = "";
        document.getElementById("item-quantity").value = "";
    }
}

function removeItem(index) {
    items.splice(index, 1);
    renderItems();
}

function updateItem(index) {
    const newQuantity = parseInt(document.getElementById(`item-quantity-${index}`).value);
    if (!isNaN(newQuantity)) {
        items[index].quantity = newQuantity;
        renderItems();
    }
}

function renderItems() {
    const itemTable = document.getElementById("item-table");
    const tbody = itemTable.getElementsByTagName("tbody")[0];
    tbody.innerHTML = "";

    items.forEach((item, index) => {
        const row = tbody.insertRow();
        row.innerHTML = `
            <td>${item.name}</td>
            <td><input type="number" id="item-quantity-${index}" value="${item.quantity}" min="1"></td>
            <td>$${item.price.toFixed(2)}</td>
            <td>$${(item.price * item.quantity).toFixed(2)}</td>
            <td>
                <button onclick="updateItem(${index})">Update</button>
                <button onclick="removeItem(${index})">Remove</button>
            </td>
        `;
    });
}

function calculateTotal() {
    const totalPrice = items.reduce((acc, item) => acc + item.price * item.quantity, 0);
    document.getElementById("total-price").innerText = `Total: $${totalPrice.toFixed(2)}`;
}

function generateInvoice() {
    const invoiceTable = document.getElementById("invoice-table");
    const tbody = invoiceTable.getElementsByTagName("tbody")[0];
    tbody.innerHTML = "";

    let total = 0;

    items.forEach((item) => {
        const row = tbody.insertRow();
        row.innerHTML = `
            <td>${item.name}</td>
            <td>${item.quantity}</td>
            <td>$${item.price.toFixed(2)}</td>
            <td>$${(item.price * item.quantity).toFixed(2)}</td>
        `;
        total += item.price * item.quantity;
    });

    const totalRow = tbody.insertRow();
    totalRow.innerHTML = `
        <td>Total:</td>
        <td></td>
        <td></td>
        <td>$${total.toFixed(2)}</td>
    `;

    document.getElementById("invoice-total").innerText = `Total: $${total.toFixed(2)}`;

    calculateTotal();

    window.print();
}
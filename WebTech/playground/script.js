const GST_RATE = 0.03;
let silverRatePerGram = 80;
let goldRatePerGram = 5500;
let totalCost = 0;

function calculateRate(type) {
    let weight, purity, quantity, resultField, ratePerGram;
    
    if (type === 'silver') {
        weight = parseFloat(document.getElementById("silver-weight").value);
        purity = parseFloat(document.getElementById("silver-purity").value);
        quantity = parseInt(document.getElementById("silver-quantity").value);
        resultField = document.getElementById("silver-result");
        ratePerGram = silverRatePerGram;
    } else {
        weight = parseFloat(document.getElementById("gold-weight").value);
        purity = parseFloat(document.getElementById("gold-purity").value);
        quantity = parseInt(document.getElementById("gold-quantity").value);
        resultField = document.getElementById("gold-result");
        ratePerGram = goldRatePerGram;
    }

    if (isNaN(weight) || weight <= 0 || isNaN(purity) || purity <= 0 || purity > 100 || isNaN(quantity) || quantity <= 0) {
        resultField.innerText = "Please enter valid values.";
        return;
    }

    const basePrice = (ratePerGram * purity * weight) / 100;
    const gstAmount = basePrice * GST_RATE;
    const finalPricePerUnit = basePrice + gstAmount;
    totalCost = finalPricePerUnit * quantity;

    resultField.innerText = `${type.charAt(0).toUpperCase() + type.slice(1)} Rate (with GST): ₹${finalPricePerUnit.toFixed(2)} per unit. Total Cost: ₹${totalCost.toFixed(2)}`;
}

function generateBill() {
    const customerName = document.getElementById("customer-name").value;
    const customerContact = document.getElementById("customer-contact").value;

    if (!customerName || !customerContact) {
        alert("Please enter customer details.");
        return;
    }

    document.getElementById("bill-customer-name").innerText = customerName;
    document.getElementById("bill-customer-contact").innerText = customerContact;
    document.getElementById("bill-details").innerText = `Total Cost for Gold/Silver as specified: ₹${totalCost.toFixed(2)}`;
    document.getElementById("bill-total-cost").innerText = totalCost.toFixed(2);
    document.getElementById("bill").style.display = "block";
}

function printBill() {
    const billContent = document.getElementById("bill").innerHTML;
    const printWindow = window.open('', '', 'height=600,width=800');
    printWindow.document.write('<html><head><title>Invoice</title></head><body>');
    printWindow.document.write(billContent);
    printWindow.document.write('</body></html>');
    printWindow.document.close();
    printWindow.print();
}
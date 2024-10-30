const GST_RATE = 0.03;
let silverRatePerGram = 80;
let goldRatePerGram = 5500;

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

  // Store the total cost in a data attribute for use in the bill generation
  document.getElementById("total-cost").setAttribute(`data-${type}-cost`, finalPricePerUnit * quantity);

  resultField.innerText = `${type.charAt(0).toUpperCase() + type.slice(1)} Rate (with GST): ₹${finalPricePerUnit.toFixed(2)} per unit. Total Cost: ₹${(finalPricePerUnit * quantity).toFixed(2)}`;
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

  // Retrieve total costs from data attributes
  const silverTotalCost = parseFloat(document.getElementById("total-cost").getAttribute("data-silver-cost") || 0);
  const goldTotalCost = parseFloat(document.getElementById("total-cost").getAttribute("data-gold-cost") || 0);

  // Update bill details with correct quantities
  document.getElementById("bill-details").innerHTML = `
    <div class="bill-details">
      <p>Item:</p>
      <p>Gold/Silver as specified</p>
    </div>
    <div class="bill-details">
      <p>Silver Rate:</p>
      <p>₹${silverTotalCost.toFixed(2)} for ${document.getElementById("silver-quantity").value} units</p>
    </div>
    <div class="bill-details">
      <p>Gold Rate:</p>
      <p>₹${goldTotalCost.toFixed(2)} for ${document.getElementById("gold-quantity").value} units</p>
    </div>
  `;

  const totalCost = silverTotalCost + goldTotalCost;
  document.getElementById("bill-total-cost").innerText = totalCost.toFixed(2);
  document.getElementById("bill").style.display = "block";
}

function printBill() {
  window.print();
}
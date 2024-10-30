export class InvoiceGenerator {
    generatePDF(items, total, customerInfo) {
        const { jsPDF } = window.jspdf;
        const doc = new jsPDF();

        // Document setup
        doc.setFontSize(20);
        doc.text('Invoice', 105, 20, null, null, 'center');
        doc.setFontSize(10);
        doc.text(`Date: ${new Date().toLocaleDateString()}`, 20, 30);

        // Add customer details
        doc.setFontSize(12);
        doc.text('Bill To:', 20, 40);
        doc.setFontSize(10);
        doc.text(customerInfo.name, 20, 45);
        doc.text(customerInfo.address, 20, 50);
        doc.text(`${customerInfo.city}, ${customerInfo.state} ${customerInfo.zip}`, 20, 55);
        doc.text(`Phone: ${customerInfo.phone}`, 20, 60);

        // Add items table
        const headers = [['Item Name', 'Price', 'Quantity', 'Total']];
        const data = items.map(item => [
            item.name,
            `$${item.price.toFixed(2)}`,
            item.quantity.toString(),
            `$${(item.price * item.quantity).toFixed(2)}`
        ]);

        doc.autoTable({
            startY: 70,
            head: headers,
            body: data,
            theme: 'grid',
            styles: { fontSize: 8 },
            headStyles: { fillColor: [41, 128, 185], textColor: 255 },
            margin: { top: 70 },
        });

        // Add total
        const finalY = doc.lastAutoTable.finalY || 70;
        doc.setFontSize(12);
        doc.text(`Total: $${total.toFixed(2)}`, 150, finalY + 10);

        // Save the PDF
        doc.save('invoice.pdf');
    }
}
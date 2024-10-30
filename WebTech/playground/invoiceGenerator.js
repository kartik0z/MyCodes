export class InvoiceGenerator {
    generatePDF(items, total) {
        const { jsPDF } = window.jspdf;
        const doc = new jsPDF();

        doc.setFontSize(20);
        doc.text('Invoice', 105, 20, null, null, 'center');

        doc.setFontSize(12);
        doc.setTextColor(100);

        let yPos = 40;
        doc.text('Item', 20, yPos);
        doc.text('Qty', 100, yPos);
        doc.text('Price', 130, yPos);
        doc.text('Total', 170, yPos);

        yPos += 10;
        items.forEach(item => {
            doc.text(item.name, 20, yPos);
            doc.text(item.quantity.toString(), 100, yPos);
            doc.text(`$${item.price.toFixed(2)}`, 130, yPos);
            doc.text(`$${(item.price * item.quantity).toFixed(2)}`, 170, yPos);
            yPos += 10;
        });

        yPos += 10;
        doc.setFontStyle('bold');
        doc.text(`Total: $${total.toFixed(2)}`, 170, yPos);

        doc.save('invoice.pdf');
    }
}
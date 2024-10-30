export class InvoiceGenerator {
    generatePDF(items, total) {
        const { jsPDF } = window.jspdf;
        const doc = new jsPDF();

        // Set document properties
        doc.setProperties({
            title: 'Invoice',
            subject: 'Invoice for purchase',
            author: 'Your Company Name',
            keywords: 'invoice, bill, purchase',
            creator: 'Invoice Generator'
        });

        // Add company logo (replace with your logo path)
        // doc.addImage('path/to/your/logo.png', 'PNG', 10, 10, 50, 20);

        // Set fonts
        doc.setFont("helvetica", "bold");

        // Add title
        doc.setFontSize(24);
        doc.setTextColor(41, 128, 185); // A nice blue color
        doc.text('INVOICE', 105, 20, null, null, 'center');

        // Add invoice details
        doc.setFontSize(10);
        doc.setTextColor(100);
        doc.text(`Invoice Number: INV-${Date.now()}`, 10, 40);
        doc.text(`Date: ${new Date().toLocaleDateString()}`, 10, 45);

        // Add company details
        doc.setFont("helvetica", "normal");
        doc.text('Your Company Name', 10, 60);
        doc.text('123 Business Street', 10, 65);
        doc.text('City, State, ZIP', 10, 70);
        doc.text('Phone: (123) 456-7890', 10, 75);

        // Add customer details (you might want to make this dynamic)
        doc.text('Bill To:', 110, 60);
        doc.text('Customer Name', 110, 65);
        doc.text('Customer Address', 110, 70);
        doc.text('City, State, ZIP', 110, 75);

        // Add table headers
        let yPos = 90;
        doc.setFillColor(52, 152, 219); // A light blue for header background
        doc.rect(10, yPos, 190, 10, 'F');
        doc.setTextColor(255);
        doc.setFont("helvetica", "bold");
        doc.text('Item', 15, yPos + 7);
        doc.text('Qty', 100, yPos + 7);
        doc.text('Price', 130, yPos + 7);
        doc.text('Total', 170, yPos + 7);

        // Add table rows
        doc.setFont("helvetica", "normal");
        doc.setTextColor(0);
        yPos += 15;
        items.forEach((item, index) => {
            const rowColor = index % 2 === 0 ? 245 : 255;
            doc.setFillColor(rowColor);
            doc.rect(10, yPos - 5, 190, 10, 'F');

            doc.text(item.name, 15, yPos);
            doc.text(item.quantity.toString(), 100, yPos);
            doc.text(`$${item.price.toFixed(2)}`, 130, yPos);
            doc.text(`$${(item.price * item.quantity).toFixed(2)}`, 170, yPos);
            yPos += 10;
        });

        // Add total
        yPos += 10;
        doc.setFont("helvetica", "bold");
        doc.setFillColor(52, 152, 219);
        doc.rect(130, yPos - 5, 70, 10, 'F');
        doc.setTextColor(255);
        doc.text(`Total: $${total.toFixed(2)}`, 170, yPos);

        // Add footer
        doc.setFont("helvetica", "italic");
        doc.setFontSize(10);
        doc.setTextColor(100);
        doc.text('Thank you for your business!', 105, 280, null, null, 'center');

        // Save the PDF
        doc.save('invoice.pdf');
    }
}
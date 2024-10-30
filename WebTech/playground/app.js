const form = document.querySelector('form');
const formData = {};

form.addEventListener('submit', (e) => {
	e.preventDefault();
	const data = new FormData(form);
	for (const [key, value] of data) {
		formData[key] = value;
	}
	console.log(formData);
});
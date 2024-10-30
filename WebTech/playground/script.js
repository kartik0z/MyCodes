const goldAPIKey = 'goldapi-znm19m2vj6dur-io'; // Replace with your GoldAPI key
const rapidAPIKey = '02a657ab60msh61125a4984d582ap1f599djsn5e2a0ab5e4f0'; // Replace with your RapidAPI key
const usdToInr = 83.0; // Conversion rate for GoldAPI (USD to INR)

// Fetch live rates from RapidAPI for gold and silver in INR
function fetchRapidAPIRates() {
    return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.withCredentials = true;

        xhr.addEventListener('readystatechange', function () {
            if (this.readyState === XMLHttpRequest.DONE) {
                const response = JSON.parse(this.responseText);
                if (response.gold_price && response.silver_price) {
                    const rates = {
                        gold: response.gold_price,
                        silver: response.silver_price
                    };
                    resolve(rates);
                } else {
                    reject("RapidAPI response is missing price data.");
                }
            }
        });

        xhr.open('GET', 'https://gold-silver-rates-india.p.rapidapi.com/api/Fetch-Gold-Silver/?city=Mumbai&state=Maharashtra');
        xhr.setRequestHeader('x-rapidapi-key', rapidAPIKey);
        xhr.setRequestHeader('x-rapidapi-host', 'gold-silver-rates-india.p.rapidapi.com');
        xhr.send(null);
    });
}

// Fetch live rates from GoldAPI for gold and silver in USD, then convert to INR
function fetchGoldAPIRates() {
    return Promise.all([
        fetch(`https://www.goldapi.io/api/XAU/USD`, {
            headers: { 'x-access-token': goldAPIKey, 'Content-Type': 'application/json' }
        }).then(response => response.json()),
        fetch(`https://www.goldapi.io/api/XAG/USD`, {
            headers: { 'x-access-token': goldAPIKey, 'Content-Type': 'application/json' }
        }).then(response => response.json())
    ]).then(([goldData, silverData]) => {
        const rates = {
            gold: (goldData.price_per_gram * usdToInr).toFixed(2),
            silver: (silverData.price_per_gram * usdToInr).toFixed(2)
        };
        return rates;
    }).catch(error => {
        console.error("Error fetching GoldAPI rates:", error);
        return null;
    });
}

// Main function to display rates
async function displayRates() {
    try {
        const rates = await fetchRapidAPIRates();
        document.getElementById("gold-rate").innerText = rates.gold;
        document.getElementById("silver-rate").innerText = rates.silver;
    } catch (error) {
        console.warn("Falling back to GoldAPI due to RapidAPI failure:", error);
        const rates = await fetchGoldAPIRates();
        if (rates) {
            document.getElementById("gold-rate").innerText = rates.gold;
            document.getElementById("silver-rate").innerText = rates.silver;
        } else {
            document.getElementById("gold-rate").innerText = "Unavailable";
            document.getElementById("silver-rate").innerText = "Unavailable";
        }
    }
}

// Call displayRates when the page loads
window.onload = displayRates;
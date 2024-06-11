function calculateStats() {
    let num1 = document.getElementById('num1').value;
    let num2 = document.getElementById('num2').value;
    let num3 = document.getElementById('num3').value;

    let numbers = [num1, num2, num3].map(Number);
    numbers.sort((a, b) => a - b);

    let max = numbers[2];
    let min = numbers[0];
    let mean = (numbers[0] + numbers[1] + numbers[2]) / 3;
    let median = numbers[1];
    let range = max - min;

    let resultsDiv = document.getElementById('results');
    resultsDiv.innerHTML = `
        <p>Max: ${max}</p>
        <p>Min: ${min}</p>
        <p>Mean: ${mean}</p>
        <p>Median: ${median}</p>
        <p>Range: ${range}</p>
    `;
}
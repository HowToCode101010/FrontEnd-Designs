const colors = ['#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7', '#DDA0DD'];
const btn = document.getElementById('btn');
const colorDisplay = document.getElementById('color');

btn.addEventListener('click', () => {
    const randomColor = colors[Math.floor(Math.random() * colors.length)];
    document.body.style.backgroundColor = randomColor;
    colorDisplay.textContent = randomColor;
    
    // Change button color to contrast with background
    btn.style.backgroundColor = randomColor;
    btn.style.color = 'white';
});

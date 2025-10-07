const words = ["apple", "banana", "orange", "grape", "mango"];
let chosenWord = "";
let hiddenWord = [];
let wrongGuesses = [];

function startGame() {
  chosenWord = words[Math.floor(Math.random() * words.length)];
  hiddenWord = Array(chosenWord.length).fill("_");
  wrongGuesses = [];
  document.getElementById("word").textContent = hiddenWord.join(" ");
  document.getElementById("wrong").textContent = "";
  document.getElementById("message").textContent = "Type a letter below";
}

function makeGuess() {
  const input = document.getElementById("guess");
  const letter = input.value.toLowerCase();
  input.value = "";

  if (!letter.match(/[a-z]/) || letter.length !== 1) {
    document.getElementById("message").textContent = "Please enter a valid letter!";
    return;
  }

  if (hiddenWord.includes(letter) || wrongGuesses.includes(letter)) {
    document.getElementById("message").textContent = "You already guessed that!";
    return;
  }

  if (chosenWord.includes(letter)) {
    for (let i = 0; i < chosenWord.length; i++) {
      if (chosenWord[i] === letter) hiddenWord[i] = letter;
    }
    document.getElementById("word").textContent = hiddenWord.join(" ");
    document.getElementById("message").textContent = "Good guess!";
  } else {
    wrongGuesses.push(letter);
    document.getElementById("wrong").textContent = wrongGuesses.join(", ");
    document.getElementById("message").textContent = "Wrong guess!";
  }

  if (!hiddenWord.includes("_")) {
    document.getElementById("message").textContent = "🎉 You guessed the word!";
  }
}

function resetGame() {
  startGame();
}

// Start first game
startGame();

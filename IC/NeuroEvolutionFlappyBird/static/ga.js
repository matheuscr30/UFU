function resetGame() {
  counter = 0;
  if (bestBird) bestBird.score = 0;
  pipes = [];
}

function nextGeneration() {
  resetGame();
  normalizeFitness(allBirds);
  activeBirds = generate(allBirds);
  allBirds = activeBirds.slice(); // Copy array
}

function generate(oldBirds) {
  let newBirds = [];
  for (let i = 0; i < oldBirds.length; i++) {
    let bird = poolSelection(oldBirds);
    newBirds[i] = bird;
  }
  return newBirds;
}

function normalizeFitness(birds) {
  // Add up all the scores
  let sum = 0;
  for (let i = 0; i < birds.length; i++) {
    sum += birds[i].score;
  }
  // Divide by the sum
  for (let i = 0; i < birds.length; i++) {
    birds[i].fitness = birds[i].score / sum;
  }
}

// Roullete Selection
function poolSelection(birds) {
  let index = 0;
  let r = random(1);

  while (r > 0) {
    r -= birds[index].fitness;
    index += 1;
  }
  index -= 1;

  // Copy mutates
  return birds[index].copy();
}

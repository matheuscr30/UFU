function mutate(x) {
  if (random(1) < 0.1) {
    // randomGaussian because can be positive or negative
    let offset = randomGaussian() * 0.5;
    let newx = x + offset;
    return newx;
  } else {
    return x;
  }
}

class Bird {
  constructor(brain) {
    // position and size of bird
    this.x = 64;
    this.y = height / 2;
    this.r = 6;

    // Gravity, lift and velocity
    this.gravity = 0.8;
    this.lift = -7;
    this.velocity = 0;

    // Is this a copy of another Bird or a new one?
    // The Neural Network is the bird's "brain"
    if (brain instanceof NeuralNetwork) {
      this.brain = brain.copy();
      this.brain.mutate(mutate);
    } else {
      this.brain = new NeuralNetwork(5, 8, 2);
    }

    this.score = 0;
    this.fitness = 0;
  }

  copy() {
    return new Bird(this.brain);
  }

  show() {
    fill(255, 100);
    stroke(255);
    ellipse(this.x, this.y, this.r * 2, this.r * 2);
  }

  think(pipes) {
    // closest pipe
    let closest = null;
    let record = Infinity;
    for (let i = 0; i < pipes.length; i++) {
      let diff = pipes[i].x - this.x;
      if (diff > 0 && diff < record) {
        record = diff;
        closest = pipes[i];
      }
    }

    if (closest != null) {
      let inputs = [];
      // x position of closest pipe
      inputs[0] = closest.x / width;
      // top of closest pipe opening
      inputs[1] = closest.top / height;
      // bottom of closest pipe opening
      inputs[2] = closest.bottom / height;
      // bird's y position
      inputs[3] = this.y / height;
      // bird's y velocity
      inputs[4] = this.velocity / 10;

      let action = this.brain.predict(inputs);
      if (action[1] > action[0]) {
        this.up();
      }
    }
  }

  up() {
    this.velocity += this.lift;
  }

  bottomTop() {
    return (this.y > height || this.y < 0);
  }

  update() {
    this.velocity += this.gravity;
    this.y += this.velocity;

    // Every frame it is alive increases the score
    this.score++;
  }
}

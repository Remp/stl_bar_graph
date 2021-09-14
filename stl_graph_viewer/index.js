const plotlib = require('nodeplotlib');
const fs = require('fs');

function readStdin() {
  return fs.readFileSync(0).toString();
}

function run() {
  try {
    const stdinJson = JSON.parse(readStdin());
    const data = [
      {
        x: stdinJson.data.map(point => point.x),
        y: stdinJson.data.map(point => point.y),
        type: 'bar'
      }
    ];

    plotlib.plot(data);
  } catch (error) {
    console.error(error)
  }
}

run();

// require deployd
var deployd = require('deployd');

// configure database etc. 
var server = deployd({
  port: process.env.PORT || 5000,
  env: 'production',
  db: {
    connectionString: "mongodb://cpsc362:cpsc362@ds229648.mlab.com:29648/heroku_nzbv6h9p"
  }
});

server.sockets.server.set('transports', ['xhr-polling']);

// start the server
server.listen();

// debug
server.on('listening', function() {
  console.log("Server is listening on port: " + process.env.PORT);
});

// Deployd requires this
server.on('error', function(err) {
  console.error(err);
  process.nextTick(function() { // Give the server a chance to return an error
    process.exit();
  });
});
